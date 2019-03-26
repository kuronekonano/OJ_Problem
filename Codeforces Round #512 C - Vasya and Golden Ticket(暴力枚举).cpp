#include<bits/stdc++.h>
#define LL long long
#define M(a,b) memset(a,b,sizeof a)
#define pb(x) push_back(x)
using namespace std;
const int maxn=1e5+7;
int n,b[108];
char a[108];
int judge(int x)
{
    for(int i=0;i<n;)
    {
        int sum=0;
        while(sum<x&&i<n)
        {
            sum+=b[i];
            if(sum>x)return false;
            else i++;
        }
        if(i==n&&sum!=x&&sum!=0)return false;
    }
    return true;
}
int main()
{
    scanf("%d",&n);
    scanf("%s",a);
    int l=0,r=0;
    bool ans=false;
    for(int i=0;i<n;i++) b[i]=a[i]-'0',l=l<b[i]?b[i]:l,r+=b[i];
    r--;
    while(l<=r)
    {
        if(judge(r))
        {
            ans=true;
            break;
        }
        else r--;
    }
    if(l==0)ans=true;
    printf("%s\n",ans?"YES":"NO");
}
/*
6
612458
*/
