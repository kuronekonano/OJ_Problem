#include<stdio.h>///���ڸ��ڵ�Ĺ�ϵ��Ȩֵ��ʾ
int n,t,fa[50004],link[50004];
int finds(int x)
{
    if(fa[x]!=x)///�ݹ�ʽ����
    {
        int tmp=finds(fa[x]);
        link[x]=(link[x]+link[fa[x]])%3;///����ö�ٹ����Ƶ����Ĺ�ʽ������·��ѹ���������ǰ����븸�׵ĸ��׽��Ĺ�ϵȨֵ
        fa[x]=tmp;///���½��ĸ��ױ�Ϊԭ����үү���
    }
    return fa[x];
}
int main()
{
    scanf("%d%d",&n,&t);
    int flag,x,y,ans=0;
    for(int i=1; i<=n; i++)fa[i]=i,link[i]=0;
    while(t--)
    {
        scanf("%d%d%d",&flag,&x,&y);
        if(x>n||y>n||(x==y&&flag==2))
        {
            ans++;
            continue;
        }
        int fx=finds(x),fy=finds(y);
        if(fx==fy&&(link[y]-link[x]+3)%3!=flag-1)ans++;///���ݵ�ǰ���ѵĸ��ڵ���ͬʱ��˵�������ڵ��Ѿ������������Ѿ���Ϊһ�ѣ�ֱ�Ӽ�����߹�ϵ�����ݵ�һ���滰�����ж�������仰�Ƿ���Ϲ�ϵȨֵ
        else
        {
            fa[fy]=fx;
            link[fy]=(link[x]-link[y]+flag-1+3)%3;///�ϲ�������ԭ���ڵ����µĸ��׽ڵ�Ĺ�ϵ������ö���Ƶ����Ĺ�ʽ
        }
    }
    printf("%d\n",ans);
}
