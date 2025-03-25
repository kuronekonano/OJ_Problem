#include<stdio.h>
int main()
{
    int n,m,x;
    scanf("%d%d",&m,&n);
    x=m%n;
    if(x=0)
    printf("YES\n");
    else
    printf("NO\n");
    return 0;
}
