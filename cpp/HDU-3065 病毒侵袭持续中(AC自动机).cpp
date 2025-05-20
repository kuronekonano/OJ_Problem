#include <queue>
#include <stdio.h>
#include <string.h>
using namespace std;
struct node {
  int next[26];
  int fail, cnt;
} Tree[50004];
int tot;
queue<int> q;
void init() {
  while (!q.empty())
    q.pop();
  memset(Tree[0].next, 0, sizeof(Tree[0].next));
  Tree[0].fail = Tree[0].cnt = 0;
  tot = 0;
}
void insert(char S[], int num) {
  int len = strlen(S);
  int now = 0;
  for (int i = 0; i < len; i++) {
    if (!Tree[now].next[S[i] - 'A']) {
      Tree[now].next[S[i] - 'A'] = ++tot;
      memset(Tree[Tree[now].next[S[i] - 'A']].next, 0,
             sizeof(Tree[Tree[now].next[S[i] - 'A']].next));
      Tree[Tree[now].next[S[i] - 'A']].fail =
          Tree[Tree[now].next[S[i] - 'A']].cnt = 0;
    } /// 注意初始化，之前错误的把新节点认为是S[i]的编号，这样一直只会清除128号节点之内的值，结果直接错误，tot才是真正新节点的编号，要初始化的应该是tot的子节点
    now = Tree[now].next[S[i] - 'A'];
  }
  Tree[now].cnt = num;
}
void build() {
  Tree[0].fail = -1;
  q.push(0);
  while (!q.empty()) {
    int top = q.front();
    q.pop();
    for (int i = 0; i < 26; i++) {
      if (Tree[top].next[i]) {
        if (top == 0)
          Tree[Tree[top].next[i]].fail = 0;
        else {
          int tmp = Tree[top].fail;
          while (tmp != -1) {
            if (Tree[tmp].next[i]) {
              Tree[Tree[top].next[i]].fail = Tree[tmp].next[i];
              break;
            }
            tmp = Tree[tmp].fail;
          }
          if (tmp == -1)
            Tree[Tree[top].next[i]].fail = 0;
        }
        q.push(Tree[top].next[i]);
      }
    }
  }
}
int ans[1002];
void getans(int n) {
  while (n) {
    if (Tree[n].cnt)
      ans[Tree[n].cnt]++;
    n = Tree[n].fail;
  }
}
int match(char S[]) {
  int len = strlen(S);
  int now = 0;
  for (int i = 0; i < len; i++) {
    if (Tree[now].next[S[i] - 'A'])
      now = Tree[now].next[S[i] - 'A'];
    else {
      int tmp = Tree[now].fail;
      while (tmp != -1 && Tree[tmp].next[S[i] - 'A'] == 0)
        tmp = Tree[tmp].fail;
      if (tmp == -1)
        now = 0;
      else
        now = Tree[tmp].next[S[i] - 'A'];
    }
    if (Tree[now].cnt)
      getans(now);
  }
}
char str[2000006], key[1001][51], tmp[2000006];
int main() {
  int n;
  while (scanf("%d", &n) != EOF) {
    init();
    memset(ans, 0, sizeof(ans));
    for (int i = 1; i <= n; i++) {
      scanf("%s", key[i]);
      insert(key[i], i);
    }
    build();
    scanf("%s", str);
    int len = strlen(str);
    int flag = 0;
    for (
        int i = 0; i <= len;
        i++) /// 注意这里，题目的字典树只有26个大写字母，串T有2e6的长度包含了所有ASCII码字符，必须过滤掉非字典树中的字符，否则全部遍历会TLE(坑点)
    {
      if (str[i] >= 'A' && str[i] <= 'Z')
        tmp[flag++] = str[i];
      else {
        tmp[flag] = '\0';
        match(tmp);
        flag = 0;
      }
    }
    for (int i = 1; i <= n; i++)
      if (ans[i])
        printf("%s: %d\n", key[i], ans[i]);
  }
}
