#include <stdio.h>
#include <string.h>
char S[1004], T[1004];
void kmp_pre(char x[], int m, int next[]) /// 子串预处理next数组
{
  int i, j;
  j = next[0] = -1;
  i = 0;
  while (i < m) {
    while (j != -1 && x[i] != x[j])
      j = next[j];
    next[++i] = ++j;
  }
}
int kmp_count(char x[], int m, char y[], int n) {
  int i = 0, j = 0, next[1004], ans = 0;
  kmp_pre(x, m, next);
  while (i < n) {
    while (j != -1 && x[j] != y[i])
      j = next[j];
    i++;
    j++;
    if (j >= m) {
      ans++;
      j = 0;
    }
  }
  return ans;
}
int main() {
  while (scanf("%s", S) != EOF) {
    if (S[0] == '#')
      break;
    scanf("%s", T);
    printf("%d\n", kmp_count(T, strlen(T), S, strlen(S)));
  }
}
