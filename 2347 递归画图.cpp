#include<stdio.h>
#include<math.h>
#include<string.h>
int poww(int a,int b)
{
    int ans=1;
    while(b!=0)
    {
        if(b&1)ans=ans*a;
        a=a*a;
        b=b>>1;
    }
    return ans;
}
char ma[1005][1005],ans[1005][1005];
int n,m;
int dfs(int t,int x,int y,int xx,int yy)
{
    if(t==1)///递归终点
    {
        for(int i=x,ii=0; i<x+n; i++,ii++)
            for(int j=y,jj=0; j<y+n; j++,jj++)
                ans[i][j]=ma[ii][jj];
        return 0;
    }
    int tmx=poww(n,t-1);
    for(int i=x,ii=0; i<xx; i+=tmx,ii++)
        for(int j=y,jj=0; j<yy; j+=tmx,jj++)
            if(ma[ii][jj]!=' ')dfs(t-1,i,j,i+tmx,j+tmx);
}
int main()
{
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        getchar();
        for(int i=0; i<n; i++)gets(ma[i]);
        if(m==1)
        {
            for(int i=0; i<n; i++)printf("%s\n",ma[i]);
            printf("\n");
            continue;
        }
        memset(ans,' ',sizeof(ans));
        int xx=poww(n,m),tmx=poww(n,m-1);///当以原倍数(m=1)输出图形时，tmx=0，for循环爆炸
        for(int i=0,ii=0; i<xx; i+=tmx,ii++)
            for(int j=0,jj=0; j<xx; j+=tmx,jj++)
                if(ma[ii][jj]!=' ')dfs(m-1,i,j,i+tmx,j+tmx);
        for(int i=0; i<xx; i++)
        {
            for(int j=0; j<xx; j++)
                printf("%c",ans[i][j]);
            printf("\n");
        }
        printf("\n");
    }
}
/*
2 2
**
**
*/
