
#include <stdio.h>
 int main()
{
   float a,b;
   char op;
   printf("enter any two numbers:");
   scanf("%f %f",&a,&b);
   printf("enter an operator(*,+,-,/) : ");
   scanf(" %c",&op);
   switch (op)
   {
       case'+':
       printf("%f + %f = %f",a,b,a+b);
       break;
       case'-':
       printf("%f - %f = %f",a,b,a-b);
       break;
       case'*':
       printf("%f * %f = %f",a,b,a*b);
       break;
       case'/':
       printf("%f / %f = %f",a,b,a/b);
       break;
       default:
       printf("invalid operator");
       break;
   }
        return 0;
}
   
