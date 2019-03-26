#include<stdio.h>
int main()
{
    int n,a[15]={1,1,2,3,5,8,13,21,34,55};
    while(scanf("%d",&n)!=EOF)
    {
        printf("%d\n",a[n-1]);
    }
    return 0;
}
