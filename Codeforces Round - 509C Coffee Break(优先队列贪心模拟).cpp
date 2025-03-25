#include <bits/stdc++.h>
#define LL long long
#define M(a, b) memset(a, b, sizeof a)
#define pb(x) push_back(x)
using namespace std;
const int maxn = 2e5 + 7;
struct node {
  int pos, ti;
  bool operator<(const node &a) const { return ti < a.ti; }
} a[maxn];
struct days {
  int day, tim;
  days() {}
  days(int a, int b) { tim = a, day = b; }
  bool operator<(const days &a) const { return tim > a.tim; }
};
int n, m, d, ans[maxn];
priority_queue<days> q;
int main() {
  scanf("%d%d%d", &n, &m, &d);
  for (int i = 0; i < n; i++)
    scanf("%d", &a[i].ti), a[i].pos = i;
  sort(a, a + n);
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    while (!q.empty() && q.top().tim >= m)
      q.pop();
    if (i == 0 || q.top().tim >= a[i].ti) {
      ans[a[i].pos] = ++cnt;
      q.push(days(a[i].ti + d, cnt));
    } else {
      int tmp = q.top().day;
      q.pop();
      ans[a[i].pos] = tmp;
      q.push(days(a[i].ti + d, tmp));
    }
  }
  printf("%d\n", cnt);
  for (int i = 0; i < n; i++)
    printf("%d%c", ans[i], i == n - 1 ? '\n' : ' ');
}

/*
��n���Ϳ��ȵ�ʱ�䣬ÿ��ֻ��m��ʱ�乤��������ÿ��d���Ӻ�һ�ο��ȣ�Ҫ������n������ʱ�䶼�ȵ�������Ҫ����
��ΪҪ�ȵ�һ�ο���ʱ��϶�ѡ����ʹ�������н�ֹʱ����С�ģ�������ȶ���ά��һ��topʹ����Ϊÿ�θ��µ���һ��Ľ���ʱ��
�����top��ʱ�䶼�޷������µ�ǰ�����Ŀ���ʱ�䣬��ô˵����Ҫ�¿�һ�죬���ң�ÿ�ε�������һ�칤��ʱ�������
10 10 1
10 5 7 4 6 3 2 1 9 8

1 2 3 4 5 6 7 8 9 10
1 2 1 2 1 2 1 2 1 2
*/
