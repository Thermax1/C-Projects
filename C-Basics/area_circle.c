// calculate Area and Circumference of a circle

#include<stdio.h>
int main()
{
    float r;
    float pie = 3.14;
    printf("enter radius: ");
    scanf("%f", &r);
    //r stores radius 
    //TODO: 1. declare a variable a to hold area and a variable c to hold circumference

    float a = pie * (r * r);
    //TODO  2. calculate and store area into a and circumference into c (you can assume pi = 3.14)

    float diameter = 2.0 * r;
    float c = diameter * pie;
    printf("Area = %.2f circumference = %.2f\n",a,c);
    return 0;
}