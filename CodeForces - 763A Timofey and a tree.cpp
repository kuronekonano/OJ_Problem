#include<stdio.h>
#include<string.h>
int co[100005],x[100005],y[100008];
int main()
{
    int n,link[100005];
    while(scanf("%d",&n)!=EOF)
    {
        memset(co,0,sizeof(co));
        memset(x,0,sizeof(x));
        memset(y,0,sizeof(y));
        memset(link,0,sizeof(link));
        for(int i=1;i<=n-1;i++) scanf("%d%d",&x[i],&y[i]);
        for(int i=1;i<=n;i++) scanf("%d",&co[i]);
        int sum=0;
        for(int i=1;i<=n-1;i++)
        {
            if(co[x[i]]!=co[y[i]])
            {
                sum++;///根节点应有的不同颜色连接次数
                link[x[i]]++;link[y[i]]++;///如果作为根节点，这个点所连接的不同颜色节点个数
            }
        }
        bool flag=false;
        for(int i=1;i<=n;i++)
        {
            if(sum==link[i])///一旦有节点符合作为根节点的连接次数，即存在
            {
                printf("YES\n%d\n",i);
                flag=true;
                break;
            }
        }
        if(!flag)printf("NO\n");

    }
}
/*
题意：一棵树中n个节点被染上了co[i]颜色，让你在一棵树中随便选一个节点作为根节点,然后把整棵树抬起来，问你是否存在一个节点，使得以这个点为根节点的所有子树中的节点的颜色相同
解题思路：若有这样的节点，边的两端端点颜色不一样的边(设为特殊边,这样的边总数为sum)肯定是有和根节点连在一起的(如果没有和根节点相连的话,肯定会造成子树里面有两个颜色不一样的);
*/
