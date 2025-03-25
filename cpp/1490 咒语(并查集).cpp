#include <stdio.h> ///����ĸ���ڵ㣬�Ե������ߣ���Ϊ���������ӵ��ʵ�����ĸ��ĩ��ĸ��һ�������ֱ���õ�������������ͬ��ĸ����
#include <string.h> ///���鼯
using namespace std;
int r[30], n;
char a[55];
int find(int a) {
  int tmp = a, t;
  while (tmp != r[tmp]) {
    t = tmp;
    tmp = r[tmp];
    r[t] = r[tmp];
  }
  return tmp;
}
void join(int x, int y) {
  int fa = find(x), fb = find(y);
  if (fa != fb) {
    r[fa] = fb;
  }
}
int main() {
  while (scanf("%d", &n) != EOF) {
    int num = 0;
    bool flag = false;
    for (int i = 1; i <= 26; i++)
      r[i] = i;
    for (int i = 1; i <= n; i++) {
      scanf("%s", a);
      int x = a[0] - 'a';
      int y = a[strlen(a) - 1] - 'a';
      join(x, y);
    }
    printf("%s\n", find('s' - 'a') == find('w' - 'a') ? "Yes" : "No");
  }
}
