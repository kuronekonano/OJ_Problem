#include <algorithm>
#include <stdio.h>
using namespace std;
int main() {
  int i, n, a[100005], j;
  while (scanf("%d", &n) != EOF) {
    for (i = 0; i < n; i++) {
      scanf("%d", &a[i]);
    }
    sort(a, a + n); // ������sort��ʱ���ס���㿪ʼ
    int flag;
    bool ent = false;
    for (i = 0; i < n; i++) {
      flag = 1;
      while (a[i] ==
             a[i + 1]) // ���������������ͬ��������������Ĺ��i�Զ��������
      {
        flag++;
        i++;
      }
      if (flag % 2 != 0 && ent == false) {
        printf("%d", a[i]);
        ent = true;
      } else if (flag % 2 != 0 && ent == true) {
        printf(" %d", a[i]);
      }
    }
    printf("\n");
  }
  return 0;
}
