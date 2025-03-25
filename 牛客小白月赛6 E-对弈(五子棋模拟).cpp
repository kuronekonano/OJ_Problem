#include <bits/stdc++.h>
#define LL long long
#define M(a, b) memset(a, b, sizeof a)
using namespace std;
const int maxn = 1e3 + 7;
int n, q, x, y;
int mp[maxn][maxn];
int main() {
  int flag = 0, num = 0;
  scanf("%d%d", &n, &q);
  for (int i = 1; i <= q; i++) {
    scanf("%d%d", &x, &y);
    if (i & 1)
      mp[x][y] = 1;
    else
      mp[x][y] = -1;
    int tmp = mp[x][y];
    if (!flag) {
      for (int j = 0; j < 4; j++) {
        int sum = 1;
        if (j == 0) {
          int tmx = x + 1, tmy = y;
          while (tmx > 0 && tmx <= n) {
            if (mp[tmx][tmy] == tmp && sum < 5)
              sum++;
            else
              break;
            tmx++;
          }
          tmx = x - 1, tmy = y;
          while (tmx > 0 && tmx <= n) {
            if (mp[tmx][tmy] == tmp && sum < 5)
              sum++;
            else
              break;
            tmx--;
          }
          if (sum >= 5) {
            flag = tmp;
            break;
          }
        }
        if (j == 1) {
          int tmx = x, tmy = y + 1;
          while (tmy > 0 && tmy <= n) {
            if (mp[tmx][tmy] == tmp && sum < 5)
              sum++;
            else
              break;
            tmy++;
          }
          tmx = x, tmy = y - 1;
          while (tmy > 0 && tmy <= n) {
            if (mp[tmx][tmy] == tmp && sum < 5)
              sum++;
            else
              break;
            tmy--;
          }
          if (sum >= 5) {
            flag = tmp;
            break;
          }
        }
        if (j == 2) {
          int tmx = x + 1, tmy = y + 1;
          while (tmx > 0 && tmx <= n && tmy > 0 && tmy <= n) {
            if (mp[tmx][tmy] == tmp && sum < 5)
              sum++;
            else
              break;
            tmx++;
            tmy++;
          }
          tmx = x - 1, tmy = y - 1;
          while (tmx > 0 && tmx <= n && tmy > 0 && tmy <= n) {
            if (mp[tmx][tmy] == tmp && sum < 5)
              sum++;
            else
              break;
            tmx--;
            tmy--;
          }
          if (sum >= 5) {
            flag = tmp;
            break;
          }
        }
        if (j == 3) {
          int tmx = x + 1, tmy = y - 1;
          while (tmx > 0 && tmx <= n && tmy > 0 && tmy <= n) {
            if (mp[tmx][tmy] == tmp && sum < 5)
              sum++;
            else
              break;
            tmx++;
            tmy--;
          }
          tmx = x - 1, tmy = y + 1;
          while (tmx > 0 && tmx <= n && tmy > 0 && tmy <= n) {
            if (mp[tmx][tmy] == tmp && sum < 5)
              sum++;
            else
              break;
            tmx--;
            tmy++;
          }
          if (sum >= 5) {
            flag = tmp;
            break;
          }
        }
      }
    }
    if (flag && num == 0)
      num = i;
  }
  printf("%s %d\n", flag == 0 ? "UNK" : (flag == 1 ? "HtBest" : "WHZ"),
         flag == 0 ? q : num);
}
