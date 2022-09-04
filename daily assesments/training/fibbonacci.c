/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>

int main()
{
   int a=0;             //declaration of variables and initialization
   int b=1;
   int c,n;
   printf("ENTER NO OF ELEMENTS NEEDED: ");
   scanf("%d",&n);      //reading input from user
   for(int i=1;i<n;i++)     // creating loop to get fibbonacci series
   {
       c=a+b;
       a=b;     // interchanging the positions of a and b
       b=c;
       printf("%d\t",c);        //printing the output
   }
   

    return 0;
}
