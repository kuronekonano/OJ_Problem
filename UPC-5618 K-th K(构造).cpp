#include<bits/stdc++.h>
using namespace std;
struct num
{
    int val,pos;
} a[508],b[508];
bool cmp(num a,num b)
{
    return a.val<b.val;
}
int ans[508*508];
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        bool flag=true;
        memset(ans,0,sizeof(ans));
        for(int i=1; i<=n; i++)
        {
            scanf("%d",&a[i].val);
            b[i].val=a[i].val;
            b[i].pos=a[i].pos=i;
        }
        sort(b+1,b+n+1,cmp);
        int it=1;
        for(int i=1; i<=n; i++)
        {
            ans[a[b[i].pos].val]=b[i].pos;
            for(int j=1; j<b[i].pos; j++) ///在第val为之前要填充pos个pos
            {
                while(ans[it])it++;///只能在没有被填数的位置填
                ans[it]=b[i].pos;
            }
            if(it>a[b[i].pos].val)///若填充超量说明根本不够构造
            {
                printf("No\n");
                flag=false;
                break;
            }
        }
        if(!flag) continue;
        for(int i=1; i<=n; i++) ///对于所有数，先正向填充，保证在val前能填充够pos个
        {
            for(int j=1; j<=n-b[i].pos; j++) ///再反向填充，前pos个能保证的情况下，在剩余空位能填充够n个
            {
                while(ans[it])it++;
                if(it<a[b[i].pos].val)///上一个循环避免了下标太小的情况，现在这个判断防止下标太大导致val位后不足以填充剩余n-pos个
                {
                    printf("No\n");
                    flag=false;
                    break;
                }
                ans[it]=b[i].pos;
            }
            if(!flag) break;
        }
        if(flag)printf("Yes\n");
//        for(int i=1; i<=n*n; i++)printf("%d ",ans[i]);
    }
}
