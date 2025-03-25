#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 7;
bool vis[maxn];
struct node {
  int num, sum;
  node() {}
  node(int a, int b) {
    num = a;
    sum = b;
  }
};
deque<node>
    q; /// 双向队列保证搜索顺序，因为要先遍历了再同一个按位加和的情况下，所有乘10的情况，再去计算下一个按位加和是否是倍数
int k;
int main() {
  scanf("%d", &k);
  memset(vis, false, sizeof vis);
  q.clear();
  q.push_back(node(1, 1));
  while (!q.empty()) {
    node tmp = q.front(); /// 前端表示尽量保持按位加的变化
    q.pop_front();
    if (!vis[tmp.num]) {
      vis[tmp.num] = true; /// 标记已经遍历过的数
      if (!tmp.num) /// 当对k的取模已经为0且第一个搜到的，表示按照最小按位加且是k的倍数
      {
        printf("%d\n", tmp.sum);
        break;
      }
      q.push_back(node(
          (tmp.num + 1) % k,
          tmp.sum +
              1)); /// 后端表示，当前端都被标记过后，从后端取出+1的按位和来继续搜索所有*10的情况
      q.push_front(node((tmp.num * 10) % k, tmp.sum));
    }
  }
}
