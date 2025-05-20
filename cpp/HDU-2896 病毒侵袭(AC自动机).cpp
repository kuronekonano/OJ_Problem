#include <algorithm>
#include <queue>
#include <stdio.h>
#include <string.h>
#include <string>
#include <vector>
using namespace std;
struct node {
  int next[128];
  int fail,
      cnt; /// 注意,cnt作为末尾节点的标记，只存在1和0两种情况，不会有一个节点同时是多个单词结尾的情况。(只适用于无重复单词的情况)
} Tree[100005];
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
    if (!Tree[now].next[S[i]]) {
      Tree[now].next[S[i]] = ++tot;
      memset(Tree[Tree[now].next[S[i]]].next, 0,
             sizeof(Tree[Tree[now].next[S[i]]].next));
      Tree[Tree[now].next[S[i]]].fail = Tree[Tree[now].next[S[i]]].cnt = 0;
    }
    now = Tree[now].next[S[i]];
  }
  Tree[now].cnt = num;
}
void build() {
  Tree[0].fail = -1;
  q.push(0);
  while (!q.empty()) {
    int top = q.front();
    q.pop();
    for (int i = 0; i < 128; i++) {
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
vector<int> web[1002];
void getnum(int n, int num) {
  while (n) {
    if (Tree[n].cnt)
      web[num].push_back(Tree[n].cnt);
    n = Tree[n].fail;
  }
}
int match(char S[], int num) {
  int len = strlen(S);
  int now = 0;
  for (int i = 0; i < len; i++) {
    if (Tree[now].next[S[i]])
      now = Tree[now].next[S[i]];
    else {
      int tmp = Tree[now].fail;
      while (tmp != -1 && Tree[tmp].next[S[i]] == 0)
        tmp = Tree[tmp].fail;
      if (tmp == -1)
        now = 0;
      else
        now = Tree[tmp].next[S[i]];
    }
    if (Tree[now].cnt)
      getnum(now, num);
  }
}
char key[202], str[10004];
int main() {
  int n, m;
  while (scanf("%d", &n) != EOF) {
    init();
    int total = 0;
    for (int i = 1; i <= n; i++) {
      scanf("%s", key);
      insert(key, i);
    }
    build();
    scanf("%d", &m);
    for (int i = 0; i <= m; i++)
      web[i].clear();
    for (int i = 1; i <= m; i++) {
      scanf("%s", str);
      match(str, i);
      if (web[i].size())
        total++;
    }
    for (int i = 1; i <= m; i++) {
      if (web[i].size())
        sort(web[i].begin(), web[i].end());
      if (web[i].size()) {
        printf("web %d: ", i);
        printf("%d", web[i][0]);
        for (int j = 1; j < web[i].size(); j++)
          printf(" %d", web[i][j]);
        printf("\n");
      }
    }
    printf("total: %d\n", total);
  }
}
