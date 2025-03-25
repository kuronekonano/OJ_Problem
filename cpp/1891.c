#include<stdio.h>
int main()
{
    int a,b,i=0;
    while(scanf("%d%d",&a,&b)!=EOF)
    {
        if(i!=0)
            printf("\n");
            printf("%d\n",a+b);
        i++;
    }
    return 0;
}
