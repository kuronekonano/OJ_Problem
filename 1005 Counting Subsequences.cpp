#include <map> ///��map��Ӧ���ִ�����Ҳ������Ϳɵ����λ���Ƿ����
#include <stdio.h>
using namespace std;
int main() {
  int n, i, t, temp, sum;
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    map<int, int> m;
    int flag = 0;
    sum = 0;
    m[0] = 1; /// ��һ�������ܺ���0��
    for (i = 0; i < n; i++) {
      scanf("%d", &temp);
      sum += temp;
      m[sum]++;
      flag += m
          [sum -
           47]; /// ���ִ������Ǹ��ܺͳ����˼��Σ����м��������У�Ҳ���ǿ��Ե����λ��
    }
    printf("%d\n", flag);
  }
}
