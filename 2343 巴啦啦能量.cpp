#include <stdio.h> ///�����ַ����ֵĴ������ж��Ƿ�����Ӵ�T��������������һ�δ�S�У�һ�����С������T�ķ�Χ������¼��̴������ұ߽�
#include <string.h>
char S[100008], T[100005];
int ss[300], tt[300];
bool judge() {
  for (int j = 'A'; j <= 'z'; j++)
    if (tt[j] > ss[j])
      return false;
  return true;
}
int main() {
  int lens, lent;
  while (scanf("%s %s", S, T) != EOF) {
    int lens = strlen(S);
    int lent = strlen(T);
    memset(ss, 0, sizeof(ss));
    memset(tt, 0, sizeof(tt));
    int minn = 0, maxn = 100008, low = 0;
    bool ans = false;
    for (int i = 0; i < lent; i++)
      tt[T[i]]++;
    for (int i = 0; i < lens; i++) {
      ss[S[i]]++;
      while (judge()) {
        ans = true;
        if (maxn - minn > i - low) {
          minn = low;
          maxn = i;
        }
        ss[S[low]]--;
        low++;
      }
    }
    if (ans)
      for (int i = minn; i <= maxn; i++)
        printf("%c", S[i]);
    printf("\n");
  }
}
