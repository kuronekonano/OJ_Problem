#include<stdio.h>
#include<string.h>
int n,a[1000001];
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        memset(a,0,sizeof(a));
        scanf("%d",&n);
        int flag;
        int miku;
        for(int i=0; i<n; i++)
        {
            scanf("%d",&flag);
            a[flag]++;
            if(a[flag]>n/2)
            {
                miku=flag;
            }
        }
        printf("%d\n",miku);
    }
    return 0;
}
