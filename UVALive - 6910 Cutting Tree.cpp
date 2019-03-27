#include<stdio.h>///类似并查集的查找函数，顺着存储的父亲节点向上查找公共祖先，如果有，输出YES,否则输出NO
int n,k,t,r[20005],cas=0;///修改树结构，只有删除自己与父亲节点的关系，那么这个节点将作为一个根节点存在，没有父亲节点，父亲为0的也为根节点
int fin(int x)
{
    int tmp=x;
    while(r[tmp]!=0&&r[tmp]!=tmp) tmp=r[tmp];
    return tmp;
}
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&k);
        for(int i=1;i<=n; i++) scanf("%d",&r[i]);
        char c[3];
        printf("Case #%d:\n",++cas);
        for(int i=0; i<k; i++)
        {
            scanf("%s",c);
            if(c[0]=='C')
            {
                int x;
                scanf("%d",&x);
                r[x]=x;
            }
            else
            {
                int a,b;
                scanf("%d%d",&a,&b);
                printf("%s\n",fin(a)==fin(b)?"YES":"NO");
            }
        }
    }
}
