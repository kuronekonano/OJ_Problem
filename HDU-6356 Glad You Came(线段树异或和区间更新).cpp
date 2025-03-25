#include <bits/stdc++.h> ///����������������������С��val��ֵ���³�val
#define LL long long
#define M(a, b) memset(a, b, sizeof a)
using namespace std;
const int maxn = 1e5 + 7;
struct node {
  int l, r;
  LL val;
} tre[maxn << 2];
int m, n;
unsigned int x, y, z;
LL ans;
unsigned int calsq() {
  x = x ^ (x << 11);
  x = x ^ (x >> 4);
  x = x ^ (x << 5);
  x = x ^ (x >> 14);
  unsigned w = x ^ (y ^ z);
  x = y;
  y = z;
  z = w;
  return z;
}
void pushup(
    int rt) /// ��ô�߶���ά��������Сֵ����������ʱ��������Ķ�������С�ڸ���ֵ��
{
  tre[rt].val = min(tre[rt << 1].val, tre[rt << 1 | 1].val);
}
void pushdown(
    int rt) /// ��ʱ���´��ݸ������ֵ����֤��θ��º�ά�����ײ��õ�����Ч�����ֵ����
{
  if (tre[rt].val) {
    tre[rt << 1].val = max(tre[rt << 1].val, tre[rt].val);
    tre[rt << 1 | 1].val = max(tre[rt << 1 | 1].val, tre[rt].val);
    tre[rt].val = 0;
  }
}
void build(int l, int r, int rt) {
  tre[rt].l = l;
  tre[rt].r = r;
  tre[rt].val = 0;
  if (l == r)
    return;
  else {
    int mid = (l + r) >> 1;
    build(l, mid, rt << 1);
    build(mid + 1, r, rt << 1 | 1);
    pushup(rt);
  }
}
void update(int l, int r, unsigned val, int rt) {
  if (tre[rt].val >= val)
    return;
  if (tre[rt].l >= l &&
      tre[rt].r <=
          r) /// ����ʱҪ���������СֵС�ڱ�����ֵ����ô���е���Сֵ���ᱻ���£������������ֵ�޹�
  {
    if (tre[rt].val <= val)
      tre[rt].val = val;
    return;
  }
  pushdown(rt);
  int mid = (tre[rt].l + tre[rt].r) >> 1;
  if (l <= mid)
    update(l, r, val, rt << 1);
  if (r > mid)
    update(l, r, val, rt << 1 | 1);
  pushup(rt); /// ���ϴ�����Сֵ
}
void query(int l, int r, int rt) {
  if (tre[rt].l == tre[rt].r) /// ��ѯʱ��ѯ���ײ㣬�ñ��L���ֵ��˲������ANS
  {
    ans = ans ^ (tre[rt].l * tre[rt].val);
    return;
  }
  pushdown(rt);
  query(l, r, rt << 1);
  query(l, r, rt << 1 | 1);
}
LL f[maxn * 3];
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%d%d%u%u%u", &n, &m, &x, &y, &z);
    build(1, n, 1);
    for (int i = 1; i <= m; i++) { /// ���������ֵ
      LL a = calsq(), b = calsq();
      int l = min(a % n + 1, b % n + 1);
      int r = max(a % n + 1, b % n + 1);
      LL val = calsq() % (1 << 30);
      update(l, r, val, 1);
    }
    ans = 0;
    query(1, n, 1);
    printf("%lld\n", ans);
  }
}
