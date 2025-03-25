#include <bits/stdc++.h> ///分情况判断，首先找到两串中谁有*
#define LL long long
#define M(a, b) memset(a, b, sizeof a)
using namespace std;
const int maxn = 2e5 + 7;
int n, t, m;
char a[maxn], b[maxn];
int main() {
  while (scanf("%d%d", &n, &m) != EOF) {
    bool flag = true;
    scanf("%s %s", a, b);
    int pos = -1;
    for (int i = 0; i < n; i++) {
      if (a[i] == '*') {
        pos = i;
        break;
      }
    }
    if (pos == -1) {
      for (int i = 0; i < m; i++)
        if (b[i] == '*') {
          pos = i;
          break;
        }
      if (pos == -1) /// 若两者都没有*
      {
        if (n != m) /// 判断长度
        {
          printf("NO\n");
          continue;
        }
        for (int i = 0; i < n; i++) /// 判断每个字符是否一样
        {
          if (a[i] != b[i]) {
            printf("NO\n");
            flag = false;
            break;
          }
        }
        if (!flag)
          continue; /// 最后错误：没有continue输出两次结果
        else {
          printf("YES\n");
          continue;
        }
      }
      if (pos > n) ///*在b串中
      {
        printf("NO\n"); /// 若星号位置大于a串长度，那么肯定不可能组成
        continue;
      }
      if (m - 1 > n) /// 若剩余b串长度大于a串长度，同样不可能
      {
        printf("NO\n");
        continue;
      }
      for (int i = 0; i < min(pos, n); i++) /// 遍历星号之前位置是否相等
      {
        if (a[i] != b[i]) {
          printf("NO\n");
          flag = false;
          break;
        }
      }
      if (!flag)
        continue;
      for (int i = n - 1, j = m - 1; j > pos && i > 0;
           j--, i--) /// 遍历星号之后位置是否相等
      {
        if (a[i] != b[j]) {
          printf("NO\n");
          flag = false;
          break;
        }
      }
    } else ///*在a串中
    {
      if (pos > m) {
        printf("NO\n");
        continue;
      }
      if (n - 1 > m) {
        printf("NO\n");
        continue;
      }
      for (int i = 0; i < min(pos, m); i++) {
        if (a[i] != b[i]) {
          printf("NO\n");
          flag = false;
          break;
        }
      }
      if (!flag)
        continue;
      for (int i = n - 1, j = m - 1; i > pos && j > 0; i--, j--) {
        if (a[i] != b[j]) {
          printf("NO\n");
          flag = false;
          break;
        }
      }
    }
    if (flag)
      printf("YES\n");
  }
}
