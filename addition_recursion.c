#include<stdio.h>
int series(int n);
int main(void)
{

    int n;
    printf("Enter the series number you want :");
    scanf("%d", &n);
    printf("%d",series(n));
    return 0;
}
int series(int n)
{
    if(n==0)
    {
        return 0;
    }
    return n + series(n-1);
}