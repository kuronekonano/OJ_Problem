#include <stack>
#include <stdio.h>
#include <string.h>
using namespace std;
char a[1000006];
int main() {
  int t, i;
  scanf("%d", &t);
  while (t--) {
    stack<char> q;
    while (!q.empty()) {
      q.pop();
    }
    scanf("%s", a);
    int n = strlen(a);
    int flag = 0;
    for (i = 0; i < n; i++) // �����ַ���
    {
      if (a[i] == '(') {
        q.push(a[i]); // ������������ջ
        continue;
      } else if (
          a[i] == ')' && !q.empty() &&
          q.top() ==
              '(') // �����������ҷǿգ���ջ��Ϊ������ʱ���������������໥ƥ�䣬��������һ
      {
        q.pop(); // ��ʹ��ǰ�����ų�ջ
        flag++;
      }
    }
    printf("%d\n", flag * 2); // ����ƥ��ɹ�ʱ�ַ��������Ƕ��ı���
  }
  return 0;
}
