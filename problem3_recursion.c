#include<stdio.h>
int power(int base,int exp);
int main()
{ 
    int base, exp;
    printf("Enter the base number : ");
    scanf("%d",&base);
    printf("Enter the exp number : ");
    scanf("%d",&exp);
    printf("%d", power(base,exp));
    return 0;
}
int power(int base,int exp)
{
    if(exp==1)
    {
        return base;
    }
    return base*power(base,exp-1);
}