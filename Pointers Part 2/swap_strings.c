#include <stdio.h>
//In this question you will implement string version of swap
//You are not allowed to use globals
//You are only allowed to use pass-by-address/reference

void swap_string(char **swap1, char **swap2) {
	//TODO: implement string swap
    /***Your code here***/
    char *temp = *swap1;
    *swap1 = *swap2;
    *swap2 = temp;


}


int main(void){
    char * a = "Hello";
    char * b = "World";

    printf("before swap, a=%s\n", a); 
    printf("before swap, b=%s\n", b);
    //Do not modify any code above this line in main function
    
    swap_string(&a,&b);
    
    //Do not modify any code underneath
    printf("after swap, a=%s\n", a); 
    printf("after swap, b=%s\n", b);

}
