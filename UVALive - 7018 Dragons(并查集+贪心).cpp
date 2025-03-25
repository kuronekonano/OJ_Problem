#include <algorithm>
#include <stdio.h> ///���鼯+̰��
#include <string.h>
using namespace std;
struct dragon {
  int ci, si, ni;
} a[1002];
int n, m, k, city[305];
int finds(int i) {
  int r = i, t;
  while (city[r] != r) /// ���Բ���·��ѹ��������һ��Ҫ�ǵ÷���boss
  {
    t = r;
    r = city[r];
    city[t] = city[r];
  }
  return r;
}
int join(int x, int y) {
  int a = finds(x), b = finds(y);
  if (a != b)
    city[a] = b;
}
bool cmp(
    dragon a,
    dragon
        b) /// ��ͷ�������ٶȴӴ�С�����������ж������ٶȽϿ�����������������ڳ�ʼʱɱ���������γɵĳ�ʼ��Ⱥ���ں����ı�����Ҳ������Ϊһ������������
{
  return a.ni >
         b.ni; /// ������Ϊɱ����ʼͷ��������֮�ͣ��������������޷����ơ�֮��������ۼӣ�Ҳ���һЩ���������ٶȴ��ˣ��Ͳ���Ҫ������
}
int main() {
  while (scanf("%d%d%d", &n, &m, &k) != EOF) {
    if (!n && !m && !k)
      return 0;
    int x, y;
    for (int i = 0; i <= n; i++)
      city[i] = i;
    for (int i = 0; i < m; i++) {
      scanf("%d%d", &x, &y);
      join(x, y); /// �γɼ��ŵĻ�ͨ����
    }
    for (int i = 0; i < k; i++)
      scanf("%d%d%d", &a[i].ci, &a[i].si, &a[i].ni);
    sort(a, a + k, cmp);
    int sum[305];
    memset(sum, 0, sizeof(sum)); /// ÿ�����ŵ���С��������
    for (int i = 0; i < k; i++)  /// ����ÿͷ��
    {
      int mi = finds(a[i].ci); /// �ҵ���¼������м��ŵ�boss
      if (sum[mi] + a[i].si <
          a[i].ni +
              1) /// �����ǰ������+��ʼͷ����С�������ٶ�+1��˵���޷����������Ĺ�����ĥ����Ҫ������ɱ������ô�ͼ�����ͷ���ĳ�ʼͷ������������ɱ��,����ȡ��ȡ������ν
        sum[mi] += a[i].si;
      else
        sum[mi] =
            sum[mi] > a[i].ni + 1
                ? sum[mi]
                : a[i].ni +
                      1; /// �������+��ʼͷ�������ͳ����������ٶȣ�˵���������ý�������������������ɱ����ȡ���еĽϴ�ֵ
    } /// ��Ϊsum[mi]ԭ��������ɱ����ͷ��֮ǰ�ı�Ҫ������������ˣ������ӵ���ͷ���������ٶ�+1��������������ˣ���Ҳ���ܼ���
    int ans = 0;
    for (int i = 1; i <= n; i++)
      if (city[i] = i)
        ans += sum[i]; /// ������ÿ�����м���֮��
    printf("%d\n", ans);
  }
}
