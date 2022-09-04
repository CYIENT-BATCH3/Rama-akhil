#include <stdio.h>
 int main()
{
 int n; int fact=1;
 int i=1;
 printf("give an input:");
 scanf("%d",&n);
 while(i<=n)
 {
     
     fact=fact*i;
     i++;
     
 }
 printf("fact of %d is: %d ",n,fact);
 
 return 0;
}
   