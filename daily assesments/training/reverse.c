/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>                  //header file

int main()                          //creating a memory space
{
    int n=123456,d1,d2,d3,d4,d5,d6,reverse;
    printf("entered 6 digit number is = %d",n);
    d6=n%10;
    n=n/10;
    d5=n%10;
    n=n/10;
    d4=n%10;
    n=n/10;
    d3=n%10;
    n=n/10;
    d2=n%10;
    n=n/10;
    d1=n%10;
    n=n/10;
    reverse=d6*100000+d5*10000+d4*1000+d3*100+d2*10+d1;
    printf("\nreversed number is = %d",reverse);
    
    return 0;
}
