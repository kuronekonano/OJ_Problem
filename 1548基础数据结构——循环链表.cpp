#include<stdio.h>
#include<queue>//巧妙运用队列，依次筛选循环弹出被杀者
using namespace std;

int main()
{
    int n,m,i;
    queue<int>q;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        while(!q.empty())//必须要清空队列，否则上一轮数据的胜者会遗留下来
        {
            q.pop();
        }
        for(i=1;i<=n;i++)
        {
            q.push(i);//按次序给入列的人标号
        }
        int flag;
        n--;//因为必须剩下一个胜者，所以while括号内为0时，应还剩下一个，这一个在这里被减掉
        while(n--)
        {
            for(i=1;i<m;i++)//只循环m-1次，因为第m个人是被杀的，之前的人可循环归入队列，形成一个圈
            {
                flag=q.front();
                q.pop();
                q.push(flag);
            }
            q.pop();//杀死第m个人
        }
        printf("%d\n",q.front());//最后的胜者只剩一人为队首
    }
    return 0;
}
