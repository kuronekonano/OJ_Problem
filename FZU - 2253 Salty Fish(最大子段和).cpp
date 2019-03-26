#include<stdio.h>
#include<vector>
using namespace std;
const int maxn=1e5+10;
int a[maxn];
vector<int>q;
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        q.clear();
        int tmp=-1,one=0;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            if(a[i])one++;
            if(tmp==-1)
            {
                tmp=1;
                continue;
            }
            if(i!=1&&a[i]!=a[i-1])
            {
                if(a[i-1])tmp=-tmp;
                q.push_back(tmp);
                tmp=1;
            }
            else tmp++;
        }
        if(a[n])tmp=-tmp;
        q.push_back(tmp);
        if(n==one)///必须翻一次
        {
            printf("%d\n",n-1);
            continue;
        }
        int ans=0;
        tmp=0;
        for(int i=0;i<q.size();i++)///最大子段和
        {
            if(tmp>0)tmp+=q[i];
            else tmp=q[i];
            if(tmp>ans)ans=tmp;
        }
        printf("%d\n",one+ans);
    }
}
