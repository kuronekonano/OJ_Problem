#include<bits/stdc++.h>///贪心
#define LL long long
using namespace std;
const int maxn=1e5+10;
struct node
{
    int ti;
    LL vi;
} a[maxn];
priority_queue<int,vector<int>,less<int> >q;///从大到小的优先队列
bool cmp(node a,node b)///先按时间排序，越晚消失的越先遍历，相同时间的打价值大的
{
    if(a.ti==b.ti)return a.vi>b.vi;
    return a.ti>b.ti;
}
int n;
int main()
{
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=0; i<n; i++)scanf("%d",&a[i].ti);
        for(int i=0; i<n; i++)scanf("%lld",&a[i].vi);
        while(!q.empty())q.pop();
        sort(a,a+n,cmp);
        int now=a[0].ti;///初始时间为最后一个消失的
        LL ans=0;
        int i=0;
        while(now)///倒着遍历消失的地鼠，保证价值大的先打
        {
            while(a[i].ti==now)///当遍历到的地鼠在此时小时
                q.push(a[i++].vi);///将其放到队列中表示在目前到之后的时间都是可以打的
            if(!q.empty())///在队列中一直取当前时间下可以打的地鼠
                ans+=q.top(),q.pop();
            now--;///打一只地鼠时间减小
        }
        printf("%lld\n",ans);
    }
}///倒着遍历时间，保证了每次在同一时刻下，遍历所有最晚消失的地鼠，将其放到队列中做价值最高的筛选，如果一只地鼠能打，还没消失，根据他的价值判断打不打
/*

5
5 3 6 1 4
7 9 2 1 5

6
1 1 2 2 3 3
1 1 1 1 1 1000

7
1 2 3 4 4 5 6
1000 0 2000 300 4000 500 20

4
1 2 3 3
2 3 50 51
*/
