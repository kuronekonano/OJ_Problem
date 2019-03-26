#include<stdio.h>
#include<deque>
#include<stack>
#include<algorithm>
using namespace std;
int main()
{
    int a[200008],i,n,ss;
    while(scanf("%d%d",&n,&ss)!=EOF)
    {
        int ans=0;
        for(i=1; i<=n; i++)
        {
            scanf("%d",&a[i]);
            if(a[i]==0&&i!=ss)
            {
                a[i]=0x7fffffff;
            }
            if(a[i]!=0&&ss==i)
            {
                a[i]=0;
                ans++;
            }
        }
        sort(a+1,a+n+1);
        stack<int >q;
        deque<int >s;
        for(i=1; i<=n; i++)
        {
            s.push_front(a[i]);
        }
        while(!s.empty())
        {
            if(q.empty())
            {
                q.push(s.back());
                s.pop_back();
            }
            else
            {
                if(s.back()-q.top()==0||s.back()-q.top()==1)
                {
                    q.push(s.back());
                    s.pop_back();
                }
                else
                {
                    ans++;
                    s.pop_front();
                    q.push(q.top()+1);
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0 ;
}
