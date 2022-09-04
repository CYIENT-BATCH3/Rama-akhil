
#include <stdio.h>
 int main()
{
 int a;
 int i;
 printf("give an input:");
 scanf("%d",&a);
 i=a;
 while(i<=a)
 {
     
     if(i%2==1)
     {
         printf("%d \t",i);
     }
     i--;
 }
 return 0;
}
   
