#include<stdio.h>
int main()
{
    int t,m,n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        if(n%(m+1)==0)//∞Õ ≤≤©ﬁ»
        {
            printf("Rabbit\n");
        }
        else
        {
            printf("Grass\n");
        }
    }
    return 0;
}
