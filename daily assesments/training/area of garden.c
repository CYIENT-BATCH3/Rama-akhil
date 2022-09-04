/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>                  //header file

int main()                          //creating a memory space
{
    int r;
    float pi=3.14;
    
    printf("enter the garden radius =\n");
    scanf("%d",&r);         // reading the input from user
    float area=pi*r*r;              /// formulea for are of a circle
    printf("THE COVERED AREA IS =%f",area);// printing the output
    
    return 0;
}
