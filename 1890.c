#include<stdio.h>
int main()
{
    int i=0,a,b;
    while(scanf("%d %d",&a,&b)!=EOF)
    {
        printf("%d\n",a+b);
        i++;
        if(i!=0)
        printf("\n");
    }
    return 0;
}
