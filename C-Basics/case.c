//No toupper() or any other C function.
#include<stdio.h>
int main ()
{
    char _lc;
    int _uc;
    printf("Enter a lowercase character: ");
    scanf("%c", &_lc);
    //TODO: convert lowercase character to uppercase. You are not allowed to use an if statement or switch statement. For instance, if _lc stores char 'a', then char 'A' should be stored into _uc.

    _uc = _lc - 32; //ASCII value difference is 32.
    printf("Letter in capital  : %c\n", _uc);
    return 0;


}