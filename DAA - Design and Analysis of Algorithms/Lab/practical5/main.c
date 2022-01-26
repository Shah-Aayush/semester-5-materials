/*
19BCE245 Aayush Shah
DAA practical 5
Prims Algorithm
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>


#define inf INT_MAX
#define MAX_SIZE 100
#define graph( i,j ) graph[ (i)*n + (j) ]


/* adjecency list representation for Graphs */
typedef struct {
    int weight[MAX_SIZE];
    int adj[MAX_SIZE];
    int adj_size;
} adj_list_node;

void print_mst_adj_matrix( int *graph, int *mst, const int n )
{
    int cost = 0, tempCost;
    printf("Edges in the MST.\n\n");
    for ( int i=1 ; i<n ; i++ ) {
        tempCost = graph( i, mst[i] );
        printf("   %-5d - %5d   ===>   %5d   \n", mst[i]+1, i+1, tempCost );
        cost+=tempCost;
    }
    printf("\nTotal cost is %d.",cost);
}

void prim_adj_matrix( int *graph, int *mst, const int n )
{
    bool *visited = ( bool * ) calloc ( n , sizeof( bool ) );
    int  *key     = ( int  * ) malloc ( n * sizeof( int  ) );

    /* 'key' values of all the vertices will initially be 'inf' */
    for ( int i=0 ; i < n ; i++ ) key[i] = inf;

    key[0] = 0;  /* Start with vertex 0. */
    mst[0] = -1; /* No parent of the first vertex. */

    for ( int count=0 ; count < n-1 ; count++ ) {

        /* Find minimum key and include it in visited array. */
        int min_key = inf;
        int u = -1; /* Vertex corresponding to the minimum key. */
        for ( int i=0 ; i < n ; i++ ) {
            if ( key[i] < min_key && visited[i] == false ) {
                min_key = key[i];
                u = i;
            }
        }

        visited[u] = true; /* Mark 'u' as visited. */

        /* Iterate throught all the edges of the node 'u'. */
        for ( int v=0 ; v < n ; v++ ) {

            if ( graph( u, v ) && visited[v] == false && graph( u, v ) < key[v] ) {
                mst[v] = u;
                key[v] = graph( u, v );
            }
        }
    }

    free( visited );
    free( key );
}


int main( int argc, char *argv[] )
{
    const int n = 8;

    printf("Running prim's algorithm...\n");

    int *mst = ( int * ) malloc ( sizeof( int ) * n );
    adj_list_node *graph = ( adj_list_node * ) malloc ( sizeof( adj_list_node ) * n );

    int graph_[25] = {  0, 3, 0, 1, 0,
                        3, 0, 2, 5, 1,
                        0, 2, 0, 0, 4,
                        1, 5, 0, 0, 3,
                        0, 1, 4, 3, 0  };

    prim_adj_matrix( graph_, mst, 5 );
    printf("\n==== MST FOUND ====\n\n");
    print_mst_adj_matrix( graph_, mst, 5 );

    return 0;
}