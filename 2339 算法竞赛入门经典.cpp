#include <stdio.h>
#include <math.h>
#include<string.h>
using namespace std;
int main()
{
    int n,t,a[108];
    while(scanf("%d%d",&n,&t)!=EOF)
    {
        int ans=0;
        bool flag=true;
        for(int i=0; i<n; i++)
        {
            scanf("%d",&a[i]);
            int tmp=86400-a[i];
            if(t>0)ans++;
            if(t>0&&tmp)t-=tmp;
        }
        printf("%d\n",t>0?0:ans);
    }
}
