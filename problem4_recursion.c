#include<stdio.h>
int fun(int n);
int main()
{
    printf("%d",fun(6));
    return 0;
}
int fun(int n)
{
    if(n<=1)
    {
        return n;
    }
    return fun(n/2)+fun(n/2)+1;
}