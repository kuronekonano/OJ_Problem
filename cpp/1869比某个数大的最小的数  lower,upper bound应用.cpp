#include <algorithm> ///���뺯����ͷ�ļ�
#include <stdio.h>
using namespace std;
int main() {
  int n, a[105], i;
  while (scanf("%d", &n) != EOF) {
    for (i = 0; i < n; i++) {
      scanf("%d", &a[i]);
    }
    sort(a, a + n); /// upper��lowerֻ��������������ʹ��
    int t;
    scanf(
        "%d",
        &t); /// ע����뺯����ʹ�÷�������һ�������������׵�ַ����Ȼ�����������е�ĳ����Χ����a+n,�����Ҫ�������
    while (
        t--) /// ���棡����ԭ�������ص���һ����ַ��������������׵�ַa������һ����ʾλ�õ�ֵ������
    {
      int flag;
      scanf("%d", &flag); /// �����������������������������е���
      int inside =
          upper_bound(a, a + n, flag) - a; /// ����������뵽����õ�������
      if (inside >=
          n) /// ��������λ������������һλ����ô˵��û�б����������
      {
        printf("Orz\n");
      } else {
        printf(
            "%d\n",
            a[inside]); /// ����ֱ��������������Ǹ�λ�þͺã���Ϊ�Ǹ�λ�þ��Ǳ��������С����
      }
    }
  }
  return 0;
}
