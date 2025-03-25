#include <bits/stdc++.h>
using namespace std;
char a[1008];
bool vis[1008];
int main() {
  int n;
  while (scanf("%s", &a) != EOF) {
    memset(vis, false, sizeof vis);
    scanf("%d", &n);
    int len = strlen(a);
    for (int i = 0; i < n; i++) {
      int j = 0;
      while ((vis[j] == true || a[j] <= a[j + 1]) && j < len)
        j++;
      vis[j] = true;
      int tmp = j;
      while (vis[tmp] == true)
        a[tmp--] = a[j + 1];
    }
    bool flag = false;
    //        for(int i=0;i<len;i++)printf("%c",a[i]);
    //        printf("\n");
    for (int i = 0; i < len; i++) {
      if (!vis[i]) {
        if (a[i] == '0' && !flag)
          continue;
        else
          flag = true;
        if (flag)
          printf("%c", a[i]);
      }
    }
    if (!flag)
      printf("0");
    printf("\n");
  }
}
/*
1785934 2
1785934 3
10010010 3
10010010 2
56653536 5
*/
