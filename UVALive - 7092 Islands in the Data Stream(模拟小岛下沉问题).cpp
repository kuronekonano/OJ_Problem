#include <map>
#include <math.h>
#include <stdio.h> ///һ�����ߺ�ƽ�棬����û���½�أ�ÿ����û��Ϊһ�ֵ������
#include <string.h>
using namespace std;
int k, a[20], t;
bool check() /// �ж��Ƿ����е��춼����û
{
  for (int i = 2; i <= 11; i++) {
    if (a[i])
      return false;
  }
  return true;
}
int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &k);
    for (int i = 1; i <= 12; i++)
      scanf("%d", &a[i]);
    int sum = 0, num = 2;
    while (!check()) /// ͷβһ����0
    {
      int i = 2; /// ���ϴ�2������11
      while (i <= 11) {
        if (a[i] && a[i - 1] == 0) /// ֻҪ����0(����)
        {
          sum++;                 /// ��Ϊ���쿪ʼ����������
          int minn = 0x7fffffff; /// ��¼ÿ�����嵺����͵�
          int st = i;            /// ��¼���쿪ʼλ��
          while (a[i] != 0)      /// ����������
          {
            if (a[i] < minn)
              minn = a[i];
            i++;
          }
          for (int j = st; j <= i; j++)
            if (a[j])
              a[j] -= minn; /// �ر�����û��͵�
        }
        i++; /// Խ����ǰ�Ǻ����λ��
      }
    }
    printf("%d %d\n", k, sum);
  }
}
