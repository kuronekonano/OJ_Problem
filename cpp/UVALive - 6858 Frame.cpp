#include <algorithm>
#include <stdio.h>
using namespace std;
int main() {
  int x, y, n, a;
  while (scanf("%d%d", &x, &y) != EOF) {
    scanf("%d", &n);
    while (n--) {
      bool ans = false;
      scanf("%d", &a);
      if (y % a == 0 && (x - 2) % a == 0)
        ans = true; /// �������������������䣬�̱�Ҳ������
      if (y % a == 1 && ((x - 1) % a == 0 || (x - 2) % a == 0 && x % a == 0))
        ans = true; /// ���߶��1��������̱���������̱�-2�Ͷ̱�ͬʱ������
      if (y % a == 2 && (x % a == 0))
        ans = true; /// ����-2�������̱���������
      swap(x, y);
      if (y % a == 0 && (x - 2) % a == 0)
        ans = true;
      if (y % a == 1 && ((x - 1) % a == 0 || (x - 2) % a == 0 && x % a == 0))
        ans = true;
      if (y % a == 2 && (x % a == 0))
        ans = true;
      printf("%s\n", ans ? "YES" : "NO");
    }
  }
}
