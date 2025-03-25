// #include<stdio.h>///递归路径记录
// int writedown[21][21][21];
// int w(int a,int b,int c)
//{
//     if(a<=0||b<=0||c<=0)
//     {
//         return 1;
//     }
//     if(writedown[a][b][c])
//     {
//         return writedown[a][b][c];
//     }
//     else if(a<b&&b<c)
//     {
//         return writedown[a][b][c]=w(a,b,c-1)+w(a,b-1,c-1)-w(a,b-1,c);
//     }
//     else
//     {
//         return
//         writedown[a][b][c]=w(a-1,b,c)+w(a-1,b-1,c)+w(a-1,b,c-1)-w(a-1,b-1,c-1);
//     }
//
// }
// int main()
//{
//     int x,y,z;
//     while(scanf("%d%d%d",&x,&y,&z)!=EOF)
//     {
//         if(x==-1&&y==-1&&z==-1)
//         {
//             return 0;
//         }
//         if(x<=0||y<=0||z<=0)
//         {
//             printf("w(%d, %d, %d) = 1\n",x,y,z);
//         }
//         else if(x>20||y>20||z>20)
//         {
//             printf("w(%d, %d, %d) = 1048576\n",x,y,z);
//         }
//         else
//         {
//             printf("w(%d, %d, %d) = %d\n",x,y,z,w(x,y,z));
//         }
//     }
//     return 0;
// }
#include <stdio.h> ///循环嵌套迭代（预处理）
int main() {
  int a[22][22][22];
  int i, j, k;
  for (i = 0; i <= 20; i++) {
    for (j = 0; j <= 20; j++) {
      for (k = 0; k <= 20; k++) {
        if (i == 0 || j == 0 || k == 0) {
          a[i][j][k] = 1;
          continue; /// 当有一个为0的时候，说明剩下的也可以跳过去了
        } else if (i < j && j < k) {
          a[i][j][k] = a[i][j][k - 1] + a[i][j - 1][k - 1] - a[i][j - 1][k];
        } else {
          a[i][j][k] = a[i - 1][j][k] + a[i - 1][j - 1][k] +
                       a[i - 1][j][k - 1] - a[i - 1][j - 1][k - 1];
        }
      }
    }
  }
  while (scanf("%d%d%d", &i, &j, &k) != EOF) {
    if (i == -1 && j == -1 && k == -1) {
      return 0;
    }
    if (i <= 0 || j <= 0 || k <= 0) /// 记住要处理完所有情况，比如小于0时
    {
      printf("w(%d, %d, %d) = %d\n", i, j, k, a[0][0][0]);
    } else if (i > 20 || j > 20 || k > 20) {
      printf("w(%d, %d, %d) = %d\n", i, j, k, a[20][20][20]);
    } else {
      printf("w(%d, %d, %d) = %d\n", i, j, k, a[i][j][k]);
    }
  }
  return 0;
}
