#include<stdio.h>///����·����¼
#include<queue>
#include<string.h>
using namespace std;
bool vis[600];///�������
int path[600];///·����¼���飬ÿ��������������±��¼����һ��ͣ��������
int main()
{
    int start,stop,i;
    queue<int>q;
    while(scanf("%d%d",&start,&stop)!=EOF)
    {
        memset(vis,false,sizeof(vis));
        memset(path,-1,sizeof(path));
        while(!q.empty())
        {
            q.pop();
        }
        q.push(start);
        vis[start]=true;
        while(!q.empty())///��һ���֣������ҵ����·��������¼·��
        {
            int walk=q.front();
            q.pop();
            if(walk==stop)
            {
                break;
            }
            for(i=1;i<=3;i++)///��˳������������룬1���2��ǰ��3��Ծ
            {
                int will;
                if(i==1)
                {
                    will=walk-1;
                }
                if(i==2)
                {
                    will=walk+1;
                }
                if(i==3)///���ж���ô��
                {
                    will=walk*2;
                }
                if(will>=0&&will<=500&&!vis[will])///���ж������߷�����������
                {
                    vis[will]=true;
                    path[will]=walk;///���������ͼ�¼��һ�����굽·��������,�����൱������Ĵ洢��ʽ�������ű�ʾ���꣬�����д洢�����ֱ�ʾ������֮ǰ��λ��
                    q.push(will);
                }
            }
        }
        int backto=stop;///�ڶ����֣���Ŀ�ĵأ�����·����¼���飬���ݵ���㣬������·�������д洢�������֮��Ĺ�ϵ�������ȳ�ʼ������ָ��backtoΪ����λ�á�
        int flag=0;                                                          ///�ж�ÿһ���Ķ�������ǰ����󣬻�����Ծ
        int road[600];///���������飬��¼ÿһ����·���������ֱ���123��ʾ���ֶ���
        while(path[backto]!=-1)///ѭ���������ҵ�ÿһ�����洢����һ����·����ֱ���ҵ��������û�д洢·����-1
        {
            if(path[backto]==backto+1)///��ǰ������洢����Ĺ�ϵΪ+1ʱ��˵����ǰ�����Ǵ洢������˵õ���
            {
                road[flag++]=1;///��Ǵ˲���Ϊ1�����ˣ�
                backto=path[backto];///��סҪ����
            }
            else if(path[backto]==backto-1)///˵����ǰ�����Ǵ洢������ǰһ���õ���
            {
                road[flag++]=2;
                backto=path[backto];
            }
            else///����������if���ж��������ظ���ʣ�µ����ֻ����Ծ�ˣ���������if����ͨ������һ���ĺ��ˣ��Ի���ܷ�������Ծ��������ϵ
            {
                road[flag++]=3;
                backto=path[backto];
            }
        }
        for(i=flag-1;i>=0;i--)///�������֣����ݶ�������洢��·�����������ÿ����������Ϊ������¼ʱ�Ǵ��յ㵽����
        {
            if(road[i]==1)///���ݶ�������洢�Ķ����������ж��������
            {
                printf("step back\n");
            }
            if(road[i]==2)
            {
                printf("step forward\n");
            }
            if(road[i]==3)
            {
                printf("jump\n");
            }
        }
        printf("\n");

    }
    return 0;
}
