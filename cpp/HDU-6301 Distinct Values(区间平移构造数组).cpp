#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int t, n, m, a[maxn];
struct node {
  int l, r;
} qu[maxn];
bool cmp(
    node a,
    node
        b) /// ����߽��С�����������ϱ���˳�򣬰��ұ߽�ϴ��������������������䶼�ϴ󣬲����������Ч(����������ȫ���ǵ�)����
{
  if (a.l == b.l)
    return a.r > b.r;
  return a.l < b.l;
}
priority_queue<int, vector<int>, greater<int>> q;
int ans[maxn];
int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%d%d", &n, &m);
    memset(ans, 0, sizeof ans);
    for (int i = 0; i < m; i++)
      scanf("%d%d", &qu[i].l, &qu[i].r);
    sort(qu, qu + m, cmp);
    while (!q.empty())
      q.pop();
    int maxnum = 1, pl = qu[0].l, pr = qu[0].r;
    if (m != 0) {
      for (int i = qu[0].l; i <= qu[0].r; i++)
        ans[i] = maxnum++;
      for (int i = 1; i < m; i++) {
        while (pl < qu[i].l) {
          if (pl <= pr)
            q.push(
                ans[pl]); /// ֻ�е�Lָ��С��Rָ��ʱ�Ž����ͷŵ�����Ͷ�������
          pl++;
        }
        while (pr < qu[i].r) {
          pr++;
          if (!q.empty()) {
            if (pr >= pl)
              ans[pr] = q.top(),
              q.pop(); /// ͬ��ֻ�е�Rָ�����Lָ��ʱ�Ÿ�ֵ����
          } else
            ans[pr] =
                maxnum++; /// �������Ϊ�գ�˵����ʹ�õ����ֵ�����ô��ʱ�Ž����ȶ����к�ѡֵ����������
        }
      }
    }
    for (int i = 1; i <= n; i++)
      printf("%d%c", ans[i] == 0 ? 1 : ans[i], i == n ? '\n' : ' ');
  }
}
/*
99
2 1
1 2
4 2
1 2
3 4
5 2
1 3
2 4
9 0
9 2
1 3
5 7
*/
