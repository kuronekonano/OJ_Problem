#include<bits/stdc++.h>///���������������Ǿ���ѭ���ڣ���Ϊ������Ψһ�ģ���ô�ҵ�ÿһ����Ӧ���ڵ�λ�ã��κβ����Լ�λ�õ�������Ҫ�����Ļ��еģ�ֱ�ӱ����ң���������
#define LL long long
#define M(a,b) memset(a,b,sizeof a)
#define pb(x) push_back
using namespace std;
const int maxn=1e5+7;
int a[maxn];
bool vis[maxn];
int main()
{
    int t,n;
    scanf("%d",&t);
    while(t--)
    {
        M(vis,false);
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        LL ans=0;
        for(int i=1;i<=n;i++)
        {
            int cnt=0;
            int tmp=i;
            while(!vis[tmp]&&a[tmp]!=tmp)///����һ���Լ����ڵ�λ��
            {
                cnt++;
                vis[tmp]=true;///��ǻ��и�ֵ�Ƿ񱻱�����
                tmp=a[tmp];
            }
            if(cnt) ans+=cnt-1;///ÿ�����Ľ����������
        }
        printf("%lld\n",ans);
    }
}
