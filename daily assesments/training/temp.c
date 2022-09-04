
#include <stdio.h>
 int main()
{
   
   int temp;        //declaring persons
   printf("enter the temp of room:\n");
   scanf("%d",&temp);
  
   
    if (temp>=40)

    {
        printf("VERY HOT");
    }
    else if(temp<40 && temp>=30)
        {
            printf("HOT ");
        }
        else if(temp<=29 && temp>=20)
            {
                printf("NORMAL IN TEMP ");
            }
            else if(temp<=19 && temp>=10)
                {
                    printf(" COLD WHETHER");
                    
                }
                 else if(temp<=9 && temp>=0)
                {
                    printf(" VERY COLD WHETHER");
                }
                 else if(temp<0)
                {
                    printf("freezing whether ");}
        return 0;
}
   
