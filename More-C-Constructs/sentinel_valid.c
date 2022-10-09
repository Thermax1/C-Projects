//You do not have a starter code in this question. Follow the instructions below.
//TODO: Copy your implementation of sentinel.c over.

//TODO: Add an input validation to make sure each grade is within the 
//range of [0,100].  If the number is not within that range, it will be discarded, and 
//the code will continue to ask for next grade.  If the number is within the valid range, 
//then the rest is the same as sentinel.c 

/**your code here**/

#include <stdio.h>
int main(void) {


	int t;
	int grades[20]; 
	int i = 0;

    printf("Enter a grade between 0 - 100 or enter -1 to exit:\n");
	scanf("%d", &t);
	
    while((t < 0 && t != -1) || t >= 101) {
        printf("Out of range. Enter a grade between 0 - 100 or enter -1 to exit:\n");
	    scanf("%d",&t);
    }
	while(t != -1){ 



		grades[i] = t;
		i++;

		printf("Enter a grade between 0 - 100 or enter -1 to exit:\n");
		scanf("%d", &t);

        while((t < 0 && t != -1) || t >= 101) {
            printf("Out of range. Enter a grade between 0 and 100 or enter -1 to exit:\n");
		    scanf("%d", &t);
        }

	}
	
	float average; 

	float sum = 0;
	for(int x = 0; x < i; x++) {
		sum = sum + grades[x];

		if(x == (i - 1)) {
			average = sum / i;
		}
	}

    if(i > 0){
	printf("the average grade of the class is %.2f", average);
    }

	return 0;
}