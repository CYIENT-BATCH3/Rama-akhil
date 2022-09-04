
#include <stdio.h>

int main()
{
    float a=13.3;
    float b=4.4;
    int int_sum=a+b;
    printf(" = %d\n",int_sum);
    float float_sum=a+b;
    printf("the float sum of float no's is = %f\n",float_sum);
    printf("====================================================================================================================================\n");
    float result=int_sum/float_sum;
    printf("the final result after devided with float sum is = %f\n",result);

    return 0;
}
