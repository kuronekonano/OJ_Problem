#include<stdio.h>///����ȫ����
#include<string.h>
int vis[30];///�������
int a[35];

int dfs(int n,int num)
{
    if(num>n)///��num�����ִ�������n�ĸ���ʱ��˵�������ˣ����������ǰ������
    {
        for(int i=1; i<=n; i++)///���a�����е���n����
        {
            printf("%d%c",a[i],i==n?'\n':' ');
        }
        return 0;
    }
    for(int i=1; i<=n; i++)
    {
        if(!vis[i])///��û�б����(�����������Ƿ���ȫ�ֱ����ģ����Ե�һ��for������1���ڶ��ξ���2��������)
        {
            vis[i]=1;///��������
            a[num]=i;
//            for(int k=1; k<=n; k++)printf("%d\n",vis[k]);
//            printf("======\n");
            dfs(n,num+1);///�ݹ�
            vis[i]=0;
        }
    }
}
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        memset(vis,0,sizeof(vis));
        dfs(n,1);
    }
    return 0;
}
