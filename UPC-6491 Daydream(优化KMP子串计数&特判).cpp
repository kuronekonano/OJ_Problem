#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int maxn = 1e5 + 10;
int n;
char a[maxn];
void kmp_pre(char x[], int m, int next[]) {
  int i, j;
  j = next[0] = -1;
  i = 0;
  while (i < m) {
    while (j != -1 && x[i] != x[j])
      j = next[j];
    ++i, ++j;
    next[i] = x[i] == x[j] ? next[j] : j;
  }
}
int kmp_count(char x[], int m, char y[], int n) {
  int ans = 0;
  int i = 0, j = 0, next[maxn];
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
int kmp_countdrmr(char x[], int m, char y[], int n) {
  int ans = 0;
  int i = 0, j = 0, next[maxn];
  kmp_pre(x, m, next);
  while (i < n) {
    while (j != -1 && x[j] != y[i])
      j = next[j];
    i++;
    j++;
    if (j >= m) {
      ans++;
      if (y[i] == 'a' && y[i + 1] == 's' && y[i + 2] == 'e')
        ans--;
      j = 0;
    }
  }
  return ans;
}
char dream[] = "dream";
char dreamer[] = "dreamer";
char erase[] = "erase";
char eraser[] = "eraser";
int lendrm = strlen(dream);
int lendrmr = strlen(dreamer);
int lenera = strlen(erase);
int lenerar = strlen(eraser);
int main() {
  while (scanf("%s", a) != EOF) {
    int len = strlen(a);
    int drm = kmp_count(dream, lendrm, a, len);
    int drmr = kmp_countdrmr(dreamer, lendrmr, a, len);
    int era = kmp_count(erase, lenera, a, len);
    int erar = kmp_count(eraser, lenerar, a, len);
    drm -= drmr;
    era -= erar;
    if (drm * lendrm + drmr * lendrmr + era * lenera + erar * lenerar == len)
      printf("YES\n");
    else
      printf("NO\n");
  }
}
