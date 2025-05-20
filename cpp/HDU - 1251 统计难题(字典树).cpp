#include <cstdio>
#include <cstring>
using namespace std;
int tot;
int trie[500000][26];
int num[500000];              /// 记录节点被访问次数
int insert(char *str, int rt) // 建树
{
  for (int j = 0; str[j]; j++) {
    int x = str[j] - 'a'; // 第x个分支是这个字母，此层的分支就是x，从x再分出节点
    if (trie[rt][x] == 0) {
      trie[rt][x] = ++tot; // 若是未标记的新字母，则重新标号
    }
    num[trie[rt][x]]++;
    rt = trie[rt][x];
  }
}
int find(char *str, int rt) // 查询字典
{
  int x, len = strlen(str);
  for (int i = 0; i < len; i++) {
    x = str[i] - 'a';
    if (trie[rt][x] == 0)
      return 0;
    if (i != len - 1)
      rt = trie[rt][x];
  }
  return num[trie[rt][x]];
}

char str[100];
int main() {
  tot = 0; /// 根节点
  int floor = ++tot;
  memset(trie[floor], 0, sizeof(trie[floor]));
  memset(num, 0, sizeof(num));
  while (gets(str)) {
    if (str[0] == NULL)
      break;
    insert(str, floor);
  }
  char s[15];
  while (scanf("%s", s) != EOF)
    printf("%d\n", find(s, floor));
  return 0;
}
