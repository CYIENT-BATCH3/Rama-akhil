/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>                  //header file

int main()                          //creating a memory space
{
   int a=0,b=0;
   (a&&b)?printf("true"):puts("false"); 
 //condintional operator
(a||b)?printf("true"):puts("false");
!(a<b)?printf("true\n"):puts("false");
   !(a>b)?printf("true"):puts("false");
      !(a)?printf("true"):puts("false");

   return 0;
}
