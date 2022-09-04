#include <stdio.h>
enum SHABBAR{DISPLAYON=0Xff,CURSORON=0X0E,FIRSTLINE=0X0A,SECONDLINE=0X0B,CLEAR=0X01};
int main()
{
   enum SHABBAR put;
   //put=0X08;
   put=DISPLAYON;
   //scanf("%x",&put);
   printf("%x\n",put);
}
   
