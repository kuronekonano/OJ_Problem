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
    q; /// ˫����б�֤����˳����ΪҪ�ȱ�������ͬһ����λ�Ӻ͵�����£����г�10���������ȥ������һ����λ�Ӻ��Ƿ��Ǳ���
int k;
int main() {
  scanf("%d", &k);
  memset(vis, false, sizeof vis);
  q.clear();
  q.push_back(node(1, 1));
  while (!q.empty()) {
    node tmp = q.front(); /// ǰ�˱�ʾ�������ְ�λ�ӵı仯
    q.pop_front();
    if (!vis[tmp.num]) {
      vis[tmp.num] = true; /// ����Ѿ�����������
      if (!tmp.num) /// ����k��ȡģ�Ѿ�Ϊ0�ҵ�һ���ѵ��ģ���ʾ������С��λ������k�ı���
      {
        printf("%d\n", tmp.sum);
        break;
      }
      q.push_back(node(
          (tmp.num + 1) % k,
          tmp.sum +
              1)); /// ��˱�ʾ����ǰ�˶�����ǹ��󣬴Ӻ��ȡ��+1�İ�λ����������������*10�����
      q.push_front(node((tmp.num * 10) % k, tmp.sum));
    }
  }
}
