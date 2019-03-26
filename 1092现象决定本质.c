#include<stdio.h>
int main()
{
    int v1,v2,v;
    while(scanf("%d%d",&v1,&v2)!=EOF)
    {
        if(v1<0)
        {
            v=v1-v2;
        }
        else if(v1>0)
        {
            v=v1+v2;
        }
        printf("%d\n",v);
    }
    return 0;
}
