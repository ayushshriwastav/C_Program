#include<stdio.h>
int fact(int n);
int main(void)
{
    int n;
    printf("Enter the number : ");
    scanf("%d",&n);
    printf(" %d \n", fact(n));
    return 0;
}
int fact(int n)
{
    if(n<1)
    {
        return 1;
    }
    else 
    {
        return n * fact(n-1);
    }
}