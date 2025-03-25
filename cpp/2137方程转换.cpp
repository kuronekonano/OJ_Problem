#include <stdio.h>
int main() {
  int t;
  char b[10] = {'m', 'n', 'p', 'i', 'j', 'k'};
  scanf("%d", &t);
  while (t--) {
    long a[10];
    for (int i = 0; i < 7; i++) {
      scanf("%ld", &a[i]);
    }
    bool flag = false;
    for (int i = 0; i <= 6; i++) {
      if (flag && a[i] > 0)
        printf("+"); /// 注意符号要单独输出，如果是符号就不输出正号
      if (a[i] != 0 && i != 6) {
        if (a[i] == 1) /// 坑点:注意系数为1时没有数字只有字母
        {
          printf("%c", b[i]);
        } else if (a[i] == -1)
          printf("-%c", b[i]); /// 同时要注意负数也是如此
        else
          printf("%ld%c", a[i],
                 b[i]); /// 如果不是1的系数，那就数字和字母一起输出
        flag = true;    /// 这个标记是标记有没有不为0的数的
      }
      if (a[i] != 0 && i == 6) /// 最后一个常数单独输出和判断
      {
        printf("%ld", a[i]);
        flag = true;
      }
    }
    if (!flag)
      printf("0");
    printf("\n");
  }
  return 0;
}

// #include<cstdio>
// char c[9]= {'m','n','p','i','j','k'};
// int main()
//{
//     int k=0,p,a[9],q=0;
//     scanf("%*d");
//     while(~scanf("%d",&a[p=k++%7]))
//     {
//         if((a[p]==1||a[p]==-1)&&p<6)printf(a[p]>0?q?"+%c":"%c":"-%c",c[p]);
//         else printf(a[p]?q?p>5?"%+d":"%+d%c":p>5?"%d":"%d%c":"",a[p],c[p]);
//         if(a[p])q=1;
//         if(p>5)printf(a[0]||a[1]||a[2]||a[3]||a[4]||a[5]||a[6]?"\n":"0\n"),q=0;
//     }
// }
