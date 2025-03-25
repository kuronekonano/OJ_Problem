#include <queue>
#include <stdio.h> ///AC�Զ���������N�����ʣ�������T����ѯ��T�а������ٸ������ĵ���
#include <string.h>
using namespace std;
struct node /// �ֵ����Ľڵ�����
{
  int next[26];  /// ÿ���ַ�֮����26���ڵ�(��ĸ)
  int fail, cnt; /// failָ�����ǰ׺��������ĸ��cnt��Ϊ���ﵥ��ĩβ�ı��
} Tree[500005];  /// ��10000�����ʣ�ÿ�����ʳ��Ȳ�����50
int tot;         /// �ֵ����Ľڵ����
queue<int> q;
void init() /// ��ʼ���ڵ�
{
  while (!q.empty())
    q.pop();
  for (int i = 0; i < 500000; i++) {
    memset(Tree[i].next, 0, sizeof(Tree[i].next));
    Tree[i].fail = Tree[i].cnt = 0;
  }
  tot = 0;
}
void insert(char S[]) /// ����
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
void build() /// ���ѽ���fail��,fail��һ��ʧ������ã�����ĳ���ڵ�ʧ��ʱ����������ʧ��ǰ��һ���ַ���Ϊ���ǰ׺���������ƥ�䴮T��ʵ�����Եı�����T����ƥ��
{
  Tree[0].fail = -1; /// ���ڵ��failΪ-1
  q.push(0);
  while (!q.empty()) {
    int top = q.front();
    q.pop();
    for (int i = 0; i < 26; i++) /// ����Ԫ�س��Ӻ����26������
    {
      if (Tree[top].next[i]) {
        if (top == 0)
          Tree[Tree[top].next[i]].fail = 0; /// ���ڵ��ֱ�Ӻ���failΪ0
        else /// ������Ǹ��ڵ㣬�ҵ�ǰ�ڵ�ĸ��׵�fail����...ֱ���ҵ�һ�����׵Ķ��ӵ�����һ����ĸi��ֵ����������������ǰ׺
        {
          int tmp = Tree[top].fail; /// ���׵�fail
          while (tmp != -1)         /// �Ի��ݵ����ڵ�Ϊֹ
          {
            if (Tree[tmp].next[i]) /// ���׵�fail�ҵ���һ�����Ӻ͸��׵ĺ���һ��
            {
              Tree[Tree[top].next[i]].fail =
                  Tree[tmp].next[i]; /// ���ҵ����ǰ׺��
              break;                 /// ���ǰ׺
            }
            tmp = Tree[tmp].fail; /// δ�ҵ����Լ�һ���ĺ��ӣ���������fail��fail
          }
          if (tmp == -1)
            Tree[Tree[top].next[i]].fail = 0;
        }
        q.push(Tree[top].next[i]);
      }
    }
  }
}
int sum(int n) /// ��β�ڵ�������
{
  int ans = 0;
  while (n) {
    ans += Tree[n].cnt;
    Tree[n].cnt = 0;
    n = Tree[n].fail;
  }
  return ans;
}
int match(char S[]) /// �ԱȲ�ѯ����
{
  int len = strlen(S); /// �ַ�����
  int ans = 0, now = 0;
  for (int i = 0; i < len; i++) /// ������T
  {
    if (Tree[now].next[S[i] - 'a'])
      now =
          Tree[now].next
              [S[i] -
               'a']; /// �����ֵ�����ƥ�䣬�����ǰ�ַ������ֵ����Ľڵ��ַ������¼���ƥ��
    else /// ���ʧ�䣬��ô��ʧ��ڵ�������fail��Ҳ�ʹ��ֵ����е�ĳ�����ʣ�������һ�������ϼ���ƥ�䡣��Ҫʹ��ĵ��ʵ�ǰ׺��ʧ�䵥�ʵ����ǰ׺�����
    {
      int tmp = Tree[now].fail;
      while (tmp != -1 && Tree[tmp].next[S[i] - 'a'] == 0)
        tmp =
            Tree[tmp]
                .fail; /// �ҵ�һ������������fail������������fail��Ҫǰ׺��ͬ������ǰ׺����һ����ĸ(�ӽڵ�)Ҫ���ϴ�T����ƥ����Ǹ���ĸ
      if (tmp == -1)
        now = 0; /// ���������failû�У���ôֻ���������ڵ㡣
      else
        now = Tree[tmp]
                  .next[S[i] - 'a']; /// ����now�������ֵ�����һ�����ʵĽڵ��С�
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
