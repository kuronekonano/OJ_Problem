#include<stdio.h>
#include<string.h>
int a[1000002];
int main()
{
    int n,m,i,s,t;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        memset(a,0,sizeof(a));///全部路程清空为0
        for(i=0; i<m; i++)
        {
            scanf("%d%d",&s,&t);
            a[s]++;///起始标记
            a[t]--;///结束标记
        }
        int sum=0;///树木计数
        int flag=0;///当flag遍历到起始标记时，变成>0的数，当遍历到结束标记时，减回0
        for(i=0; i<=n; i++)///因此只用判断flag的值就可以知道现在flag位于哪一种区域，也可以完全避免重合交叉的情况
        {
            flag+=a[i];///加上这个坐标的状态，就相当于检查这个坐标的状态是其实还是结束
            if(flag==0&&a[i]==0)///注意这里是先赋予状态再判断状态是否计数，因此在结束节点时，flag会归于0，但a[t]是没有树的
            {
                sum++;///所以再判断一下这个a[i]是不是结束的地方
            }
        }
        printf("%d\n",sum);
    }
    return 0;
}
