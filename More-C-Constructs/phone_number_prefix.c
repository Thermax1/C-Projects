#include <stdio.h>

int main(void) {
	char original[8];
	printf("Please input a 7-digit phone number:");
	scanf("%s", original);
	char converted[13];
	//DO NOT modify the code above

	//TODO: Insert the area code (516) ahead of the phone number stored original array
	//For instance, if the input is 1234567 then the output is (516)1234567
	//The output must be stored in array converted (already declared in line 7)
	//You MUST use a loop to copy characters over

	for(int i = 0; i < sizeof(original);i++) {
		converted[i] = original[i];
		}
	for(int i = 7; i >= 0;i--){
		converted[i + 1] = converted[i];
	}
	converted[0] = ')';
	for(int i = 8; i >= 0;i--){
		converted[i + 1] = converted[i];
	}
	converted[0] = '6';
	for(int i = 9; i >= 0;i--){
		converted[i + 1] = converted[i];
	}
	converted[0] = '1';
	for(int i = 10; i >= 0;i--){
		converted[i + 1] = converted[i];
	}
	converted[0] = '5';
	for(int i =11; i >= 0;i--){
		converted[i + 1] = converted[i];
	}
	converted[0] = '(';

	//DO NOT modify the code below
       	printf("%s\n", converted);	
}