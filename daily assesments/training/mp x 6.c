#include <stdio.h>
#include <limits.h>


int main(void)
{
   unsigned char var;
   printf("ENTER A DECIMAL VALUE BW 0 to 255:");
   scanf(" %d",&var);
   printf("var=%d\n",var);
   printf("ENTER A OCTAL VALUE BW 0 to 377:");
   scanf(" %d",&var);
   printf("var=%o\n",var);
   printf("ENTER A HEXADECIMAL VALUE BW 0 to ff:");
   scanf(" %d",&var);
   printf("var=%x\n",var);
}
