#include <stdio.h>
#include <string.h>
char a[200005]; /// 主体活动串长度
char b[2005];   /// 入侵者活动串长度
int next[2008];
int lena, lenb;
void getnext() /// 预处理
{
  memset(next, 0, sizeof(next)); /// 计算next数组，初始全部为0
  int i = 0, j = next[0] = -1;   /// 模式串自己和自己比较
  while (i < lenb) /// i是一直增大的，这里也可以用for，其实相当于遍历一遍模式串
  {                /// 如果j为0，或成功匹配了字符
    while (j != -1 && b[i] != b[j])
      j = next[j];
    ++i, ++j;                             /// 匹配下一位
    next[i] = b[i] == b[j] ? next[j] : j; /// 同时给next数组的下一位赋值j的位置
  }
}
bool kmp() /// 主串与模式串相匹配
{
  int i = 0, j = 0;
  while (i < lena) {
    if (j == -1 || a[i] == b[j])
      i++, j++;
    else
      j = next[j];
    if (j == lenb)
      return true;
  }
  return false;
}
int main() {

  while (scanf("%s%s", a, b) != EOF) {
    lena = strlen(a);
    lenb = strlen(b);
    getnext(); /// 模式串预处理
    //        for(int i=0; i<=lenb; i++)
    //        {
    //            printf("%d->%d\n",i,next[i]);///next数组
    //        }
    printf("%s\n", kmp() ? "yes" : "no");
  }
  return 0;
}
// #include<stdio.h>
// #include<string.h>
// char a[200005];///主体活动串长度
// char b[2005];///入侵者活动串长度
// int next[2008];
// int lena,lenb;
// void getnext()///预处理
//{
//     memset(next,0,sizeof(next));///计算next数组，初始全部为0
//     for(int i=1; i<lenb;
//     i++)///遍历一遍模式串，此时计算next数组相当于自己和自己匹配
//     {///i是一直增长的，j是计算的next值
//         int
//         j=next[i];///每次将当位(i)的next值赋给j，如果j不为0，那么可以继续增加j的长度，如果j为0，说明上一位i没有什么最长前后缀，还得从目前遍历的第i位开始查找最长前后缀
//         while(j&&b[i]!=b[j])///如果j不为0，说明最长前后缀计数有一定长度，但是当j+1位
//         {
//             j=next[j];
//         }
//         next[i+1]=(b[i]==b[j])?(j+1):0;///如果第i和j位字符匹配，那么在i+1的位置就是这之前的最长公共前缀，如果不匹配，前缀后缀长度就为0
//     }///此时是一个递推的过程
// }
// bool kmp()///主串与模式串相匹配
//{
//     int j=0;///模式串在不停移动，以next数组为标准做后退的移动
//     for(int i=0; i<lena; i++)///遍历主串，i值是一直增长的
//     {
//         while(j&&a[i]!=b[j])///j!=0(模式串匹配到前后缀的某个位置了)且两串出现字符匹配失败时
//         {
//             j=next[j];///将模式串按next数组后移，移动到第next[j]位(因为是到j位不匹配的，所以应该从上一个和j相同的前缀处再比较)
//         }
//         if(a[i]==b[j])///如果匹配了，j和i同时后移比较下一位
//         {
//             j++;
//         }
//         if(j>=lenb)///模式串匹配完成，确认主串包含模式串可以返回
//            return true;
//     }
//     return
//     false;///如果遍历完了整个主串，模式串指针j仍未达到模式串的长度，说明不匹配，返回
//     匹配失败
// }
// int main()
//{
//
//     while(scanf("%s%s",a,b)!=EOF)
//     {
//         lena=strlen(a);
//         lenb=strlen(b);
//         getnext();///模式串预处理
////        for(int i=0; i<=lenb; i++)
////        {
////            printf("%d->%d\n",i,next[i]);///next数组
////        }
//        printf("%s\n",kmp()?"yes":"no");
//    }
//    return 0;
//}
