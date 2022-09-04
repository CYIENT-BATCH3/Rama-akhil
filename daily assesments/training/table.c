#include <stdio.h>
 
int main()
{
  int a;int r=0;		//declaring inputs
  printf("enter a num :");
  scanf("%d",&a);		//reading input from user
  for (int i=1;i<=10;i++)	//for iterations
  {  
     r=a*i; 			//fromulea
    printf("%d x %d = %d\n",a,i,r);//fromat of prining
  }
  return 0;
}