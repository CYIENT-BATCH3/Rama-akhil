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
  
   int c=a+b,n;
   printf("ENTER NO OF ELEMENTS NEEDED: ");
   scanf("%d",&n);      //reading input from user
   printf("%d\t%d\t",a,b);
   for(int i=2;i<n;i++)     // creating loop to get fibbonacci series
   {
       printf("%d\t",c);
       
       a=b;     // interchanging the positions of a and b
       b=c;
       c=a+b;
       if(c>=n)
       break;      //printing the output
   }
   

    return 0;
}