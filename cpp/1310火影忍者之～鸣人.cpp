#include <algorithm>
#include <stdio.h> /// ��սṹ�����飺memset���ṹ���������ƣ�0��sizeof(�ṹ����������)��
#include <string.h>
using namespace std;
int m, n;
struct nijia {
  char message[503][103];
  int att, lea;
} fir[505];
bool cmp(nijia a, nijia b) {
  if (a.att == b.att) {
    if (a.lea == b.lea) {
      for (int i = 0; i < n; i++) /// ��ά�����ַ����Ƚ�
      {
        if (strcmp(a.message[i], b.message[i]) != 0) {
          return (strcmp(a.message[i], b.message[i]) <
                  0); /// �ֵ���������С��0��
        }
      }
    }
    return a.lea > b.lea; /// �Ӵ�С����ʱ���ں�
  }
  return a.att > b.att;
}
int main() {
  int k, i, j;
  while (scanf("%d%d%d", &m, &n, &k) != EOF) {
    for (i = 0; i < m; i++) {
      for (j = 0; j < n; j++) {
        scanf("%s", fir[i].message[j]);
      }
      scanf("%d%d", &fir[i].att, &fir[i].lea);
    }
    sort(fir, fir + m, cmp); /// �ṹ������
    for (i = 0; i < k; i++) {
      printf("%s\n", fir[i].message[0]);
    }
  }
  return 0;
}
