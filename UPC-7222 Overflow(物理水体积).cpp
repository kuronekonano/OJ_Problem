#include <bits/stdc++.h> ///���ڵ���ˮ�ܶȵ�ֱ����ȫ��ûˮ��
#define LL                                                                     \
  long long /// ��������������������ſ�ˮ��������ͬʱˮ���ܶ���1�������ſ�ˮ�����
#define M(a, b)                                                                \
  memset(a, b, sizeof a) /// ֱ�Ӽ���ˮ���ӵ���������Ƚ�һ���Ƿ񳬹�Ͱ�߶ȼ���
#define pb(x) push_back(x)
using namespace std;
const int maxn = 1008;
int t, n;
int main() {
  double s, h, v, l, p;
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    double sum = 0;
    for (int i = 1; i <= n; i++) {
      scanf("%lf%lf", &l, &p);
      if (p >= 1.0)
        sum += l * l * l;
      else
        sum += l * l * l * p;
    }
    scanf("%lf%lf%lf", &s, &h, &v);
    sum += v;
    sum /= s;
    printf("%.2f\n", sum < h ? sum : h);
  }
}
