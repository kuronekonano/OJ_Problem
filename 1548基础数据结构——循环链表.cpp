#include<stdio.h>
#include<queue>//�������ö��У�����ɸѡѭ��������ɱ��
using namespace std;

int main()
{
    int n,m,i;
    queue<int>q;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        while(!q.empty())//����Ҫ��ն��У�������һ�����ݵ�ʤ�߻���������
        {
            q.pop();
        }
        for(i=1;i<=n;i++)
        {
            q.push(i);//����������е��˱��
        }
        int flag;
        n--;//��Ϊ����ʣ��һ��ʤ�ߣ�����while������Ϊ0ʱ��Ӧ��ʣ��һ������һ�������ﱻ����
        while(n--)
        {
            for(i=1;i<m;i++)//ֻѭ��m-1�Σ���Ϊ��m�����Ǳ�ɱ�ģ�֮ǰ���˿�ѭ��������У��γ�һ��Ȧ
            {
                flag=q.front();
                q.pop();
                q.push(flag);
            }
            q.pop();//ɱ����m����
        }
        printf("%d\n",q.front());//����ʤ��ֻʣһ��Ϊ����
    }
    return 0;
}
