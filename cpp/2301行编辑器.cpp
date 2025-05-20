// #include<stdio.h>
// #include<string.h>
// int main()
//{
//     int t,n,i,j;
//     char
//     a[100005],b[100005];//遇到@换行，遇到#退格，因此可以倒着从字符串尾向前遍历
//     scanf("%d",&t);//当遇到@时，说明这之前的字符全部无效，这之后的字符才是有效的
//     while(t--)//将有效的字符串挪到另一个数组中，当遇到#时，遍历指针多向前挪两位，跳过被退格的字符和#字符
//     {
//         scanf("%s",a);//最后因为是倒序的，所以结果数组中也要倒叙输出
//         n=strlen(a);
//         j=0;
//         for(i=n-1;i>=0;i--)
//         {
//             if(a[i]=='@')
//             {
//                 break;
//             }
//             if(a[i]=='#')
//             {
//                 if(i-2>=0)
//                 {
//                     i=i-2;
//                 }
//                 else
//                 {
//                     break;
//                 }
//             }
//             b[j]=a[i];
//             j++;
//         }
//         for(i=j-1;i>=0;i--)
//         {
//             printf("%c",b[i]);
//         }
//         printf("\n");
//     }
//     return 0;
// }
#include <stdio.h>
#include <string.h>
int main() {
  char str[100005], str2[100005];
  int i, j, t, n;
  scanf("%d", &t);
  while (t--) {
    memset(str2, ' ', sizeof(str2));
    memset(str, ' ', sizeof(str));
    scanf("%s", str);
    n = strlen(str);
    j = 0;
    for (i = 0; i < n; i++) {
      if (str[i] == '@') {
        j = 0;
        continue;
      } else if (str[i] == '#') {
        j--;
        continue;
      } else {
        str2[j] = str[i];
      }
      j++;
    }
    str2[j] = '\0';
    printf("%s\n", str2);
  }
  return 0;
}
