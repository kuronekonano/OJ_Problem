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
有n个和咖啡的时间，每天只有m的时间工作，必须每隔d分钟喝一次咖啡，要把所有n个咖啡时间都喝掉最少需要几天
因为要喝掉一次咖啡时间肯定选择已使用天数中截止时间最小的，因此优先队列维护一个top使其作为每次更新的那一天的进行时间
如果连top的时间都无法容纳下当前遍历的咖啡时间，那么说明需要新开一天，并且，每次弹出超过一天工作时间的天数
10 10 1
10 5 7 4 6 3 2 1 9 8

1 2 3 4 5 6 7 8 9 10
1 2 1 2 1 2 1 2 1 2
*/
