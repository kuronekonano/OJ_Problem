#include <stdio.h>
int main() {
  int n, a, b, k, i, j;
  char str[200008];
  while (scanf("%d%d%d%d", &n, &a, &b, &k) != EOF) {
    scanf("%s", str);
    int sum = 0, ans = 0;
    for (i = 0; i < n; i++) {
      if (str[i] == '0') {
        sum++;
      } else {
        ans = ans + sum / b;
        sum = 0;
      }
    }
    ans += sum / b;
    sum = 0;
    printf(
        "%d\n",
        ans - a +
            1); /// �ܴ�λ��-��ֻ����+1(ʣ�µĿմ�λ��Ҫ��������ڴ˻����϶��һ��)
    int flag = 0;
    for (i = 0; i < n; i++) /// ��������ȡ���ķ������ˣ�����
    {
      sum++;             /// 0�ͼ���
      if (str[i] == '1') /// ����1����ռ�����������0���ǿճ�����λ��
      {
        sum = 0;
        continue; /// ������ע���⼸��������Ⱥ�˳��
      }
      if (sum % b == 0) /// �봬��ȡģ
      {
        flag++;
        printf("%d%c", i + 1, flag == ans - a + 1 ? '\n' : ' ');
        if (flag == ans - a + 1) {
          break;
        }
      }
    }
  }
}
