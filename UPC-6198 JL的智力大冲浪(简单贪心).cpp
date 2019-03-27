#include<stdio.h>
#include<math.h>
#include<string.h>
#include<algorithm>
#define LL long long
using namespace std;
struct  node
{
    int t,w;
} a[506];
bool vis[506];
bool cmp(node a,node b)
{
    if(a.t==b.t)return a.w>b.w;
    return a.t<b.t;
}
int main()
{
    int m,n;
    while(scanf("%d",&m)!=EOF)
    {
        memset(vis,false,sizeof(vis));
        scanf("%d",&n);
        for(int i=1; i<=n; i++) scanf("%d",&a[i].t);
        for(int i=1; i<=n; i++) scanf("%d",&a[i].w);
        sort(a+1,a+n+1,cmp);///垃圾水题，错在sort的排序边界忘了+1
        int i=1,time=1;
        while(i<=n)
        {
            if(a[i].t>=time)
            {
                vis[i]=true;
                time++;
            }
            else
            {
                int minn=0x7fffffff,mini=i;
                for(int k=1; k<i; k++)
                    if(a[k].w<minn&&vis[k])
                    {
                        minn=a[k].w;
                        mini=k;
                    }
//                printf("-------%d\n",minn);
                if(minn<a[i].w)
                {
                    m-=minn;
                    vis[i]=true;
                    vis[mini]=false;
                }
                else m-=a[i].w;
            }
            i++;
//            printf("%d=====%d\n",a[i].t,m);
        }
        printf("%d\n",m<0?0:m);
    }
}
/*
1000
9
1 1 1 3 4 5 2 2 2
30 60 90 100 100 100 30 60 90

3000
8
1 2 2 3 4 4 4 4
10 10 10 10 100 100 100 100
*/
