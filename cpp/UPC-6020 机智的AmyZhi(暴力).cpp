#include <stdio.h> ///������һ��n����һ����С��mʹ��m����m��ÿһ��λ�ϵ�ֵ�������n
#define LL                                                                     \
  long long /// ��Ϊ�����ϵ�ֵ���ᳬ����ǰλ��*9�����ֻ�ñ�����ξ��뼴��
int main() {
  int t;
  LL n;
  scanf("%d", &t);
  while (t--) {
    scanf("%lld", &n);
    LL tmp = n;
    int len = 0;
    while (tmp) {
      tmp /= 10;
      len++;
    }
    int sub = len * 9;
    bool flag = false;
    for (LL i = n - sub; i < n; i++) {
      tmp = i;
      LL sum = 0;
      while (tmp) {
        sum += tmp % 10;
        tmp /= 10;
      }
      //            printf("%lld -----> %lld\n",i,sum+i);
      if (sum + i == n) {
        printf("%lld\n", i);
        flag = true;
        break;
      }
    }
    if (!flag)
      printf("Stupid SiriusRen\n");
  }
}
