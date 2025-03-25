#include <algorithm>
#include <stdio.h>
#define LL long long
using namespace std;
const LL MOD = 1e9 + 7;
LL poww(LL x, LL n) /// ������
{
  LL res = 1;
  while (n) {
    if (n & 1)
      res = res * x % MOD;
    x = x * x % MOD;
    n >>= 1;
  }
  return res;
}
/// �����ģ��
LL p[100005], f[100005]; /// pΪ�׳����飬fΪ�׳˵���Ԫ
void init()              /// Ԥ����
{
  p[0] = 1;
  for (int i = 1; i <= 100000; ++i) /// ����׳�
    p[i] = p[i - 1] * i % MOD;

  f[0] = 1;
  for (int i = 1; i <= 100000; ++i) /// ������Ԫ
    f[i] = poww(p[i], MOD - 2);
  return;
}
LL comb(int n, int m) /// ���������
{
  return (f[m] * f[n - m]) % MOD * p[n] % MOD;
} /// ����---->  n!
  /// ��ĸ---->  m!*(n-m)!   ������Ԫ����˵õ�C(n,m)�������
int main() {
  LL k, n;
  while (scanf("%lld%lld", &n, &k) != EOF) {
    LL ans = 1;
    LL sum = poww(2, n); ///  ������ܺͣ�����C(n,0)+C(n,1)+......+C(n,n)=2^n
    LL tmp = n;
    for (int i = 2; i <= k; i++) {
      ans = (ans + tmp) % MOD;
      //            printf("===%lld=====%lld\n",tmp,ans);
      tmp = ((tmp * (n - i + 1)) % MOD * poww(i, MOD - 2)) %
            MOD; /// ���Լ��������������*n-i+1,��ĸ*i
    }
    ans = (sum - ans + MOD) % MOD; /// ��������ȡģ������MOD�ٶ�MODȡģ
    printf("%lld\n", ans);
  } /// ��Ϊ��Ŀ�м���K��N(1e9)
    /// �����������ᳬʱ���������n��������ܺ�2^n��ȥ��0��k-1�������֮��(�϶̶�)���õ�����k��n�����֮��(�ϳ���)
}
// LL comb(LL n, LL m)///��һ��������󷨣���������б���������
//{
//     if(m > n) return 0;
//     LL ret = 1;
//     m = min(n - m, m);
//     for(int i = 1; i <= m; i ++)
//     {
//         LL a = (n + i - m) % MOD;
//         LL b = i % MOD;
//         ret = ret * (a * mod_pow(b, MOD - 2) % MOD) % MOD;
//     }
//     sum=(sum%MOD+ret%MOD)%MOD;
// }
//
// LL Lucas(LL n, LL m)
//{
//     if(m == 0) return 1;
//     return comb(n % MOD, m % MOD) * Lucas(n / MOD, m / MOD) % MOD;
// }
