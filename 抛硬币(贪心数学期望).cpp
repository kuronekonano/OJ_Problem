#include <algorithm>
#include <stdio.h>
using namespace std;
bool cmp(double a, double b) /// ���μǵ��Ǹ�����
{
  return a > b; /// �Ӵ�С����
}
int main() {
  int n, m, i, j;
  double a[100][100];
  while (scanf("%d%d", &n, &m) != EOF) {
    if (n == 0 && m == 0)
      break; /// ��Ϊ0ʱ�˳�
    for (i = 0; i < n; i++) {
      for (j = 0; j < m; j++) {
        scanf("%lf",
              &a[j][i]); /// ���룬���б���У��б�������룬��������sortÿһ��
      }
    }
    double sum = 0; /// ��ʼ�����(��ѧ����)
    for (i = 0; i < m; i++) {
      sort(a[i], a[i] + n,
           cmp); /// ��ÿһ��������ôÿһ�е�Ԫ�ض�����һ�е����ֵ
    }
    for (i = 0; i < n; i++) /// ���
    {

      double tmp = 1.0;
      for (j = 0; j < m; j++) {
        tmp *= a[j][i]; /// ÿһ��(��)�ĸ������
      }
      sum += tmp; /// ���
    }
    //        for(i=0; i<m; i++)
    //        {
    //            for(j=0; j<m; j++)
    //            {
    //                printf(" %f",a[i][j]);
    //            }
    //            printf("\n");
    //        }
    printf("%.4f\n", sum); /// ��ѧ���������ֵ
  }
  return 0;
}
