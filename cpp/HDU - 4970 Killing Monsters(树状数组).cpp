#include <stdio.h> ///��n�������������У���m����������ÿ��������L��R��Χ�ڵ�ÿ�����������Z���˺�����K�����ÿֻ������POS������������HP��Ѫ����������ܻ����߳�N�����ӵĹ����ж��١�
#include <string.h> ///������Ϊ��״�����С�������ڴ洢ÿ��������ɵ��˺������������˺����ܵ�����£��ᳬʱ��ֻ��������£���������߽�L����Z���ұ߽�R+1����-Z
#define LL                                                                     \
  long long /// ��˵�sum�������ʱ����1��x�ļ���������������˺������߽��-Z������������Xʱ��Ϊ��δ����߽�-Z���������Խ��õ��˴����ӵ��˺�����ʹ�ص����ǵ�����Ҳ�ܵõ��˺�
int n,
    m; /// attact�����ʾ�Ӹ���pos�������յ�����˺�������ʱ��n������1������
       /// ÿ��POS�����˺�����i-1��sum(i)���ƶ���
LL tree[100005], attact[100005];
int lowbit(int x) { return x & (-x); }
void update(int p, int x) /// ����ʱ��x��n
{
  while (p <= n) {
    tree[p] += x;
    p += lowbit(p);
  }
}
LL sum(int x) /// ���ʱ��X��1
{
  LL sum = 0;
  while (x > 0) {
    sum += tree[x];
    x -= lowbit(x);
  }
  return sum;
}
int main() {
  int l, r, z;
  while (scanf("%d", &n) != EOF) {
    if (n == 0)
      break;
    scanf("%d", &m);
    memset(tree, 0, sizeof(tree));
    for (int i = 0; i < m; i++) {
      scanf("%d%d%d", &l, &r, &z);
      update(l, z);
      update(r + 1, -z);
    }
    attact[n + 1] = 0;
    for (int i = n; i >= 1; i--)
      attact[i] = attact[i + 1] + sum(i);
    int k, pos, ans = 0;
    LL hp;
    scanf("%d", &k);
    while (
        k--) /// ��������ÿ�������HP�ͳ�����ʱ��ֻ��Ƚϸù����Ѫ���Ƿ��ܳ��ܴӳ����㵽�յ���˺��ܺͣ������жϸù����Ƿ��ܴ��
    {
      scanf("%lld%d", &hp, &pos);
      if (hp > attact[pos])
        ans++;
    }
    printf("%d\n", ans);
  }
}
