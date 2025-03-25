#include <bits/stdc++.h>
#define LL long long
#define M(a, b) memset(a, b, sizeof b)
#define pb(x) push_back(x)
using namespace std;
const int maxn = 100008;
const int inf = 0x3f3f3f3f;
int n;
char str[6][maxn], mastr[maxn];
int nxt[6][maxn], len[6],
    checkpoint
        [6]
        [maxn]; /// checkpoint数组记录主串每一位对于不同子串的匹配记录，因为是并行同时匹配，因此不知道每个子串在不同位置的回退过程
/// 一一记录，这样也保证动态主串前半部分不变信息能够充分利用
inline void kmp_pre(char x[], int m, int num) /// 优化next数组构造
{
  int i, j;
  j = nxt[num][0] = -1;
  i = 0;
  while (i < m) {
    while (j != -1 && x[i] != x[j])
      j = nxt[num][j];
    ++i, ++j;
    nxt[num][i] =
        x[i] == x[j]
            ? nxt[num][j]
            : j; /// 说是优化但是已经改变了内部构造所以有些情况反而可能超时
  }
}
int main() /// 要变化的主串的后缀尽可能匹配字典中单词的前缀，使得加入的字母越少越好，即KMP前缀后缀匹配，每次找到对子串的最大前缀后缀匹配即当前的一个ans
{          /// 即使利用next回退的过程也是寻找最大前缀匹配的过程
  while (scanf("%d", &n) != EOF) {
    int ans = inf;
    for (int i = 0; i < n; i++) {
      scanf("%s", str[i]);
      kmp_pre(str[i], len[i] = strlen(str[i]), i);
      ans = min(ans, len[i]);
    }
    scanf("%s", mastr);
    int mlen = strlen(mastr);
    printf("%d\n", ans); /// 对于空串输出最短单词
    int pt =
        0; /// 动态主串指针，指向的不是主串中的哪个字符，而是主串变化的长度上的下标位
    for (int i = 0; i < mlen; i++) /// 遍历主串的每一个字符，用于比较和退位指针
    {
      ans = inf;
      if (mastr[i] == '-') /// 退位，直接取之前的答案最小值输出即可
      {
        if (pt != 0)
          pt--;
        for (int j = 0; j < n; j++)
          ans = min(ans, len[j] - checkpoint[j][pt]);
        printf("%d\n", ans);
      } else /// 字符增加的时候进行多串并行的KMP匹配
      {
        for (int j = 0; j < n; j++) /// 对每个串比较取取最小值做ans
        {
          int tmj = checkpoint[j][pt];
          while (tmj != -1 && str[j][tmj] != mastr[i])
            tmj = nxt[j][tmj];
          checkpoint[j][pt + 1] = tmj + 1;
        }
        pt++;
        for (int j = 0; j < n; j++)
          ans = min(ans, len[j] - checkpoint[j][pt]);
        printf("%d\n", ans);
      }
    }
  }
}
