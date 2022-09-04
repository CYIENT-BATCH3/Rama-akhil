
#include <stdio.h>
 int main()
{
 int a;
 int i=1;
 printf("give an input:");
 scanf("%d",&a);
 while(i<=a)
 {
     if(i%2==0)
     {
         printf("%d \t",i);
     }
     i++;
 }
 return 0;
}
   
