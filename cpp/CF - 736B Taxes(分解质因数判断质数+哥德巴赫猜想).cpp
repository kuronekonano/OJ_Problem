#include <math.h>
#include <stdio.h>  ///判断素数的方法，就是从2一直到sqrt(n)判断取摸是否有为0
#include <string.h> ///可以不用素数筛，单个数判断素数
bool judge(
    long long
        n) /// 分3种情况，根据哥德巴赫猜想，一个不为2的偶数必能拆成两个素数之和，所以偶数n纳税都是2
{
  int x = n, i;
  for (
      i = 2; i <= sqrt(n);
      i++) /// 奇数分两种情况，一种就是素数，另一种是，奇数-2后是一个素数，此时可分成2+一个素数，纳税为2
  {
    while (x % i == 0) {
      return false; /// 第三种情况，奇数-2不为素数，此时奇数被分为3个素数相加，纳税为3
    }
  }
  return true;
}
int main() /// 题目要纳的税是收入n的最大因子(除去n)，并且可以把n分成不为1的很多份
{          /// 求纳税最小值
  int i, n;
  while (scanf("%d", &n) != EOF) /// 也就是当分成很多个素数时，纳税都是1
  {
    if (judge(n)) /// 若是质数。最大因子为1
    {
      printf("1\n");
      continue;
    }
    if (n % 2 == 0) /// 若是偶数，可分解为两个质数之和
      printf("2\n");
    else /// 非素数的奇数，有两种情况
    {
      if (judge(n - 2))
        printf("2\n");
      else
        printf("3\n");
    }
  }
}
// void zhiyinshu(int n)
//{
//     int x=n,i;
//     printf("%d=",n);
//     for(i=2;i<=sqrt(n);i++)
//     {
//         while(x%i==0)
//         {
//             if(x==i)
//                 break;
//             x/=i;
//             printf("%d*",i);
//         }
//     }
//     printf("%d\n",x);
// }
