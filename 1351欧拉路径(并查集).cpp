#include<stdio.h>
#include<string.h>///���鼯�ķ�������Ƿ�Ϊһ����ͨͼ���ж�����boss��������Ϊͬһ������Ϊһ����ͨͼ����������ͨ
int z[108];
int drg[108];
int find(int x)
{
    int r=x,t;
    while(r!=z[r])//���ϼ�����ѹ��·��
    {
        t=r;///ѹ��·������
        r=z[r];///���ݲ���
        z[t]=z[r];///ѹ��·������
    }
    return r;
}
void join(int a,int b)//join��������������֮��Ĵ�����ϵ
{
    int fa=find(a),fb=find(b);//����˫�����ϼ��������ͬ����������ϵ
    if(fa!=fb)//���ϼ���ͬ
    {
        z[fa]=fb;//����������ϵ
    }
}
int main()
{
    int j,n,m,u,v,i,sum;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        for(i=1; i<=n; i++)//��ʼ�����Լ�Ϊ�Լ����ϴ�
        {
            z[i]=i;
        }
        memset(drg,0,sizeof(drg));
        for(i=1; i<=m; i++)//�����ϵ
        {
            scanf("%d%d",&u,&v);
            drg[u]++;///��¼��u�ڵ�Ķ���
            drg[v]++;///��¼v�ڵ�Ķ���
            join(u,v);///����鲢Ϊһ����ͨ��ͼ
        }
        int boss=find(v);
        bool flag=false;
        for(j=1; j<=n; j++)///�������нڵ�
        {
            if(find(j)!=boss)///���ÿ���ڵ���ϴ�Ϊͬһ������ȷ��Ϊ��ͨͼ
            {
                printf("Graph is not connected!\n");
                flag=true;
                break;
            }
        }
        if(flag)continue;
        int path=0,cir=0;
        for(i=1;i<=n;i++)///���ȷ��Ϊ��ͨͼ���ж����нڵ����ȳ���
        {
            if(drg[i]%2==0)///��Ϊŷ����·�������нڵ������Ϊ2
            {
                cir++;
            }
            else///����������ڵ����ǡ��Ϊ2��������ŷ��ͨ·
            {
                path++;
            }
        }
        if(path==2)printf("have Euler path\n");
        else if(cir==n)printf("have Euler Circuit\n");
        else printf("have no Euler path\n");///����ж����������Ĵ�С����������������������κ�ŷ��·
    }
    return 0;
}
