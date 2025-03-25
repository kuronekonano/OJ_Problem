#include <stdio.h>
#include <string.h>
#define LL long long
using namespace std;
const int mod = 1000000007;
struct matrix {
  LL mat[2][2];
};
LL n, m;
matrix mul(matrix a, matrix b) {
  matrix ans;
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      ans.mat[i][j] = 0;
      for (int k = 0; k < 2; k++) {
        LL tmp = a.mat[i][k] * b.mat[k][j] % mod;
        ans.mat[i][j] = (ans.mat[i][j] + tmp) % mod;
      }
    }
  }
  return ans;
}
matrix poww(matrix a, LL b) {
  matrix ans = a;
  b--;
  while (b) {
    if (b & 1)
      ans = mul(ans, a);
    a = mul(a, a);
    b >>= 1;
  }
  return ans;
}
int main() {
  while (scanf("%I64d%I64d", &n, &m) != EOF) {
    matrix ma;
    if (m == 1) {
      printf("%I64d\n", n % mod);
      continue;
    }
    if (m == 2) {
      printf("%I64d\n", n * (n - 1) % mod);
      continue;
    }
    if (m == 3) {
      printf("%I64d\n", n * (n - 1) * (n - 2) % mod);
      continue;
    }
    ma.mat[1][0] = n - 1;
    ma.mat[0][0] = n - 2;
    ma.mat[0][1] = 1;
    ma.mat[1][1] = 0;
    matrix ans = poww(ma, m - 3);
    matrix tmp;
    tmp.mat[0][1] = n * (n - 1);
    tmp.mat[0][0] = n * (n - 1) * (n - 2);
    tmp.mat[1][0] = ma.mat[1][1] = 0;
    ans = mul(tmp, ans);
    printf("%I64d\n", ans.mat[0][0] % mod);
  }
}
