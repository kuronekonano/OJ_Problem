#include <stdio.h> ///��n���ˣ���������������n-k�����Ŷ�λ�õ�������Ҳ������k��0�����Ŵ������
long long tC[1002][10], cP[25]; /// �������+���Ź�ʽ���
void init() {
  for (int i = 0; i <= 1000; i++) /// �����Ԥ����Ĳ���������
  {
    tC[i][0] = 1;
    for (int j = 1; j <= 4 && j < i; j++) {
      tC[i][j] = tC[i - 1][j - 1] + tC[i - 1][j];
    }
    tC[i][i] = 1;
  }
  cP[0] = 1; /// �����˶��ŶԵ����
  cP[1] = 0;
  cP[2] = 1;
  for (int i = 3; i <= 20; i++) {
    cP[i] = (i - 1) * (cP[i - 1] + cP[i - 2]); /// ���ŵ��ƹ�ʽ
  }
}
int main() {
  int n, k;
  init();
  while (scanf("%d%d", &n, &k) != EOF) {
    long long ans = 0;
    for (int i = k; i >= 0;
         i--) /// ����i==0ʱ�����(�����˶��Ŷ�ʱ)��Ϊ1�֣������Ͳ�����+1
    {
      ans += cP[i] * tC[n][i];
    }
    printf("%lld\n", ans);
  }
}
