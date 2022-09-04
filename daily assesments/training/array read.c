
#include <stdio.h>

int main()
{
   int n,i;                         //decleration
   printf("size of array :");       //asking user to enter size of array
   scanf("%d",&n);                  //reading input from user
   int a[n];                        //initialization of array
  printf("enter the elements:\n");  //printing
   for( i=0;i<n;i++)                //iterating loop to store the vakues in array
   {
       scanf("%d",&a[i]);
       printf("THE %d ELEMENT IS :",i);
   }
   for(i=1;i<n;i++)                 //iterating loop to print the array values
   {
      printf( "%d\t",a[i]);
   }
   
   

    return 0;
}
