#include <stdio.h>
#include <ctype.h>

int main(void) {
	char u[50] = "HELLOWORLD,CS604 STUDENTS!";
	//TODO: Write a loop to convert the above message (in line 4) to lower case
	//You may NOT use the functions toUpper() or toLower()
	//Please note the conversion has to happen in place (in array u). You may NOT declare another array.
	
	/**your code here**/

	for (int i = 0; i < sizeof(u); i++)
	{
		if(isalpha(u[i])) {
			u[i] = u[i] + 32;
		}
	}
	
	//DO NOT modify the following printf, it is supposed to print out helloworld,cs604 students!
	printf("%s\n",u);
	return 0;
}