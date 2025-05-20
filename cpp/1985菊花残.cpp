#include <stdio.h>
#include <stdlib.h>
int main() {
  char a[12];
  long x;
  while (~scanf("%s", a)) {
    x = strtol(
        a, NULL,
        13); // 因为字符串A中的字符，在传参之前就已经被后面的base进制识别了，所以即使是16进制或13进制有存在字母的他也能读取，若是大于进制的非
    if (x % 13 == 0) // 数字，他将不读取
    {
      printf("YES\n");
    } else
      printf("NO\n");
  }
  return 0;
}
/// 1 函数名：
///  strtol
/// 2 声明：
/// long int strtol(const char *nptr,char **endptr,int base);
/// 3 功能：
/// 将参数nptr字符串根据参数base来转换成长整型数。
/// 4 说明：
/// 参数base范围从2至36，或0。参数base代表采用的进制方式，如base值为10则采用10进制，若base值为16则采用16进制等。当base值为0时则是采用10
/// 进制做转换，但遇到如’0x’前置字符则会使用16进制做转换、遇到’0’前置字符而不是’0x’的时候会使用8进制做转换。一开始strtol()会扫描参数nptr
/// 字符串，跳过前面的空格字符，直到遇上数字或正负符号才开始做转换，再遇到非数字或字符串结束时('\0')结束转换，并将结果返回。若参数endptr
/// 不为NULL，则会将遇到不合条件而终止的nptr中的字符指针由endptr返回；若参数endptr为NULL，则会不返回非法字符串。
