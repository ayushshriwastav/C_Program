#include<stdio.h>
void print(int n);
void main()
{
    print(3);
}
void print(int n)
{
    if(n<1)
    {
        return;
    }
    print(n-1);
    printf("%d",n);
    print(n-1);
}