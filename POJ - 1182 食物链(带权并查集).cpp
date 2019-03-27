#include<stdio.h>///将于父节点的关系用权值表示
int n,t,fa[50004],link[50004];
int finds(int x)
{
    if(fa[x]!=x)///递归式查找
    {
        int tmp=finds(fa[x]);
        link[x]=(link[x]+link[fa[x]])%3;///根据枚举规律推导出的公式，可以路径压缩计算出当前结点与父亲的父亲结点的关系权值
        fa[x]=tmp;///更新结点的父亲变为原来的爷爷结点
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
        if(fx==fy&&(link[y]-link[x]+3)%3!=flag-1)ans++;///根据当前两堆的根节点相同时，说明两个节点已经被遍历过，已经合为一堆，直接检查两者关系，根据第一次真话，来判断现在这句话是否符合关系权值
        else
        {
            fa[fy]=fx;
            link[fy]=(link[x]-link[y]+flag-1+3)%3;///合并后计算出原根节点与新的父亲节点的关系，根据枚举推导出的公式
        }
    }
    printf("%d\n",ans);
}
