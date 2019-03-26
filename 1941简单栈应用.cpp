#include<stdio.h>///进出栈路径循环模板小应用
#include<stack>
using namespace std;
int main()
{
    int n,i,a[108],j;
    while(scanf("%d",&n)!=EOF)
    {
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        stack<int>q;
        while(!q.empty())
        {
            q.pop();
        }
        int maxn=0;
        j=0;
        for(i=1;i<=n;i++)///判断进出栈是否合理的模拟循环
        {
            q.push(i);
            if(maxn<q.size())///和普通题差别只是多了个记录最大栈容的值
            {
                maxn=q.size();///size()返回当前栈内容量
            }
            while(!q.empty()&&q.top()==a[j])
            {
                q.pop();
                j++;
            }
        }
        if(j==n)
        {
            printf("%d\n",maxn);
        }
        else
        {
            printf("-1\n");
        }
    }
    return 0;
}
