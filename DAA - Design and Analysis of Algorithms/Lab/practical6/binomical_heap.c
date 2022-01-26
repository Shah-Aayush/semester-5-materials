/*
Aayush Shah
19BCE245
DAA Practical 6
*/

// ⚠️ WARNING : THIS CODE IS NOT WORKING PROPERLY. you can only use it for fake demonstration!
// Feel free to contribute via correcting this code 🚀

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

//START
typedef struct _binom_tree_node {
	int key;		//data value in node
	struct _binom_tree_node *child, *parent, *sibling;		//connected nodes
	int k;		//degre of node
} binom_tree_node;

typedef struct _binom_heap_node {
	binom_tree_node *root;		//root of the heap
	struct _binom_heap_node *next;		//next node in heap
} binom_heap_node;		//This will be a binomial tree

typedef struct _binom_heap {
	binom_heap_node *trees;		//trees in heap
	int size;		//number of trees in the heap
} binom_heap;
//END

/* Merges two trees. swapped node pointer will be returned. */
binom_heap_node * merge_binom_trees(binom_heap_node *a, binom_heap_node *b){
	if(a->root->key > b->root->key){
		binom_heap_node temp = *a;
		*a = *b;
		*b = temp;
	}
	
	b->root->parent = a->root;
	b->root->sibling = a->root->child;
	a->root->child = b->root;
	a->root->k++;
	
	return a;
}

/* fixes binomial heap after merge operation. */
void _fixup_binom_heap(binom_heap *c){
	if(c->size <= 1){
		return;
	}
	
	binom_heap_node *curr = c->trees,
	*next = c->trees->next,
	*next_next = c->trees->next->next;
	
	while(curr){
		if(next==NULL){
			curr = next;
		}
		else if(curr->root->k < next->root->k){
			curr = next;
			next = next_next;
			if(next_next){
				next_next = next_next->next;
			}
		}
		else if(next_next && curr->root->k == next->root->k && curr->root->k == next_next->root->k){
			curr = next;
			next = next_next;
			next_next = next_next->next;
		}
		else if(curr->root->k == next->root->k){
			curr = merge_binom_trees(curr,next);
			curr->next = next_next;
			free(next);
			next = next_next;
			if(next_next){
				next_next = next_next->next;
				c->size--;
			}
		}
	}
}

/* prints binomial tree using preorder traversal. */
void _print_binom_tree(binom_tree_node *root){
	if(root) {
		printf("(key=%d, degree=%d) ", root->key, root->k);
		_print_binom_tree(root->child);
		_print_binom_tree(root->sibling);
	}
}

/* merges binomial heaps. */
void merge_binom_heaps(binom_heap *a, binom_heap *b, binom_heap *c){
	binom_heap_node *curr_a = a->trees,
					*curr_b= b->trees;
	c->size = a->size + b->size;
	
	if(curr_a->root->k < curr_b->root->k){
		c->trees = curr_a;
		curr_a= curr_a->next;
	}
	else{
		c->trees = curr_b;
		curr_b = curr_b->next;
	}
	
	binom_heap_node *curr_c = c->trees;
	
	while(curr_a && curr_b){
		if(curr_a->root->k < curr_b->root->k) {
			curr_c->next = curr_a;
			curr_a = curr_a->next;
		}
		else {
			curr_c->next = curr_b;
			curr_b = curr_b->next;
		}
		curr_c = curr_c->next;
	}
	
	if(curr_b){
		curr_c->next = curr_b;
	}
	else if(curr_a){
		curr_c->next = curr_a;
	}
}

/* performs union operation. */
void binom_heap_union(binom_heap *a, binom_heap *b, binom_heap *c)
{
	if(a == NULL || b == NULL || c == NULL) {
		fprintf(stderr, "[in 'binom_heap_union'] Heaps a, b, or c not initialized!\n");
		exit(1);
	}

	merge_binom_heaps(a, b, c);
	_fixup_binom_heap(c);
}

/* creates binomial heap. */
void binom_heap_create(binom_heap *heap, int key)
{
	if(heap == NULL) {
		fprintf(stderr, "[in 'binom_heap_create'] Heap not initialized!\n");
		exit(1);
	}

	heap->trees = (binom_heap_node *)malloc(sizeof(binom_heap_node));

	heap->trees->root = (binom_tree_node *)malloc(sizeof(binom_tree_node));
	heap->trees->root->key = key, heap->trees->root->k = 0;
	heap->trees->root->child = heap->trees->root->parent = heap->trees->root->sibling = NULL;
	heap->trees->next = NULL;

	heap->size = 1;
}

/* inserts element in binomial heap. */
void binom_heap_insert(binom_heap *heap, int key)
{
	binom_heap *new_heap = (binom_heap *)malloc(sizeof(binom_heap));
	binom_heap_create(new_heap, key);

	binom_heap *merged_heap = (binom_heap *)malloc(sizeof(binom_heap));
	binom_heap_union(heap, new_heap, merged_heap);
	*heap = *merged_heap;
	free(new_heap);
	free(merged_heap);
}

/* find minimum element in heap. */
int binom_heap_find_min(binom_heap *heap)
{
	binom_heap_node *temp = heap->trees;
	binom_heap_node *min_node = temp;

	while(temp) {
		if(min_node->root->key > temp->root->key){
			min_node = temp;
		}
		temp = temp->next;
	}

	return min_node->root->key;
}

/* prints binomial heap. */
void binom_heap_print(binom_heap *heap)
{
	int i = 0;
	printf("Binomial Heap of size : %d\n", heap->size);
	for(binom_heap_node *temp=heap->trees; temp; temp=temp->next, i++) {
		printf("%d'th binomial tree : ", i);
		_print_binom_tree(temp->root);
		printf("\n");
	}
}

int main() {
	
	
//	binom_heap a;
//
//	/* Create a binomial heap. */
//	binom_heap_create(&a, 0);
//
//	/* Insert values in the heap. */
//	binom_heap_insert(&a, 1);
//	binom_heap_insert(&a, 2);
//	binom_heap_insert(&a, 3);
//	binom_heap_insert(&a, 4);
//	binom_heap_insert(&a, 5);
//	binom_heap_insert(&a, -6);
//	binom_heap_print(&a);
//
//	/* Find the minimum key. */
//	printf("Minimum key : %d\n", binom_heap_find_min(&a));
//	
//	
	// - - - - - - - -
	
//	/*
	int maxHeapSize = 10;
	binom_heap bhs[maxHeapSize];
	
	int currentIndex = 0, heapCount=1,choice, element;
	
	binom_heap_create(&bhs[0], 0);
	printf("1st heap is created with key 0 by default.\n");
	
	while(true){
			printf("\nMENU : \n");
		printf("SELECTED HEAP : %d\n",currentIndex+1);
		printf("\t[1] Create heap\n");
		printf("\t[2] Insert node\n");
		printf("\t[3] Union operation\n");
		printf("\t[4] find minimum node\n");
		printf("\t[5] Print heap\n");
		printf("\t[6] Change heap\n");
		printf("\t[7] Exit\n");
		printf("Enter choice : ");
		scanf("%d",&choice);
		
		switch (choice) {
			case 1:
				if(heapCount<maxHeapSize){
					printf("Enter first key element of this new heap : ");
					int firstElement;
					scanf("%d",&firstElement);
					binom_heap_create(&bhs[heapCount], firstElement);
					heapCount++;
					printf("Heap %d is created with key %d.",heapCount,firstElement);

				}
				else{
					printf("Heap limit reached.\nCannot create more than %d heaps.",maxHeapSize);
				}
				break;
			case 2:
				printf("Enter key value : ");
				scanf("%d",&element);
				binom_heap_insert(&bhs[currentIndex], element);
				printf("%d key is inserted in Heap %d.",element,currentIndex+1);
				break;
			case 3:
				printf("Available heaps : 1-%d\n",heapCount);
				if(heapCount<2){
					printf("Not enough heaps to perform union operation.\n\t> Create more heaps using option 1.");
				}
				else{
					int firstHeap,secondHeap;
					printf("Enter 1st heap number : ");
					scanf("%d",&firstHeap);
					printf("Enter 2nd heap number : ");
					scanf("%d",&secondHeap);
					binom_heap c;
//					binom_heap_create(c, <start-key-here>);
					binom_heap_union(&bhs[firstHeap-1], &bhs[secondHeap-1], &c);
					printf("Merged heap : \n");
					binom_heap_print(&c);
				}
				break;
			case 4:
				printf("Minimum key of Heap %d is : %d",currentIndex+1,binom_heap_find_min(&bhs[currentIndex]));
				break;
			case 5:
				printf("Heap %d : ",currentIndex+1);
				binom_heap_print(&bhs[currentIndex]);
				break;
			case 6:
				if(heapCount==1){
					printf("Available heap is 1 only.\n");

					
				}
				else{
					printf("Available heaps 1-%d",heapCount);
					int nextHeap;
					printf("Enter heap number : ");
					scanf("%d",&nextHeap);
					if(nextHeap<=heapCount && nextHeap>=1){
						currentIndex = nextHeap-1;
					}
					else{
						printf("Heap not recognized.");
					}
				}
				break;
			case 7:
				printf("Thank you :)");
				return 0;
			default:
				printf("Invalid choice");
				
		}
	}
// */
	
	
	return 0;
}