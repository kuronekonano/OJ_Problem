// #include<stdio.h>
// #include<string.h>
// int main()
//{
//     int n,m,j,i;
//     while(scanf("%d%d",&n,&m)!=EOF)//�ݹ��㷨�����뷽���С
//     {
//         if(m==0&&n==0)//ͬʱΪ��ʱ�����������Ϊ��ʱ���1���߷�
//         {
//             return 0;
//         }
//         int a[n+5][m+5];//�趨��ά���飬����ÿ�������ߵĲ���
//         memset(a,0,sizeof(a));//�������
//         for(i=1;i<=n+1;i++)//ѭ�������Ա����ж�ÿ������Ĳ�������
//         {
//             for(j=1;j<=m+1;j++)
//             {
//                 if(i==1||j==1)//�߽綼Ϊ1��
//                 {
//                     a[i][j]=1;
//                 }
//                 else
//                 {
//                     a[i][j]=a[i-1][j]+a[i][j-1];//�м䶼Ϊ�Ϸ���������������
//                 }
//             }
//         }
//         printf("%d\n",a[n+1][m+1]);//������һ������Ŀ�ĵصĲ�������
//     }
//     return 0;
// }
#include <iostream>
#include <stdio.h>
using namespace std;
int a[2005][1005];
int main() {
  int i, j;
  for (i = 1; i <= 2000; i++) /// Ԥ����
  {
    a[i][0] = 1; /// ��һ��ȫ��Ϊ1
  }
  for (i = 1; i <= 2000; i++) {
    for (j = 1; j <= i; j++) /// ������Ԥ����
    {
      if (i == j) /// ������������������Խ���ȫ���趨Ϊ1
      {
        a[i][j] = 1;
        continue;
      }
      a[i][j] = a[i - 1][j] + a[i - 1][j - 1];
      a[i][j] = a[i][j] % 1000000007;
    }
  }
  int m, n;
  while (cin >> m >> n) /// ����
  {
    if (m == 0 && n == 0)
      break;
    if (n < m)
      cout << a[m + n][n];
    else
      cout << a[m + n][m];
    cout << endl;
  }
  return 0;
}
