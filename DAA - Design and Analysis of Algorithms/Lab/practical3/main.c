#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <sys/stat.h>

int finalArr[500];

int getRandomNumber(int lower, int upper){
  return ((rand() % (upper - lower + 1)) + lower);
}

void swap(int* a, int* b){
  int t = *a;
  *a = *b;
  *b = t;
}

int partition (int arr[], int low, int high) 
{
  int pivot = arr[high]; 
  int i = (low - 1); 
  for (int j = low; j <= high - 1; j++){
    if (arr[j] < pivot){
      i++;
      swap(&arr[i], &arr[j]);
    }
  }
  swap(&arr[i + 1], &arr[high]);
  return (i + 1);
} 

void quickSort(int arr[], int low, int high){ 
  if (low < high){ 
    int pi = partition(arr, low, high); 
    quickSort(arr, low, pi - 1); 
    quickSort(arr, pi + 1, high); 
  }
}

void printArray(int A[], int size){
  int i;
  for (i = 0; i < size; i++)
    printf("%d : %d |", i, A[i]);
  printf("finish\n");
}

void merge(int arr1[], int arr2[], int n1, int n2start, int n2end){
  
  
  int i, j, k=0;
  int n2 = 50;
  int arr3[500];
  
  printf("arr1 : %d : ",n1);
  printArray(arr1, n1);
  printf("arr2 : %d  %d %d : ",n2start,n2end,n2);
  printArray(arr2, n1+50);

  printf("step 1\t");
  int L[n1], R[50];
  
  for (i = 0; i < n1; i++)
    L[i] = arr1[i];
  for (j = n2start; j < n2+n2start; j++)
    R[k++] = arr2[j];
  
  printf("COPIED ARRAYS : \n");
  printArray(R, 50);
  printf("step 2\t");
  
  i = 0; 
  j = 0; 
  k = 0; 
  while (i < n1 && j < 50) {
    if (L[i] <= R[j]) {
      arr3[k] = L[i];
      i++;
    }
    else {
      arr3[k] = R[j];
      j++;
    }
    k++;
  }
  
  printf("step 3\t");
  
  while (i < n1) {
    arr3[k] = L[i];
    i++;
    k++;
  }
  
  printf("step 4\t");
  
  while (j < 50) {
    arr3[k] = R[j];
    j++;
    k++;
  }
  
  
  printf("step 5\n");
  
  char fileName[100];
  sprintf(fileName, "./sorted/%d.txt", n2end);
  FILE* filePointer = fopen(fileName, "w");
  
  char str[40];  
  printf("Printing merged array : ");
  for (int z=0; z<k; z++) {
//    printf("%d ",arr3[z]);
    finalArr[z] = arr3[z];
    sprintf(str, "%d\n", arr3[z]);
    fputs(str,filePointer);
  }
  printf("Printing final array with %d size : ",k);
  printArray(finalArr, k);
  fclose(filePointer);
}

  
int main(){
  int lower = 1, upper = 10000, count = 500;
  srand(time(0));
  int tempInt;
  char str[12];
  int extractedNumbers[count];
  char *line = NULL;
  size_t len = 0;
  ssize_t read;
  
  FILE *filePointer ;
  filePointer = fopen("random_numbers.txt", "w");
  
//  Generating random numbers and adding in file
  for (int i=0; i<count; i++) {
    tempInt = getRandomNumber(lower, upper);
    sprintf(str, "%d\n", tempInt);
    fputs(str,filePointer);
  }
  
  fseek(filePointer, 0, SEEK_SET);

  //Extracting the numbers
  filePointer = fopen("random_numbers.txt", "r");
  
  if(filePointer==NULL){
    printf("File doesn't exists.");
  }
  else {
    int counter = 0;
    printf("output :\n");
    while ((read = getline(&line, &len, filePointer)) != -1) {
      printf("%d : %s",counter,line);
//      printf("before : %lu",strlen(line)-1);
////      line[strlen(line)-1] = '\0';
//      printf(" | after : %lu\n",strlen(line)-1);
      extractedNumbers[counter++] = atoi(line);
//      const char *lineTemp = line;
//      sscanf(line, "%d", &extractedNumbers[counter++]);
      printf("\t%d\n",extractedNumbers[counter-1]);
//      printf("generated number %d : %d",count,extractedNumbers[count-1]);
    }
    printf("DONE");
  }
  fclose(filePointer);
  
  mkdir("sorted",0777); // created directory named sorted
  
  int size;
  int counter = 0;
  
  for (int i=0; i<count/50; i++) {
    
//    fseek(filePointer, 0, SEEK_SET);
    quickSort(extractedNumbers, i*50, (i+1)*50-1);
    
    printf("Iteration %d : \n",i+1);
    printArray(extractedNumbers, 50);
//    size = counter;
    printf("merge starts.\n");
    merge(finalArr, extractedNumbers, counter, i*50, (i+1)*50);
    printf("merge ends.\n");
    counter+=50;
//    fclose(filePointer);
  }
  
//  filePointer = fopen("./sorted/50.txt", "w");
//  filePointer = fopen("./sorted/100.txt", "w");
//  filePointer = fopen("./sorted/150.txt", "w");
//  filePointer = fopen("./sorted/200.txt", "w");
//  filePointer = fopen("./sorted/250.txt", "w");
//  filePointer = fopen("./sorted/300.txt", "w");
//  filePointer = fopen("./sorted/350.txt", "w");
//  filePointer = fopen("./sorted/400.txt", "w");
//  filePointer = fopen("./sorted/450.txt", "w");
//  filePointer = fopen("./sorted/500.txt", "w");
  
  //File 1 [first 50 sort -> File]
  
  
  
  //File 2 [second 50 sort + mergesort with first 50 -> File]
  
  //File 3
  
  //File 4
  
  //File 5
  
  //File 6
  
  //File 7
  
  //File 8
  
  //File 9
  
  //File 10
  
  
  return 0;
}