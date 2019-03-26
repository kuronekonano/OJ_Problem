#include<stack>
#include<string.h>
#include<stdio.h>
#include<algorithm>
using namespace std;
const int maxn=1e6+10;
stack<int>q;
int n;
int a[maxn],b[maxn],dp[maxn];
int main()
{
    while(scanf("%d",&n)!=EOF)
    {
        int num=0,ans=0;
        memset(dp,0,sizeof dp);
        while(!q.empty())q.pop();
        for(int i=0; i<n; i++)
        {
            scanf("%d",&a[i]);
            while(!q.empty()&&a[i]>=a[q.top()])
            {
                if(q.size()==1)
                {
                    b[num++]=a[q.top()];
                    q.pop();
                }
                else
                {
                    dp[i]=max(dp[q.top()]+1,dp[i]);
                    q.pop();
                }
            }
            q.push(i);
        }
        while(!q.empty())
        {
            if(q.size()==1)
            {
                b[num++]=a[q.top()];
                q.pop();
            }
            else
            {
                ans=max(dp[q.top()]+1,ans);
                q.pop();
            }
        }
        for(int i=0;i<n;i++)ans=max(ans,dp[i]);
        printf("%d\n",ans);
        for(int i=0;i<num;i++)
            printf("%d%c",b[i],i==num-1?'\n':' ');
    }
}
/*
7
5 6 3 7 4 1 2
7
7 1 2 3 4 6 5
7
7 5 6 2 3 4 1
8
6 5 4 1 2 3 5 2

6 2 3 5
6 3 5
6 5
6
*/
