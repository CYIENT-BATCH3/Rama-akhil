
#include <stdio.h>

int main()
{ 
    int a ;int i=1;int count=0;//declaring input variables
    printf("enter a max number :");
    scanf("%d",&a);			//reading input from user
    
    while(i<=a)
    {
        if(a%i==0)			//checking whether reminder is 0 or not
        {
            count++;
        }
        i++;
    }
    if(count==2)			//condition statements to print true portion
    {
    printf("%d is prime",a);
        
    }
    else
    {
    printf("%d is not prime",a);		//statement to print false portion
        
    }

    return 0;
}
