#include <stdio.h>
int main() {
  int t, m, n;
  scanf("%d", &t);
  while (t--) {
    scanf("%d%d", &n, &m);
    int stx = (n + 1) / 2;
    int sty = stx;
    int floor = 0;
    int maxsize = 1;
    while (maxsize * maxsize < m) {
      maxsize += 2; /// 记得是奇数 ，每次加2不是特么加1
      floor++;
    }
    int minsize =
        (maxsize - 2) * (maxsize - 2); /// 最后错误，记得区分层数和当层最大值
    int line = (maxsize * maxsize - minsize) / 4;
    m = m - minsize;
    if (m <= line) {
      stx = stx - floor;
      sty = sty + floor;
      stx = stx + m;
    } else if (m <= line * 2) {
      stx = stx + floor;
      sty = sty + floor;
      sty = sty - (m - line);
    } else if (m <= line * 3) {
      stx = stx + floor;
      sty = sty - floor;
      stx = stx - (m - 2 * line);
    } else {
      stx = stx - floor;
      sty = sty - floor;
      sty = sty + (m - 3 * line);
    }
    printf("%d %d\n", stx, sty);
  }
  return 0;
}
// #include<stdio.h>
// int main()
//{
//     int tttt;
//     scanf("%d",&tttt);
//     while(tttt--)
//     {
//         int m,n;
//         scanf("%d%d",&m,&n);
//         int z_x=(m+1)/2;///设定坐标初始为方阵中心，也就是数字1
//         int z_y=z_x;
//        //printf("%d %d\n",z_x,z_y);
//         int z=1;
//         int flag=1;
//         int quan=0;///层数初始为0
//         while(z*z<n)///判断所选数字在第几圈位置，也是第几层
//         {
//             z+=2;
//             quan++;
//         }
//
//         int qu=(z*z-(z-2)*(z-2))/4;///所求元素所在那圈，每边的元素个数
//         int ji=(z-2)*(z-2);///上一层最后一个数
//       //printf("%d %d %d ",quan ,qu,ji);
//         //printf("n:%d qu:%d z:%d\n",n,qu,z);
//         n-=ji;///所求元素，离所在层数开始的那个数字的差值
//
//        if(n<=qu)///差值小于每边元素，则在右边区域
//        {
//            z_x-=quan;///先定格在那一层的右上角
//            z_y+=quan;
//            z_x+=(n);///再根据离当层第一个元素距离，微调坐标，也就是找到是那一层的第几个
//            printf("%d %d\n",z_x,z_y);
//        }
//        else if(n<=2*qu)///下方
//        {
//            z_x+=quan;///定格在那一层的右下角
//            z_y+=quan;
//            z_y-=(n-qu);
//            printf("%d %d\n",z_x,z_y);
//        }
//        else if(n<=3*qu)///左边
//        {
//           z_x+=quan;///左下角
//            z_y-=quan;
//            //printf("%d %d\n",z_x,z_y);
//            z_x-=(n-qu*2);
//            printf("%d %d\n",z_x,z_y);
//        }
//        else///上方
//        {
//            z_x-=quan;///左上角
//            z_y-=quan;
//            //printf("%d\n",quan);
//            z_y+=(n-qu*3);
//            printf("%d %d\n",z_x,z_y);
//        }
//     }
// }
