#include <algorithm>
#include <stdio.h> ///��̰��
using namespace std;
struct baby /// �����ļ�ֵ�����
{
  int pi, mi;
} a[108];
bool cmp(baby a, baby b) /// �ṹ�����򣬴Ӵ�С���Ӽ�ֵ��ߵĿ�ʼ��
{
  return a.pi > b.pi;
}
int main() {
  int v, m, i;
  while (scanf("%d", &v) != EOF) {
    if (v ==
        0) /// ��ĿҪ��v����0ʱ��������˱���һ��һ���жϣ�����������v��m֮�����ж��Ƿ����
      return 0;
    else
      scanf("%d", &m);
    for (i = 0; i < m; i++) {
      scanf("%d%d", &a[i].pi, &a[i].mi);
    }
    sort(a, a + m, cmp);
    int sum = 0;
    for (i = 0; i < m; i++) /// �Ӽ۸�ߵ���һ��һ������Ʒ
    {
      if (v > a[i].mi) /// ���ʣ�������װ��ǰ������Ʒ
      {
        sum = sum + a[i].pi * a[i].mi; /// ����ȥ����������ܼ�ֵ
        v -= a[i].mi;                  /// �����Ӧ����
      } else                           /// ���Ų�����
      {
        sum = sum + a[i].pi * v; /// ʣ�µ��ݻ�������װĿǰ�����Ʒ
        break;                   /// ����װ�������ˣ��˳�������Ʒѭ��
      }
    }
    printf("%d\n", sum); /// ����ܺ�
  }
  return 0;
}
