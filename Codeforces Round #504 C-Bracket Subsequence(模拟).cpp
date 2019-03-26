#include<bits/stdc++.h>
#define LL long long
#define M(a,b) memset(a,b,sizeof a)
using namespace std;
const int maxn = 2e5+7;
int n,k;
char a[maxn];
stack<char>q;
int main()
{
    while(scanf("%d%d",&n,&k)!=EOF)
    {
        scanf("%s",a);
        int ans=0,cnt=0;
        for(int i=0; i<n; i++)
        {
            if(a[i]=='(')
            {
                q.push(a[i]);
                if(cnt*2<k)///输出位置计数，当大于k个左括号则停止输出
                {
                    printf("%c",a[i]);
                    cnt++;
                }
            }
            else q.pop(),printf("%c",a[i]),ans++;
            if(ans*2==k)break;
        }
        printf("\n");
    }
}
