// #include<stdio.h>
// #include<string.h>
// int main()
//{
//     int n,m,j,i;
//     while(scanf("%d%d",&n,&m)!=EOF)//递归算法，输入方格大小
//     {
//         if(m==0&&n==0)//同时为零时则结束，单个为零时输出1种走法
//         {
//             return 0;
//         }
//         int a[n+5][m+5];//设定二维数组，保存每个坐标走的步数
//         memset(a,0,sizeof(a));//清空数组
//         for(i=1;i<=n+1;i++)//循环两次以遍历判断每个坐标的步骤数量
//         {
//             for(j=1;j<=m+1;j++)
//             {
//                 if(i==1||j==1)//边界都为1步
//                 {
//                     a[i][j]=1;
//                 }
//                 else
//                 {
//                     a[i][j]=a[i-1][j]+a[i][j-1];//中间都为上方坐标加上左方坐标和
//                 }
//             }
//         }
//         printf("%d\n",a[n+1][m+1]);//输出最后一个坐标目的地的步骤数和
//     }
//     return 0;
// }
#include <iostream>
#include <stdio.h>
using namespace std;
int a[2005][1005];
int main() {
  int i, j;
  for (i = 1; i <= 2000; i++) /// 预处理
  {
    a[i][0] = 1; /// 第一列全部为1
  }
  for (i = 1; i <= 2000; i++) {
    for (j = 1; j <= i; j++) /// 三角形预处理
    {
      if (i == j) /// 像是杨辉三角那样，对角线全部设定为1
      {
        a[i][j] = 1;
        continue;
      }
      a[i][j] = a[i - 1][j] + a[i - 1][j - 1];
      a[i][j] = a[i][j] % 1000000007;
    }
  }
  int m, n;
  while (cin >> m >> n) /// 输入
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
