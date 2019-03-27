#include<stdio.h>///最长公共子序列
#include<string.h>
#include<algorithm>
using namespace std;
int vis[2008][2009],t;
int main()
{

    char x[2005];
    char y[2004];
    while(scanf("%s",x+1)!=EOF)
    {
        memset(vis,0,sizeof(vis));
        int lx=strlen(x+1);
        for(int i=1; i<=lx; i++)///回文串子序列，序列中选出一段不连续的子序列使其为回文串
            if(x[i]>='a'&&x[i]<='z') x[i]=x[i]-'a'+'A';///将原串倒过来，计算两串的最长公共子序列即最长回文串
        int ly=0;
        for(int i=lx; i>=1; i--) y[++ly]=x[i];
//        printf("%s  \n%s\n",x+1,y+1);
        for(int i=1; i<=lx; i++)///边界初始化，当空串和有长度的串比较时，公共子序列长度为0
        {
            vis[i][0]=0;
        }
        for(int i=1; i<=ly; i++)
        {
            vis[0][i]=0;
        }
        vis[0][0]=0;///空串比较空串
        for(int i=1; i<=lx; i++)///dp数组中i和j表示，当一个串长i，另一个串长j时，在此情况下的最长公共子序列
        {
            for(int j=1; j<=ly; j++)///因此，每次增加一个串的长度i或j，对比其字符是否相相等的情况下说明此字符将延续最长公共子序列，继承i-1,j-1(两串的字符都不取当前字符的最长值)
            {///当两当前对比字符相等时，直接从i-1,j-1处的值+1，不从i-1,j和i,j-1处继承
                if(x[i]!=y[j])
                {///两字符不等时，从三个方向取最大值来继承

                    vis[i][j]=vis[i-1][j-1];
                    vis[i][j]=max(vis[i-1][j],max(vis[i][j],vis[i][j-1]));
                }
                else
                    vis[i][j]=vis[i-1][j-1]+1;
            }
        }
//        printf("   ");
//        for (int i=1; i<=lx; ++i)
//            printf(" %c",x[i]);
//        puts("");
//        for(int i=0; i<=ly; i++)
//        {
//            printf("%c ",i==0?' ':y[i]);
//            for(int j=0; j<=lx; j++)
//                printf("%d%c",vis[i][j],j==lx?'\n':' ');
//        }
        printf("%d\n",ly-vis[lx][ly]);
    }
    return 0;
}

