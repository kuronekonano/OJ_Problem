#include <stack>
#include <stdio.h> ///ջ�����ж�СӦ��
using namespace std;
int main() {
  int n, i, a[55];
  while (scanf("%d", &n) != EOF) {
    stack<int> q;
    while (!q.empty()) /// ���ջ
    {
      q.pop();
    }
    for (i = 0; i < n; i++) /// ����
    {
      scanf("%d", &a[i]);
    }
    int j = 0;
    for (i = 1; i <= n; i++) /// �жϽ����Ƿ�����ѭ��
    {
      q.push(i);
      while (!q.empty() && q.top() == a[j]) {
        q.pop();
        j++;
      }
    }
    if (j == n) {
      printf("Yes\n");
    } else {
      printf("No\n");
    }
  }
  return 0;
}
