#include <algorithm>
#include <stdio.h>
using namespace std;
int main() {
  int n, t, a[100005];
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
      scanf("%d", &a[i]);
    }
    int b = a[0];          /// b��¼��ǰȡ�õ����ֵ
    int big = a[0] - a[1]; /// big��¼��ǰ����ֵ
    for (
        int i = 1; i < n;
        i++) /// �ӵڶ�������ʼ������һֱ���������������Ǵ��Ѿ�ɨ����ֵ���ң����Բ�����ֺ��������ǰ����������
    {
      big = max(
          big,
          b - a[i]); /// ���õ�ǰɨ�������ֵ��ȥ����ɨ�ĺ����Ǹ�ֵ��������ȡ��ֵ
      b = max(b, a[i]); /// ��¼����ɨ�����������е����ֵ
    }
    printf("%d\n", big);
  }
  return 0;
}
