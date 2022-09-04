
#include <stdio.h>
 int main()
{
  int num;
  int reminder;
  int sum;
  printf("enter a 4 digit num:\n");
  scanf("%d",num)
  while(num>0)
  {
      
      reminder=num%10;
      sum=sum+reminder;
      num=num/10;
  }
  printf("THE SUM OF THE DIGITS IN NUMBER IS :%d \n",sum);
        return 0;
}
   
