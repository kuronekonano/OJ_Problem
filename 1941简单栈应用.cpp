#include<stdio.h>///����ջ·��ѭ��ģ��СӦ��
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
        for(i=1;i<=n;i++)///�жϽ���ջ�Ƿ�����ģ��ѭ��
        {
            q.push(i);
            if(maxn<q.size())///����ͨ����ֻ�Ƕ��˸���¼���ջ�ݵ�ֵ
            {
                maxn=q.size();///size()���ص�ǰջ������
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
