#include <algorithm>
#include <cstring>
#include <math.h>
#include <stdio.h>
using namespace std; // ѭ����1��ʼ������
int main() {
  int a, i, b, n;
  while (scanf("%d%d", &b, &n) != EOF) {
    if (b == 0 && n == 0) {
      return 0;
    }
    for (i = 1; i <= b; i++) {
      if (b - pow(i, n) == 0) // ��������0��i��n�η�Ϊb,iΪ����Aֵ
      {
        printf("%d\n", i);
        break;
      } else if (pow(i, n) < b && pow(i + 1, n) > b) {
        if (fabs(pow(i, n) - b) > fabs(pow(i + 1, n) - b)) {
          printf("%d\n", i + 1);
          break;
        } else {
          printf("%d\n", i);
          break;
        }
      }
    }
  }
  return 0;
}
