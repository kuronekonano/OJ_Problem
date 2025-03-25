#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e2 + 10;
int main() {
  char str[4][maxn];
  while (scanf("%s %s %s", str[0], str[1], str[2]) != EOF) {
    int i[4], len[4];
    for (int i = 0; i < 3; i++)
      len[i] = strlen(str[i]);
    memset(i, 0, sizeof i);
    char tmp = 'a';
    while (i[tmp - 'a'] < len[tmp - 'a'])
      tmp = str[tmp - 'a'][i[tmp - 'a']++];
    printf("%c\n", tmp - 'a' + 'A');
  }
}
