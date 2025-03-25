#include <algorithm>
#include <math.h>
#include <stdio.h>
using namespace std;
int n;
int a[201000];        /// ԭ���д洢
int dmin[201000][51]; /// ��Сֵ
int dmax[201000][51]; /// ���ֵ
void rmq_init() {
  for (int i = 1; i <= n; i++)
    dmin[i][0] = a[i], dmax[i][0] = a[i]; /// ��ʼ������ʵ��2^0������Ǳ���
  for (int j = 1; (1 << j) < n; j++)      /// ״̬ת��,2��j�η��ĳ���
  {
    for (int i = 0; i + (1 << j) - 1 <= n; i++) /// ��ʼλ��
    {
      dmin[i][j] = min(
          dmin[i][j - 1],
          dmin[i + (1 << (j - 1))]
              [j -
               1]); /// �ڵ�ǰ�����£���������һ�����ȵ��������䣬������������ȡһ����ֵ�̳�
      dmax[i][j] = max(dmax[i][j - 1], dmax[i + (1 << (j - 1))][j - 1]);
    }
  }
}
int rmq_min(int l, int r) {
  int k = log2(r - l + 1);
  return min(dmin[l][k], dmin[r - (1 << k) + 1][k]);
}

int rmq_max(int l, int r) {
  int k = log2(r - l + 1);
  return max(dmax[l][k], dmax[r - (1 << k) + 1][k]);
}
int main() {
  int q, i;
  while (scanf("%d%d", &n, &q) != EOF) {
    for (i = 1; i <= n; i++) {
      scanf("%d", &a[i]);
    }
    int x, y;
    rmq_init(); /// ����
    //        for(i=0;i<=n;i++)
    //        {
    //            for(int j=0;j<=n;j++)
    //            {
    //                printf("%d%c",dmin[i][j],j==n?'\n':' ');
    //            }
    //        }
    while (q--) {
      scanf("%d%d", &x, &y); /// �����������λ�ã��ǵü�һ
      printf("%d\n", rmq_max(x, y) - rmq_min(x, y));
    }
  }
  return 0;
}
