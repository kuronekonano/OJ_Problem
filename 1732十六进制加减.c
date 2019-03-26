#include<stdio.h>
int main()
{
    int t,a,b;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%X%X",&a,&b);
        printf("%X\n",a+b);
    }
    return 0;
}
