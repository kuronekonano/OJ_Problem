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
      maxsize += 2; /// �ǵ������� ��ÿ�μ�2������ô��1
      floor++;
    }
    int minsize =
        (maxsize - 2) * (maxsize - 2); /// �����󣬼ǵ����ֲ����͵������ֵ
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
//         int z_x=(m+1)/2;///�趨�����ʼΪ�������ģ�Ҳ��������1
//         int z_y=z_x;
//        //printf("%d %d\n",z_x,z_y);
//         int z=1;
//         int flag=1;
//         int quan=0;///������ʼΪ0
//         while(z*z<n)///�ж���ѡ�����ڵڼ�Ȧλ�ã�Ҳ�ǵڼ���
//         {
//             z+=2;
//             quan++;
//         }
//
//         int qu=(z*z-(z-2)*(z-2))/4;///����Ԫ��������Ȧ��ÿ�ߵ�Ԫ�ظ���
//         int ji=(z-2)*(z-2);///��һ�����һ����
//       //printf("%d %d %d ",quan ,qu,ji);
//         //printf("n:%d qu:%d z:%d\n",n,qu,z);
//         n-=ji;///����Ԫ�أ������ڲ�����ʼ���Ǹ����ֵĲ�ֵ
//
//        if(n<=qu)///��ֵС��ÿ��Ԫ�أ������ұ�����
//        {
//            z_x-=quan;///�ȶ�������һ������Ͻ�
//            z_y+=quan;
//            z_x+=(n);///�ٸ����뵱���һ��Ԫ�ؾ��룬΢�����꣬Ҳ�����ҵ�����һ��ĵڼ���
//            printf("%d %d\n",z_x,z_y);
//        }
//        else if(n<=2*qu)///�·�
//        {
//            z_x+=quan;///��������һ������½�
//            z_y+=quan;
//            z_y-=(n-qu);
//            printf("%d %d\n",z_x,z_y);
//        }
//        else if(n<=3*qu)///���
//        {
//           z_x+=quan;///���½�
//            z_y-=quan;
//            //printf("%d %d\n",z_x,z_y);
//            z_x-=(n-qu*2);
//            printf("%d %d\n",z_x,z_y);
//        }
//        else///�Ϸ�
//        {
//            z_x-=quan;///���Ͻ�
//            z_y-=quan;
//            //printf("%d\n",quan);
//            z_y+=(n-qu*3);
//            printf("%d %d\n",z_x,z_y);
//        }
//     }
// }
