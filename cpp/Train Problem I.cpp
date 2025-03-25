#include <stack>
#include <stdio.h> ///��¼·���Ľ���
#include <string.h>
using namespace std;

int main() {
  int n, i;
  char a[10], b[10];
  while (scanf("%d", &n) != EOF) {
    stack<char> q;
    while (!q.empty()) {
      q.pop();
    }
    scanf("%s", a); /// ���벿��  ��ջ˳��
    scanf("%s", b); /// ��ջ˳��
    int sum = 0;
    int j = 0, k = 0; /// k0ʱһ����in����out�����Ժ���++����
    bool flag[10];
    memset(flag, false, sizeof(flag));
    for (i = 0; i < n; i++) /// ������ջ�ַ���
    {
      q.push(a[i]); /// һ��һ���ַ���ջ����һ�������жϳ�����������������
      k++;          /// ���ڼ�¼·��������
      while (!q.empty() &&
             q.top() == b[j]) /// һֱ��ջ���Ƚϣ�ֱ���ҵ���ջ˳���е�����
      {
        q.pop();          /// �ܳ��ȳ�
        flag[k++] = true; /// ���TRUE�Ķ��ǿ��Գ�ջ�ģ�Ҳ����Out
        j++;              /// �����˳�ջ�����е�һ������������һ��
      }
    }
    if (j ==
        n) /// ��һ��ѭ�����������У�Ҳ����j��i��n����������ͬ��ֵ��˵����ջ����ȫ���ɳ���yes�������
    {
      printf("Yes.\n");
      for (i = 0; i < k; i++) /// �������
      {
        if (flag[i]) {
          printf("out\n");
        } else {
          printf("in\n");
        }
      }
    } else {
      printf("No.\n");
    }
    printf("FINISH\n");
  }
  return 0;
}
