#include <algorithm>
#include <stdio.h>
#include <string.h>
using namespace std;
int main() {
  int n, k, a[200008], i;
  while (scanf("%d%d", &n, &k) != EOF) {
    int vis[200008];
    memset(vis, 0, sizeof(vis));
    int flag = 0;
    a[0] = 1;
    int change = 0;
    for (i = 1; i <= n; i++) {
      scanf("%d", &a[i]);
      if (a[i] < 0) {
        flag++;
      }
      if ((a[i - 1] >= 0 && a[i] < 0) || (a[i - 1] < 0 && a[i] >= 0)) {
        change++;
      }
    }
    if (flag == 0) {
      printf("0\n");
      continue;
    }
    if (flag > k) {
      printf("-1\n");
      continue;
    }
    int j = 0;
    for (i = 1; i <= n; i++) {
      vis[j] = a[i] >= 0 ? vis[j] + 1 : vis[j] - 1;
      if ((a[i] < 0 && a[i + 1] >= 0) || (a[i] >= 0 && a[i + 1] < 0)) {
        j++;
        if (i == n)
          j--;
      }
    }
    //        for(i=0;i<=j;i++)
    //        {
    //            printf("%d %d\n",vis[i],i);
    //        }
    if (j > 1) {
      sort(vis + 1, vis + j - 1);
    }
    k = k - flag;
    for (i = 1; i < j; i++) {
      if (vis[i] > 0 && vis[i] <= k) {
        change -= 2;
        k -= vis[i];
      }
    }
    if (vis[j] <= k && vis[j] > 0) {
      change--;
      k = k - vis[j];
    }
    //            if((a[i-1]>=0&&a[i]<0)||(a[i-1]<0&&a[i]>=0))
    //            {
    //                change++;
    //            }
    printf("%d\n", change);
  }
}
