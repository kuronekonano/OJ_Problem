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
            1); /// 总船位数-船只数量+1(剩下的空船位都要打掉，并在此基础上多打一艘)
    int flag = 0;
    for (i = 0; i < n; i++) /// 这里用了取摸的方法过了！！！
    {
      sum++;             /// 0就计数
      if (str[i] == '1') /// 遇到1就清空计数，计数的0就是空出来的位置
      {
        sum = 0;
        continue; /// 最后错误，注意这几个步骤的先后顺序
      }
      if (sum % b == 0) /// 与船长取模
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
