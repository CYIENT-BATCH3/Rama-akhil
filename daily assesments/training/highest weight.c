/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>                  //header file

int main()                          //creating a memory space
{
   int u1,u2,u3;        //declaring persons
   printf("enter the weights of 1 person:\n");
   scanf("%d",&u1);
   printf("enter the weights of 2 person:\n");
   scanf("%d",&u2);
   printf("enter the weights of 3 person:\n");
   scanf("%d",&u3);
  ( (u1>u2)&&(u1>u3))?printf("1 is bigger = %d",u1):(u3>u2)?printf("3 is bigger = %d",u3):printf("2 is bigger = %d",u2);    //condintinaol statement
   return 0;
}
