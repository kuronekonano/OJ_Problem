#include <iostream>
#include <map> ///һһӳ��
#include <stdio.h>
#include <string>
using namespace std;
int main() {
  int n, t, i;
  map<string, string> q; /// �ַ�����string������char
  char stu[30], num[30];
  while (scanf("%d", &n) != EOF) {
    for (i = 1; i <= n; i++) {
      scanf("%s %s", stu, num);
      q[stu] = num; /// ������һ��ʹ��
    }
    scanf("%d", &t);
    while (t--) {
      scanf("%s", stu);
      cout << q[stu] << endl; /// ���������C++��
    }
  }
  return 0;
}
