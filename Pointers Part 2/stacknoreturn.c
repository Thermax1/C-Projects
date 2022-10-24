//Any stack address (adderess of local vars, address of parameters, and array on stack) 
//should not  be returned to caller because where the address points to
//will be recycled right after callee returns
//The following code suffers this use-garbage-value memory bug and needs to be fixed
//TODO: Please fix the memory leak
//Your code will be tested against Valgrind to ensure there are no memory violations

#include <stdio.h>
#include <stdlib.h>
int array[0];
int * makearray(int size,int base){

  array[size];
  int j;

  for(j=0;j<size;j++)
    array[j] = base*=2; //doubling base

  
  return array;
}

int main(){
  int j, sum=0;
  int * a1 = malloc(sizeof(int *));
  free(a1);
  a1 = makearray(5,2);

  for(j=0;j<5;j++){
    printf("%d ",a1[j]);
    sum+=a1[j];
  }
  printf("\n");

  int * a2 = malloc(sizeof(int *));
  free(a2);
  a2 = makearray(10,3);
  for(j=0;j<10;j++){
    printf("%d ",a2[j]);
    sum+=a2[j];
  }
  printf("\n");

  printf("SUM: %d\n", sum);
}
