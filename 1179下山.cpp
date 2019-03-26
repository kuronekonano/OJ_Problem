#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int r,c;
int a[105][105];//�߶�����
int vis[105][105];//��ǲ���¼���ȵ�����
int walkx[4]= {0,1,-1,0};///�ĸ�������������
int walky[4]= {1,0,0,-1};
int dfs(int x,int y)
{
    if(vis[x][y]!=0)//������ǹ���˵��֮ǰ���������ҹ��������ȥ��ɽ�׵�·����ֱ��ȡ��������д洢��·����������vis[x][y]
    {
        return vis[x][y];//���仯�������˴������ڼӿ������ٶȣ������ڷ��ص���������
    }
    vis[x][y]=1;//������ǳ��ȣ�һ������Ϊһ�����ȣ���������δ��ǵ����꣬�赱ǰ����Ϊ1
    int nx,ny,i;
    for(i=0; i<4; i++)
    {
        nx=x+walkx[i];
        ny=y+walky[i];
        if(nx>0&&ny>0&&nx<=r&&ny<=c&&a[nx][ny]<a[x][y])
        {
            vis[x][y]=max(vis[x][y],dfs(nx,ny)+1);
        }
    }
    return vis[x][y];//�߲���ȥʱֱ�ӷ����Ǹ����꣬�������ڴ�������߲�����Ψһ�ж��Ƿ������յ�ķ���ֵ��
}

int main()
{
    int i,j;
    while(scanf("%d%d",&r,&c)!=EOF)
    {
        for(i=1; i<=r; i++)///���벿��
        {
            for(j=1; j<=c; j++)
            {
                scanf("%d",&a[i][j]);
            }
        }
        memset(vis,0,sizeof(vis));///��ձ�����飬ͬʱҲ�ǼƲ�������
        int sum=0;
        for(i=1; i<=r; i++)
        {
            for(j=1; j<=c; j++)
            {
                sum=max(sum,dfs(i,j));//����ÿһ���㵽���յĲ�����һֱ��������������
            }
        }
        printf("%d\n",sum);
    }
    return 0;
}
