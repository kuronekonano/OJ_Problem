#include <algorithm>
#include <stdio.h> ///最长公共子序列/滚动数组
#include <string.h>
using namespace std;
int vis[10][5009], t;
char x[5005];
char y[5004];
int main() {
  int lx;
  while (scanf("%d", &lx) != EOF) {
    scanf("%s", x + 1);
    int ly = 0;
    for (int i = lx; i >= 1; i--)
      y[++ly] = x[i];
    //        printf("%s  \n%s\n",x+1,y+1);
    for (int i = 1; i <= lx; i++)
      vis[i % 2][0] = 0;
    for (int i = 1; i <= ly; i++)
      vis[0][i] = 0;
    vis[0][0] = 0;
    for (int i = 1; i <= lx; i++) {
      for (int j = 1; j <= ly; j++) {
        vis[i % 2][j] = 0;
        if (x[i] != y[j]) {
          vis[i % 2][j] = vis[(i - 1) % 2][j - 1];
          vis[i % 2][j] =
              max(vis[(i - 1) % 2][j], max(vis[i % 2][j], vis[i % 2][j - 1]));
        } else
          vis[i % 2][j] = vis[(i - 1) % 2][j - 1] + 1;
      }
    }
    printf("%d\n", ly - vis[lx % 2][ly]);
  }
  return 0;
}
/**
#include<stdio.h>///最长公共子序列 /short int
#include<string.h>
#include<algorithm>
using namespace std;
short int vis[5008][5009],t;
char x[5005];
char y[5004];
int main()
{
    int lx;
    while(scanf("%d",&lx)!=EOF)
    {
        scanf("%s",x+1);
        int ly=0;
        for(int i=lx; i>=1; i--) y[++ly]=x[i];
//        printf("%s  \n%s\n",x+1,y+1);
        for(int i=1; i<=lx; i++)vis[i][0]=0;
        for(int i=1; i<=ly; i++)vis[0][i]=0;
        vis[0][0]=0;
        for(int i=1; i<=lx; i++)
        {
            for(int j=1; j<=ly; j++)
            {
                vis[i][j]=0;
                if(x[i]!=y[j])
                {
                    vis[i][j]=vis[i-1][j-1];
                    vis[i][j]=max(vis[i-1][j],max(vis[i][j],vis[i][j-1]));
                }
                else vis[i][j]=vis[i-1][j-1]+1;
            }
        }
        printf("%d\n",ly-vis[lx][ly]);
    }
    return 0;
}
**/
