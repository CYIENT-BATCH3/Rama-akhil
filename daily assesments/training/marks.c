
#include <stdio.h>
 int main()
{
   int marks;        //declaring persons
   printf("enter the marks of p1:\n");
   scanf("%d",&marks);
  
   
    if (marks<=100 && marks>=70)

    {
        printf("distiction");
    }
    else if(marks<=69 && marks>=50)
        {
            printf("first class");
        }
        else if(marks<=49 && marks>=40)
            {
                printf("second class");
            }
            else if(marks<=39 && marks>=35)
                {
                    printf("just pass");
                }
        else{
            printf("fail");
        }
        
        return 0;
}
   
