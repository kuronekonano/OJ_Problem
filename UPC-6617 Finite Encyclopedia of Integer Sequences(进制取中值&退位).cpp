#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int maxn=3e5+7;
int n,k,a[maxn];
int main()
{
    scanf("%d%d",&k,&n);
    if(k&1)
    {
        for(int i=1;i<=n;i++)a[i]=(k+1)/2;
        int ptr=n;
        for(int i=1;i<=n/2;i++)
        {
            if(a[ptr]==1)ptr--;
            else
            {
                a[ptr]--;
                for(int j=ptr+1;j<=n;j++)a[j]=k;
                ptr=n;
            }
        }
        for(int i=1;i<=ptr;i++)printf("%d%c",a[i],i==n?'\n':' ');
    }
    else for(int i=1; i<=n; i++)printf("%d%c",i==1?k/2:k,i==n?'\n':' ');
}

