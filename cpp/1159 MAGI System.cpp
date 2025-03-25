// #include <stdio.h>///大数乘法
// #include<string.h>
// int main()
//{
//     char a[1005];///字符串a
//     char b[1005];///字符串b
//     int na[1005];///a乘数
//     int nb[1005];///b乘数
//     int nc[1005];///结果
//     while(~scanf("%s%s",a,b))
//     {
//         if(a[0]=='0'||b[0]=='0')///输入两数任一为0则的得数肯定为0，此外因为第0位是最高位，因此最高位为0则肯定为0
//         {
//             printf("0\n");
//             continue;
//         }
//         memset(na,0,sizeof(na));///清空三个数字存储数组
//         memset(nb,0,sizeof(nb));
//         memset(nc,0,sizeof(nc));
//         int
//         la=strlen(a);///统计长度，其中，最高位在数组的0位置，个位在la-1的位置
//         int lb=strlen(b);
//         int
//         cnt=0;///注意这里，因为字符数组是从最后一位开始读入的，而数字数组是从0位开始存的，所以赋值过去时是两个单独的计数，必须分开
//         for(int i=la-1; i>=0; i--)///从个位开始（第0位）放入整型数组中
//             na[cnt++]=a[i]-'0';
//         int snt=0;
//         for(int i=lb-1; i>=0; i--)
//             nb[snt++]=b[i]-'0';
//         for(int i=0; i<cnt; i++)///计算部分
//         {
//             for(int j=0; j<snt; j++)
//             {
//                 nc[i+j]+=na[i]*nb[j];///用循环嵌套实现两个字符串每一位的对应相乘
//             }///结果位数是两个数的位数之和
//         }///相乘并相加存到每位数里的数是未进位的
//         for(int i=0; i<(cnt+snt); i++)///进位循环
//         {
//             if(nc[i]>=10)///大于10进位
//             {
//                 int tmp=nc[i]/10;///tmp临时存储进位数
//                 nc[i]=nc[i]%10;///nc结果数组每位存储当位小于10的模
//                 nc[i+1]+=tmp;///下一位进tmp
//             }
//         }///计算部分结束
//         ///输出部分
//         for(int i=1004; nc[i]==0;
//         i--)///倒着从数组最后一位找，循环条件是只要这一位是空的（为0）就继续下去
//         {///当找到i位的下一位不为零！就说明从下一位开始输出这串数字
//             if(nc[i-1]!=0)///从最高位输出，也就是nc结果数组的存储的最后的那个位置
//             {
//                 for(int j=i-1; j>=0;
//                 j--)///新循环，从数组的下一位一直输出到0位（个位）
//                     printf("%d",nc[j]);///每位输出
//                 break;///此时输出完了，因为上面的输出循环用的是j来代表位数，所以i不动，跳出寻找从哪一位开始输出的第一个循环
//             }
//         }
//         printf("\n");
//     }///这个大数乘法优雅而美观
// }
#include <stdio.h>
#include <string.h>
int main() {
  char a[1004];
  char b[1004];
  int numa[1004];
  int numb[1004];
  int numc[1004];
  int i, j;
  while (scanf("%s %s", a, b) != EOF) {
    if (a[0] == '0' || b[0] == '0') {
      printf("0\n");
      continue;
    }
    memset(numa, 0, sizeof(numa));
    memset(numb, 0, sizeof(numb));
    memset(numc, 0, sizeof(numc));
    int na = strlen(a);
    int nb = strlen(b);
    int ant = 0;
    for (i = na - 1; i >= 0; i--) {
      numa[ant++] = a[i] - '0';
    }
    int bnt = 0;
    for (i = nb - 1; i >= 0; i--) {
      numb[bnt++] = b[i] - '0';
    }
    for (i = 0; i < ant; i++) {
      for (j = 0; j < bnt; j++) {
        numc[i + j] = numc[i + j] + numa[i] * numb[j];
      }
    }
    for (i = 0; i < (ant + bnt); i++) {
      if (numc[i] >= 10) {
        int tmp = numc[i] / 10;
        numc[i] = numc[i] % 10;
        numc[i + 1] = numc[i + 1] + tmp;
      }
    }
    for (i = 1003; numc[i] == 0; i--) {
      if (numc[i - 1] != 0) {
        for (j = i - 1; j >= 0; j--) {
          printf("%d", numc[j]);
        }
        break;
      }
    }
    printf("\n");
  }
  return 0;
}
