#include <algorithm>
#include <stdio.h>
using namespace std;
int main() {
  int n, a[1005];
  while (scanf("%d", &n) != EOF) // ������Ŀ
  {
    for (int i = 0; i < n; i++) // ���ӳ�����
    {
      scanf("%d", &a[i]);
    }
    sort(a, a + n); // ���򣬴�С����ĳ�����
    int max = 0;
    for (
        int i = 0; i < n;
        i++) // ��С������С�����ӣ����԰���������Խ�࣬����ǵ�ǰ�����������ӣ����ϴ��ڴ˳��������������ӵĸ���
    {
      a[i] = a[i] * (n - i);
      if (a[i] > max) {
        max = a[i]; // ȡ���ֵ
      }
    }
    printf("%d\n", max);
  }
  return 0;
}
