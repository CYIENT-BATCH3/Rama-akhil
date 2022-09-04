/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

**************************************************************************/
#include <stdio.h>
struct employee{
    char employee_name[30];
    int id;
    long int cell;
    char location[20];
}details;
int main() {
   printf("enter employ name\n");
    scanf("%s",&details.employee_name);
   
    printf("enter employ id\n");
    scanf("%d",&details.id);
    
    printf("enter employ cell\n");
    scanf("%ld",&details.cell);
    
    printf("enter employ location\n");
    scanf("%s",&details.location);
    
    printf(" emplo name is :%s\n",details.employee_name);
    printf(" emplo id is :%d\n",details.id);
    printf(" emplo cell is :%ld\n",details.cell);
    printf(" emplo location is :%s\n",details.location);
    return 0;
}
