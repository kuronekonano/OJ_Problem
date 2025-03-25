#include <queue>
#include <stdio.h> ///AC自动机，给出N个单词，给出串T，查询串T中包含多少个给出的单词
#include <string.h>
using namespace std;
struct node /// 字典树的节点类型
{
  int next[26];  /// 每个字符之后又26个节点(字母)
  int fail, cnt; /// fail指向最大前缀后续的字母，cnt作为到达单词末尾的标记
} Tree[500005];  /// 有10000个单词，每个单词长度不超过50
int tot;         /// 字典树的节点计数
queue<int> q;
void init() /// 初始化节点
{
  while (!q.empty())
    q.pop();
  for (int i = 0; i < 500000; i++) {
    memset(Tree[i].next, 0, sizeof(Tree[i].next));
    Tree[i].fail = Tree[i].cnt = 0;
  }
  tot = 0;
}
void insert(char S[]) /// 建树
{
  int len = strlen(S);
  int now = 0;
  for (int i = 0; i < len; i++) {
    if (!Tree[now].next[S[i] - 'a'])
      Tree[now].next[S[i] - 'a'] = ++tot;
    now = Tree[now].next[S[i] - 'a'];
  }
  Tree[now].cnt++;
}
void build() /// 广搜建立fail树,fail是一个失配的利用，当在某个节点失配时，可以利用失配前的一串字符作为最大前缀，往后继续匹配串T，实现线性的遍历串T进行匹配
{
  Tree[0].fail = -1; /// 根节点的fail为-1
  q.push(0);
  while (!q.empty()) {
    int top = q.front();
    q.pop();
    for (int i = 0; i < 26; i++) /// 队首元素出队后遍历26个孩子
    {
      if (Tree[top].next[i]) {
        if (top == 0)
          Tree[Tree[top].next[i]].fail = 0; /// 根节点的直接孩子fail为0
        else /// 如果不是根节点，找当前节点的父亲的fail父亲...直到找到一个父亲的儿子等于下一个字母i的值，这个过程是找最大前缀
        {
          int tmp = Tree[top].fail; /// 父亲的fail
          while (tmp != -1)         /// 以回溯到根节点为止
          {
            if (Tree[tmp].next[i]) /// 父亲的fail找到了一个孩子和父亲的孩子一样
            {
              Tree[Tree[top].next[i]].fail =
                  Tree[tmp].next[i]; /// 即找到最大前缀。
              break;                 /// 最大前缀
            }
            tmp = Tree[tmp].fail; /// 未找到和自己一样的孩子，继续回溯fail的fail
          }
          if (tmp == -1)
            Tree[Tree[top].next[i]].fail = 0;
        }
        q.push(Tree[top].next[i]);
      }
    }
  }
}
int sum(int n) /// 结尾节点计数求和
{
  int ans = 0;
  while (n) {
    ans += Tree[n].cnt;
    Tree[n].cnt = 0;
    n = Tree[n].fail;
  }
  return ans;
}
int match(char S[]) /// 对比查询函数
{
  int len = strlen(S); /// 字符串长
  int ans = 0, now = 0;
  for (int i = 0; i < len; i++) /// 遍历串T
  {
    if (Tree[now].next[S[i] - 'a'])
      now =
          Tree[now].next
              [S[i] -
               'a']; /// 类似字典树的匹配，如果当前字符符合字典树的节点字符，往下继续匹配
    else /// 如果失配，那么从失配节点找他的fail，也就从字典树中的某个单词，跳到另一个单词上继续匹配。这要使别的单词的前缀和失配单词的最大前缀相符。
    {
      int tmp = Tree[now].fail;
      while (tmp != -1 && Tree[tmp].next[S[i] - 'a'] == 0)
        tmp =
            Tree[tmp]
                .fail; /// 找到一个符合条件的fail，符合条件的fail既要前缀相同，而且前缀的下一个字母(子节点)要符合串T正在匹配的那个字母
      if (tmp == -1)
        now = 0; /// 如果向上找fail没有，那么只能跳到根节点。
      else
        now = Tree[tmp]
                  .next[S[i] - 'a']; /// 否则now跳到了字典中另一个单词的节点中。
    }
    if (Tree[now].cnt)
      ans += sum(now);
  }
  return ans;
}
char key[60], str[1000006];
int main() {
  int t, n;
  scanf("%d", &t);
  while (t--) {
    init();
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
      scanf("%s", key);
      insert(key);
    }
    build();
    scanf("%s", str);
    printf("%d\n", match(str));
  }
}
