
#include <stdio.h>
 int main()
{
   int a,b1,b2,b3,b4,b5,b6,b7,b0,binery;
   printf("enter a hexa decimal digit :\n");
   scanf("%x",&a);
  // printf("%d\n",a);
   b0=a%2;a /=2;
   b1=a%2;a /=2;                    //assigning a bit to the b1
   b2=a%2;a /=2;
   b3=a%2;a /=2;
   b4=a%2;a /=2;
   b5=a%2;a /=2;
   b6=a%2;a /=2;
   b7=a%2;a /=2;
   printf("binery number is %d %d %d %d %d %d %d %d\n",b7,b6,b5,b4,b3,b2,b1,b0);
   if(b7==1){
       printf("the driver side 1st door b7 is opened\n");
   }
   else{
       printf("the driver side 1st door b7 is closed\n");
   }
    if(b6==1){
       printf("the driver side 2nd door b6 is opened\n");
   }
   else{
       printf("the drivrside 2nd door b6 is closed\n");
   }
    if(b0==1){
       printf("the  backdoor b1 is opened\n");
   }
   else{
       printf("the backdoor b1 is closed\n");
   }
    if(b4==1){
       printf("the passenger side b4 door is opened\n");
   }
   else{
       printf("the passenger side b4 door is closed\n");
   }
   if(b3==1){
       printf("the passenger side b3 door is opened\n");
   }
   else{
       printf("the passenger side b3 door is closed\n");
   }
        return 0;
}
   
