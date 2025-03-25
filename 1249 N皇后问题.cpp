#include <stdio.h> ///不打表会因为多次搜寻而超时
#include <string.h>
bool visr[15], vis1[20], ma[20][20], vis2[20];
int ans[12];
void dfs(int k, int n) {
  if (k == n) {
    //        for(int i=0;i<n;i++)
    //            for(int j=0;j<n;j++)
    //            printf("%d%c",ma[i][j],j==n-1?'\n':' ');
    //        memset(ma,false,sizeof(ma));
    //        printf("==============\n");
    ans[n]++;
    return;
  }
  for (int i = 0; i < n; i++) {
    if (!visr[i] && !vis1[10 + k - i] && !vis2[i + k]) {
      visr[i] = true;
      vis1[10 + k - i] = true;
      //            ma[k][i]=true;
      vis2[i + k] = true;
      dfs(k + 1, n);
      visr[i] = false;
      vis1[10 + k - i] = false;
      //            ma[k][i]=false;
      vis2[i + k] = false;
    }
  }
}
void inti() {
  for (int i = 1; i <= 10; i++) {
    //        memset(ma,false,sizeof(ma));
    memset(visr, false, sizeof(visr));
    memset(vis1, false, sizeof(vis1));
    memset(vis2, false, sizeof(vis2));
    dfs(0, i);
  }
}
int main() {
  int n;
  inti();
  while (scanf("%d", &n) != EOF) {
    if (!n)
      return 0;
    printf("%d\n", ans[n]);
  }
}
