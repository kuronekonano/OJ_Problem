#include<stdio.h>///����Ҫȡģ�����飬ÿһ��ai����֮ǰ�Ǹ��󣬶�����Ч��ȡģ
#include<string.h>///ai����a(i-1)���ӣ���ôa(i-1)������Ч��ȡ��
int main()
{
    bool flag=false;
    int n,m,a,tmp,b[100008],t;
    int vis[100008];
    scanf("%d",&t);
    while(t--)
    {
        int num=0;
        scanf("%d",&n);
        scanf("%d",&vis[++num]);
        for(int i=1; i<n; i++)
        {
            scanf("%d",&a);
            if(a<vis[num])
            {
                while(vis[num]%a==0)num--;
                vis[++num]=a;
            }
        }
        scanf("%d",&m);
        for(int i=0; i<m; i++)
        {
            scanf("%d",&tmp);
            for(int j=1; j<=num; j++)
            {
                if(vis[j]<=tmp)
                {
                    tmp%=vis[j];
                }
            }
            b[i]=tmp;
        }
        for(int i=0; i<m; i++)printf("%d\n",b[i]);
    }
}
