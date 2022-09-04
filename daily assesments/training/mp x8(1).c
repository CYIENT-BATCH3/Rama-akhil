#include <stdio.h>



int main(void)
{
   int i1,i2,i3,i4,i5;
   float f1,f2,f3,f4;
   char ch1,ch2,ch3;
   printf("ENTER A SEQUENCE OF 5 INTEGERS:\n");
   scanf("%d%d%d%d%d",&i1,&i2,&i3,&i4,&i5);
   printf("THE FIVE INT VALUES ARE:\n%d\n%d\n%d\n%d\n%d\n",i1,i2,i3,i4,i5);
   printf("ENTER A SEQUENCE OF 3 CHAR VALUES:\n");
   scanf(" %c %c %c",&ch1,&ch2,&ch3);
   printf("THE THREE CHAR VALUES ARE:\n%c\n%c\n%c\n",ch1,ch2,ch3);
   printf("ENTER FOUR FLOAT VALUES:\n");
   scanf("%f%f%f%f",&f1,&f2,&f3,&f4);
   printf("THE FOUR FLOAT VALUES ARE:\n%f\n%f\n%f\n%f\n%f\n",f1,f2,f3,f4);
}
