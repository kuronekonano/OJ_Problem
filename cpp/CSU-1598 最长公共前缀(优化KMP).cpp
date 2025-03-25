#include <stdio.h>
#include <string.h>
char S[1000008], T[1000008];
int next[1000006];
void getnext(char x[], int m) {
  int i, j;
  j = next[0] = -1;
  i = 0;
  while (i < m) {
    while (j != -1 && x[i] != x[j])
      j = next[j];
    next[i] = x[++i] == x[++j] ? next[j] : j;
  }
}
int kmp(char s[], char t[], int slen, int tlen) {
  int i = 0, j = 0, ans = 0;
  getnext(t, tlen);
  while (i < slen) {
    while (j != -1 && s[i] != t[j])
      j = next[j];
    i++;
    j++;
    if (j >= tlen)
      j = 0, ans++;
  }
  return ans;
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%s %s", S, T);
    printf("%d\n", kmp(S, T, strlen(S), strlen(T)));
  }
}
