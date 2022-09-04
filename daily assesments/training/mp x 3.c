#include <stdio.h>
#include <limits.h>


int main()
{

   printf("BITS IN CHAR %d\n", CHAR_BIT);

   printf("MIN VAL OF SIGNED CHAR = %d\n", SCHAR_MIN);
   printf("MAX VAL OF SIGNED CHAR = %d\n", SCHAR_MAX);
   printf("MAX VAL OF UNSIGNED CHAR = %d\n", UCHAR_MAX);

   printf("MIN VAL OF SHORT INT = %d\n", SHRT_MIN);
   printf("MAX VAL OF SHORT INT = %d\n", SHRT_MAX); 

   printf("MIN VAL OF INT = %d\n", INT_MIN);
   printf("MAX VAL OF INT = %d\n", INT_MAX);

   printf("MIN VAL OF CHAR = %d\n", CHAR_MIN);
   printf("MAX VAL OF CHAR = %d\n", CHAR_MAX);

   printf("MIN VAL OF LONG = %ld\n", LONG_MIN);
   printf("MAX VAL OF LONG = %ld\n", LONG_MAX);
   
   
   return(0);
}
