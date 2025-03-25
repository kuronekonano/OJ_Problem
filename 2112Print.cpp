#include <stdio.h> ///这是一层一层覆盖，是比较麻烦的方法，用时也太多
int main() {
  int n, i, j, k, s;
  char a[365][365]; /// 数组大小记得是2*50-1，否则会re
  while (scanf("%d", &n) != EOF) {
    /// 想法是，先打出全面的最外层，然后在内层覆盖，一直覆盖n次，相当于把边界坐标缩小了
    for (i = 1; i <= n; i++) {
      for (
          j = i; j <= 2 * n - i;
          j++) /// 用英子的方法，将坐标四角缩小2*n-i能实现右边和下面的坐标相应缩小
      {
        for (k = i; k <= 2 * n - i; k++) /// 列
        {
          a[j][k] =
              (n - i) % 2 == 0
                  ? '*'
                  : '.'; /// 拿外层的第层来判断是‘.’还是‘*’ 最后判断奇偶就好
          //                    printf("j=%d k=%d s=%d\n",j,k,s);
        }
      }
    }
    for (i = 1; i <= 2 * n - 1; i++) /// 输出
    {
      for (j = 1; j <= 2 * n - 1; j++) {
        printf("%c", a[i][j]);
      }
      printf("\n");
    }
  }
  return 0;
}
// #include<bits/stdc++.h>
// using namespace std;
// int main()
//{
//     int n;
//     while(~scanf("%d",&n))
//     {
//         for(int i=1; i<=2*n-1; i++)///输出2*n-1行
//         {
//             for(int j=1; j<=2*n-1; j++)///2*n-1列
//             {
//                 int
//                 a=fabs(i-n);///处理i和j，做差求绝对值后，可得到各个坐标离中心点的距离，同时，这个距离也是层数数值越大，层数靠外
//                 int  b=fabs(j-n);///偶数层属于 . 奇数层属于 *
//                 ,但是，又因为，a与b计算的是与中心的距离，因此层数是从0开始的，所以偶数层0
//                 2 4就是(*)，奇数层1 3 5就是(.)
//                 if((a>b&&a%2!=0)||(a<b&&b%2!=0)||(a==b&&a%2!=0))///分为三种情况，作为三个位置判断(若a>b，是上三角和下三角部分，然后再判断当前行是奇还是偶，即可判断符号)
//                     printf(".");///第二种情况左三角和右三角，列距离大于行距离，然后判断当层数（此时竖着为判断b列）奇偶性，可以判断符号
//                 else
//                     printf("*");
//             }
//             printf("\n");
//         }
//     }
// }
