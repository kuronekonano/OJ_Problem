#include <stdio.h>
#include <string.h>
int z[100004], tree[100005], num[100005];
int n, t, m, real;
int lowbit(int x) /// ��״�������ڸ��²�ͬ�������ֵİ�������ǰ׺��
{
  return x & (-x);
}
int update(int p, int x) {
  while (p <= n) {
    tree[p] += x;
    p += lowbit(p);
  }
}
int sum(int p) {
  int sum = 0;
  while (p > 0) {
    sum += tree[p];
    p -= lowbit(p);
  }
  return sum;
}
int finds(int x) {
  int tmp;
  while (z[x] != x) {
    tmp = x;
    x = z[x];
    z[tmp] = z[x];
  }
  return x;
}
void join(int a, int b) {
  int fa = finds(a), fb = finds(b);
  if (fa != fb) {
    z[fb] = fa;
    update(
        num[fa],
        -1); /// �����ɺϲ����������ɵ����������ı䣬��ô���������ڵİ�������ҲҪ��Ӧ�ı�
    update(num[fb], -1);
    num[fa] += num[fb]; /// ��ʾa�̲�b
    num[fb] = 0;        /// b��������Ϊ0��
    update(num[fa], 1); /// �µ�a����������������һ����������
    real--; /// ע����ʵ�������ļ��٣�������������ʱ��һ�����٣���Ϊ���п�������Ч������ȷ���������ټ�ȥ���
            /// ��ʵֵ
  }
}
int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
      num[i] = 1, z[i] = i;
    memset(tree, 0, sizeof(tree));
    update(1, n);
    real = n;
    while (m--) {
      int flag;
      scanf("%d", &flag);
      if (flag == 1) {
        int x, y;
        scanf("%d%d", &x, &y);
        join(x, y);
      } else {
        int k;
        scanf("%d", &k);
        if (k > real) {
          printf("-1\n");
          continue;
        }
        k = real - k +
            1; /// ��״����ǰ׺�ͼ�����ǵ�kС��������ô��Ҫ����ĵ�k��������Ӧ��ʵ�ʰ�����-k+1(����)��λ��
        int l = 1,
            r = n; /// Ҫ����ԭ������ԭ����Ϊ����ʱ��һ��������������߽磬������Ϊ�����������پͼ�����������
        while (
            l <
            r) /// ����kֵ���ֲ���ǰ׺���е�һ�����ڵ���k��λ�ã�Ҳ���Ǹð��ɵ�����
        {
          int mid = (l + r) / 2;
          if (sum(mid) >= k)
            r = mid;
          else
            l = mid + 1;
        }
        printf("%d\n", l);
      }
    }
  }
}
/// ��״�����д洢���ǵ�����Ϊiʱ�İ���������Ҳ�������ĳ��ִ���
/// ������kС�����İ�����������ô����˵��������ǰ׺�ͣ��Ͱ���������С�ڵ��ڸ������İ�����������ǰ׺�ʹ��ڵ���kʱ��˵��������֮ǰ�Ѿ���С��k�����ɣ���ô����k�İ���λ�ڵ��±꼴��kС��������
/// ��ǰ׺�ͣ���1��ĳֵ���±꣬��ʾ��ͬ�������ֵĴ�������ôǰ׺��Ϊk��ʾ���ڴ�֮ǰ��k-1�����ɴ��ڣ���ô��k�����ɵ����������±�
/// ���k���������������ǰ���ڵ��ܰ�����-kֵ+1�õ�����״����������µ�k��������Ҳ�����±�
