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
    } /// ע���ʼ����֮ǰ����İ��½ڵ���Ϊ��S[i]�ı�ţ�����һֱֻ�����128�Žڵ�֮�ڵ�ֵ�����ֱ�Ӵ���tot���������½ڵ�ı�ţ�Ҫ��ʼ����Ӧ����tot���ӽڵ�
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
        i++) /// ע�������Ŀ���ֵ���ֻ��26����д��ĸ����T��2e6�ĳ��Ȱ���������ASCII���ַ���������˵����ֵ����е��ַ�������ȫ��������TLE(�ӵ�)
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
