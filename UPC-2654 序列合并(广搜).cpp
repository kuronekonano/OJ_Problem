#include <bits/stdc++.h>
#define LL long long
#define M(a, b) memset(a, b, sizeof a)
using namespace std;
const int maxn = 1e5 + 7;
LL n, a[maxn], b[maxn], disa[maxn], disb[maxn];
struct node {
  int sum, i, j;
  node() {}
  node(int a, int b, int c) {
    sum = a;
    i = b;
    j = c;
  }
  bool operator<(const node &a) const { return sum > a.sum; }
};
priority_queue<node> q;
map<LL, bool> vis;
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    if (i != 0)
      disa[i] = a[i] - a[i - 1]; /// ����������������ֵ
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &b[i]);
    if (i != 0)
      disb[i] = b[i] - b[i - 1];
  }
  while (!q.empty())
    q.pop();
  vis.clear();
  int cnt = 0;
  q.push(node(a[0] + b[0], 0, 0)); /// a1��bi��Ϊ�����Сֵ��ʼ����
  while (!q.empty()) {
    node tmp = q.top();
    q.pop();
    cnt++;
    printf("%d%c", tmp.sum, cnt == n ? '\n' : ' '); /// ȡ��һ����Сֵ���
    if (cnt == n)
      break; /// ����Сֵ�����������е���һ����ֵ�������ȶ�����
    if (!vis[(tmp.i + 1) * 1000000 + tmp.j])
      q.push(node(tmp.sum + disa[tmp.i + 1], tmp.i + 1, tmp.j)),
          vis[(tmp.i + 1) * 1000000 + tmp.j] = true;
    if (!vis[tmp.i * 1000000 + tmp.j + 1])
      q.push(node(tmp.sum + disb[tmp.j + 1], tmp.i, tmp.j + 1)),
          vis[tmp.i * 1000000 + tmp.j + 1] = true;
  }
  printf("\n");
}
/*
5
7 8 1000 1002 1003
2 22 40 63 80

3
2 6 6
1 4 8

9 10 29 30 47

*/
