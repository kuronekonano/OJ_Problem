#include <stdio.h>
#include <string.h>
int ans;
void kmp_pre(char x[], int m, int next[]) {
  int i, j;
  j = next[0] = -1;
  i = 0;
  while (i < m) {
    while (j != -1 && x[i] != x[j])
      j = next[j];
    ++i, ++j;
    next[i] = x[i] == x[j] ? next[j] : j;
    //        next[++i]=++j;
  }
}
int kmp_count(char x[], int m, char y[], int n) {
  int i = 0, j = 0, next[10004];
  kmp_pre(x, m, next);
  while (i < n) {
    while (j != -1 && x[j] != y[i])
      j = next[j];
    i++;
    j++;
    if (j >= m) {
      ans++;
      j = next[j];
    }
  }
  return ans;
}
char S[1000006], T[10004];
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    ans = 0;
    scanf("%s %s", T, S);
    printf("%d\n", kmp_count(T, strlen(T), S, strlen(S)));
  }
}
