#include <stdio.h> ///�ӽ�С������ʼ�׳ˣ���1���£���2���£���3���£�ֱ����ĳ����i���³˵�jʱ����n��
int main() {
  int i, j, cas = 1;
  long long n;
  while (scanf("%lld", &n) != EOF) {
    if (n == 1) {
      printf("Case %d: Impossible\n", cas++); /// 1��Ψһһ������
      continue;
    }
    bool flag = false;
    for (i = 1; i <= 35000; i++) {
      long long sum = 1;
      for (j = i; j >= 2; j--) {
        sum *= j;
        if (sum == n) {
          flag = true;
          j--;
          break;
        }
        if (sum > n)
          break;
      }
      if (flag)
        break;
    }
    if (flag) {
      printf("Case %d: %d %d\n", cas++, i, j);
    } else {
      printf(
          "Case %d: %lld %lld\n", cas++, n,
          n - 1); /// ��û���κ�һ��������ʱ�����������������ʱ����n/n-1�Ľ׳˷���nֵ
    }
  }
  return 0;
}
