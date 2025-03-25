#include <stdio.h>
#include <string.h>
#define FOR(x)                                                                 \
  for (int x = -50; x <= 50;                                                   \
       x++) /// 自定义循环将整个x作为一个形参，放入已经定义好的FOR（）中
short int hashi
    [25000001]; /// 因此最大最小的数就是50^4=6250000，又因为是a1与a2，再乘2，又因为是带正负的相反数，再乘2=4*50^4
int main() {
  int a1, a2, a3, a4, a5;
  while (scanf("%d%d%d%d%d", &a1, &a2, &a3, &a4, &a5) !=
         EOF) /// a1~a5,x1~x5的范围都在-50~50内
  {
    memset(hashi, 0, sizeof(hashi));
    FOR(x1) /// x1和x2先找数，这里的x1相当于放入FOR（）自定义函数中的参数
    {
      if (x1) /// x1相当于i，是一直变化的数，用if是为了排除0
      {
        FOR(x2) {
          if (x2) {
            int sum =
                a1 * x1 * x1 * x1 +
                a2 * x2 * x2 * x2 *
                    (-1); /// 负数被移动到数组的高位计数，因为是找相反数，因此正数乘-1，负数当正数计数
            if (sum <
                0) /// 实际正数只到数组极限的1/2，实际就是求出x1+x2，然后对应相等于他们和的相反数的个数
            {
              sum = sum + 25000000;
            }
            hashi
                [sum]++; /// 此处x1+x2可能不止一对，因此到时加个数时，也是一一分配，遇到一个就加那么多对
          }
        }
      }
    }
    int flag = 0; /// 总个数计数器
    FOR(x3) {
      if (x3) {
        FOR(x4) {
          if (x4) {
            FOR(x5) {
              if (x5) {
                int sum = a3 * x3 * x3 * x3 + a4 * x4 * x4 * x4 +
                          a5 * x5 * x5 * x5; /// 求相等，这里不做计数，只做判断
                if (sum < 0) {
                  sum = sum + 25000000;
                }
                if (hashi[sum]) {
                  flag = flag + hashi[sum];
                }
              }
            }
          }
        }
      }
    }
    printf("%d\n", flag);
  }
  return 0;
}
