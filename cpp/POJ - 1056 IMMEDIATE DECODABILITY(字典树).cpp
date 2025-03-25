#include <stdio.h> ///字典树建树同时判断重复前缀
#include <string.h>
int tot, tre[100][3];
bool vis[100], ans;
int insert(char str[], int rt) {
  int len = strlen(str);
  for (int i = 0; i < len; i++) {
    int x = str[i] - '0';
    if (tre[rt][x] == 0) {
      tre[rt][x] = ++tot;
      memset(tre[tre[rt][x]], 0, sizeof(tre[tre[rt][x]]));
    }
    rt = tre[rt][x];
    if (vis[rt])
      ans = false;
  }
  if (rt < tot)
    ans = false;
  vis[rt] = true;
}
int main() {
  char str[100];
  tot = 0;
  int num = ++tot, cnt = 0;
  memset(vis, false, sizeof(vis));
  memset(tre[num], 0, sizeof(tre[num]));
  ans = true;
  while (scanf("%s", str) != EOF) {
    if (str[0] != '9')
      insert(str, num);
    else {
      printf("Set %d %s\n", ++cnt,
             ans ? "is immediately decodable" : "is not immediately decodable");
      tot = 0;
      int num = ++tot, cnt = 0;
      memset(vis, false, sizeof(vis));
      memset(tre[num], 0, sizeof(tre[num]));
      ans = true;
    }
  }
}
