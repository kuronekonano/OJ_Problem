#include <algorithm>
#include <stdio.h> ///��״������������+������ɢ��
#include <string.h>
using namespace std;
struct num {
  int n, i;
} a[500005];

int tree[500005], ls[500005], n;
int lowbit(int x) /// ��״����������������״�����¼ĳ����ֵ�Ƿ���ֹ�
{
  return x & (-x);
}
int sum(int p) {
  int sum = 0;
  while (p > 0) {
    sum += tree[p];
    p -= lowbit(p);
  }
  return sum;
}
void update(int p) {
  while (p <= n) {
    tree[p]++;
    p += lowbit(p);
  }
}
bool cmp(num a, num b) { return a.n < b.n; }
int main() /// ���ݷ�Χ9e9�ܴ󣬵�������Ԫ��ֻ��5e5��������ÿ��Ԫ��Ψһ����˽�����Ԫ��ӳ�䵽һ��5e5֮�ڵ���������ɢ��������ռ��˷�
{
  while (scanf("%d", &n) && n) {
    for (int i = 1; i <= n; i++) {
      scanf(
          "%d",
          &a[i].n); /// ��¼ÿ��Ԫ�ص�λ�򣬰���ֵ��С���򣬰���ֵ��С�������������ֵ��λ�����±�ǳ�һ����С������������ֵ��С��ϵ����
      a[i].i = i;
    }
    sort(a + 1, a + n + 1, cmp);
    for (int i = 1; i <= n; i++)
      ls[a[i].i] = i; /// ��ɢ��
    memset(tree, 0, sizeof(tree));
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
      update(
          ls[i]); /// ����ֵ��С����������ݣ����µ�ǰ��������λ���״̬��ʹ֮��ɳ��ֹ�
      ans +=
          i -
          sum(ls[i]); /// sum��ͣ�������ls[i]����֮ǰ���ȳ��ֵ�С��ls[i]�����ĸ�������Щ������λ��
    } /// ��ǰ��������������i����Ŀǰ���ֵ�����������i��ȥ�������ֵ����ĸ�����ʣ������������ls[i]����֮ǰ
    printf(
        "%lld\n",
        ans); /// ���ȳ��ֵĴ���ls[i]����ֵ�����������ls[i]�������������϶�ans�ۼӾ��ǽ��
  }
}
