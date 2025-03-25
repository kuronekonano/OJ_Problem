#include <math.h>
#include <stdio.h>
#include <string.h>
char a[5000][5000];
int digui(int n, int x, int y, int h, int w) {
  if (n == 2) {
    a[x][y] = a[x - 1][y - 1] = a[x][y - 2] = '*';
    return 0;
  }
  int nh = pow(2, n - 2) / 2,
      nw = (pow(2, n - 1) - 1) / 2; /// 上一个三角形坐标，各点坐标
  digui(n - 1, x, y, nh, nw);       /// 右下角，以三角形右下角为标准点，分支扩展
  digui(n - 1, x, y - w - 1, nh, nw); /// 左下角
  digui(
      n - 1, x - h, y - w / 2 - 1, nh,
      nw); /// 上方///最右下角坐标
           /// 一只讲三点坐标投向下一个图形打印的函数中处理，直到找到每一个n=2时的坐标
} /*                      /  |  \                    */
int main() /*左边大图形 中间  右边大图形*/
{
  /*   / | \   /|\     / | \     */
  int n, x, y, stop, i, j;
  while (scanf("%d", &n) != EOF) {
    memset(a, ' ', sizeof(a));
    x = pow(2, n - 1);
    y = (pow(2, n)) - 1;
    int h = x / 2; /*小图形的高宽*/
    int w = y / 2;
    digui(n, x, y, h, w); /*函数处理*/

    for (i = 1; i <= x; i++) /*输出部分*/
    {
      for (j = 1; j <= pow(2, n) - 1; j++) // 正序输出
      {
        if (a[i][j] == '*')
          stop = j; // 防止后面的空格出现
      }
      for (j = 1; j <= stop; j++) // 在空格出现处停止输出
      {
        printf("%c", a[i][j]);
      }
      printf("\n");
    }
  }
  return 0;
}
// #include<stdio.h>
// #include<string.h>
// #include<math.h>
// #define N 5000
// char mp[N][N];
// void print(int n,int x,int y,int h,int w)
//{
/// 我使用的是每个三角形的右下角作为标准
/// 每个大图形由三个小图形组成，h和w就是小图形的高度和宽度
//
//    if(n == 2)
//    {
//        printf("标准(%d,%d)\n",x,y);
//        mp[x][y] = mp[x][y-2] = mp[x-1][y-1] = '*';//最右下角为标准点
//        return;
//    }
//    int nh = pow(2,n-2)/2,nw =
//    (pow(2,n-1)-1)/2;//nh表示上一个图形的高度计算方法，因此为n-1-1，nw为上一个小图形的宽度计算方法
//    /这是新图形的高和宽
//    print(n-1,x,y,nh,nw);///右下
//    print(n-1,x,y-w-1,nh,nw);///左下，宽度因为坐标有个空格所以-1减掉空格，-w减掉一半三角形位置
//    print(n-1,x-h,y-w/2-1,nh,nw);///上，高度减掉一半高度达到上面那个最大型的三角形右下角
//}
// int main()
//{
//    int n,stop=-1,j;
//    while(~scanf("%d",&n))
//    {
//        memset(mp,'0',sizeof(mp));//清空数组
//        int x = pow(2,n-1),y = pow(2,n)-1;//最右下角的点,X和Y代表高度和宽度
//        int h = x/2,w =
//        y/2;//h代表标准点坐标，也就是1/2的高度，w代表标准点坐标，也即是1/2宽度
//        print(n,x,y,h,w);//放入print函数中递归处理
//        for(int i = 1; i <= x; i++)
//        {
//            for(int j = 1; j <=pow(2,n)-1; j++)
//            ///这里是为了控制不输出多余的空格
//            {
//                if(mp[i][j]=='*')
//                    stop=j;
//            }
//            for(int j=1;j<=stop;j++)
//            {
//                printf("%c",mp[i][j]);
//            }
//            printf("\n");
//        }
//    }
//    return 0;
//}

#include <math.h>
#include <stdio.h> ///递归应用，打印三角形
#include <string.h>
char a[5000][5000];
int digui(int n, int x, int y, int h, int w) /// 递归函数
{
  if (n == 2) {
    a[x][y] = a[x - 1][y - 1] = a[x][y - 2] = '*';
    return 0;
  }
  int nh = pow(2, n - 2) / 2,
      nw = (pow(2, n - 1) - 1) / 2; /// 上一个三角形坐标，各点坐标
  digui(n - 1, x, y, nh, nw);       /// 右下角，以三角形右下角为标准点，分支扩展
  digui(n - 1, x, y - w - 1, nh, nw); /// 左下角
  digui(
      n - 1, x - h, y - w / 2 - 1, nh,
      nw); /// 上方///最右下角坐标
           /// 一只讲三点坐标投向下一个图形打印的函数中处理，直到找到每一个n=2时的坐标
} /*                      /  |  \                    */
int main() /*左边大图形 中间  右边大图形*/
{
  /*   / | \   /|\     / | \     */
  int n, x, y, stop, i, j;
  while (scanf("%d", &n) != EOF) {
    memset(a, ' ', sizeof(a));
    x = pow(2, n - 1);   /// 三角形最右下角的点的横坐标
    y = (pow(2, n)) - 1; /// 三角形
    int h = x / 2;       /// 高度     /*小图形的高宽*/

    int w = y / 2; /// 宽度

    digui(n, x, y, h, w); /*函数处理*/

    for (i = 1; i <= x; i++) /*输出部分*/
    {
      for (j = 1; j <= pow(2, n) - 1; j++) // 正序输出
      {
        if (a[i][j] == '*')
          stop = j; // 防止后面的空格出现
      }
      for (j = 1; j <= stop; j++) // 在空格出现处停止输出
      {
        printf("%c", a[i][j]);
      }
      printf("\n");
    }
  }
  return 0;
}
