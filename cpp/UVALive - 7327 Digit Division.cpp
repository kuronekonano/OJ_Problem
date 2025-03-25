#include <math.h> ///����ָ��������mod1e9+7,���ڷָ�����������ȷֳ���С�����ܱ�m������������Ϊ����С�ָ�
#include <stdio.h> ///����һ�����У���������зָ�����������У�ʹ��ÿ����������Ϊһ��ʮ�������ܱ�m����
#include <string.h> ///��˲����ڽ��ָ��п�����һ�ηָ�ϳ�һ���µı�m���������������������ʹǰ��ηָ���һ��������������
const int mod = 1e9 + 7; /// �õ���С�ָ����������֮�󣬽���������ںϲ���
long long poww(
    long long
        b) /// ��ĳ�����Ա���������Ϊm*k1,��һ��Ϊm*k2����m*k1*10^n�����m*k2,�ṫ��ʽ������������m����˺ϲ�֮���Ǳ�m��������
{ /// ���ںϲ���������ÿ���ǵ����������п��ɱ�����ָsum�������о���sum-1�����壬ÿ��������벻�������γ�һ���µ������У�Ҳ����2^(sum-1)������
  long long ans = 1, tmp = 2;
  while (b != 0) {
    if (b & 1)
      ans = ((ans % mod) * (tmp % mod)) % mod;
    tmp = ((tmp % mod) * (tmp % mod)) % mod;
    b /= 2;
  }
  return ans;
}
int main() {
  long long n, m;
  char a[300008];
  while (scanf("%lld%lld", &n, &m) != EOF) {
    bool flag = false;
    memset(a, 0, sizeof(a));
    scanf("%s", a);
    int sum = 0, num = 0;
    for (int i = 0; i < n; i++) {
      num = num * 10 + a[i] - '0';
      ;
      if (num % m == 0) {
        sum++;
        num = 0;
      } else
        num %= m;
      if (i == n - 1 && num != 0)
        flag =
            true; /// ���������һ���������һ�����������޷���m��������ô����������ǲ��ɺϲ��ģ���������ֱ��Ϊ0
    }
    if (flag) {
      printf("0\n");
      continue;
    } else {
      long long ans = poww(sum - 1);
      printf("%lld\n", ans);
    }
  }
}
