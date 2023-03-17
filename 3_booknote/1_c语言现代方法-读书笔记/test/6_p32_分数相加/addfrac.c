// adds two fractions

#include <stdio.h>
int main(void)
{
    int num1,denom1,num2,denom2,result_num,result_denom;

    printf("enter first fraction: ");
    scanf("%d/%d",&num1, &denom1);

    printf("enter second fraction: ");
    scanf("%d/%d",&num2,&denom2);

    result_num = num1 * denom2 + num2 * denom1;
    result_denom = denom1 * denom2;
    printf("the sum is %d/%d\n",result_num, result_denom);

    return 0;
}