#include <algorithm>
#include <stdio.h>
#include <string.h>
using namespace std;
int main() {
  char kuro[105]; // 定义两个字符型数组用于存储输入的两串字符
  char neko[105];
  int ro[33] = {0}, n; // 定义两个两个整型数组用于存储两个字符串的字母出现频率
  int ko[33] = {0}, i;
  scanf("%s%s", kuro, neko);
  n = strlen(kuro); // 计算字符串长度
  for (i = 0; i < n; i++) {
    ro[kuro[i] -
       65]++; /*a[0]表示数组中的第一个值，可以把它看成一个变量x,a[0]++*/
    ko[neko[i] -
       65]++; /*a[0]++也就是数组中第一个值+1再存放到原位。比如 int a[2];
                 其中a[0]=1; a[1]=5;  a[0]++以后，a[0]的值变为2；*/
  } // 此处为将每个字母的出现次数计入到相应字符串的整型数组中
  sort(ro, ro + 26); // 按出现频率大小排序数组
  sort(ko, ko + 26);
  for (
      i = 0; i < 26;
      i++) // 逐个比较两个排序后数组的每一项，若26个字母中存在替换，则无论哪个字母被替换，他们的出现频率都应该一样
  {
    if (ro[i] != ko[i]) {
      printf("NO\n"); // 若不一样则不是加密的
      return 0;
    }
  }
  printf("YES\n");
  return 0;
}
