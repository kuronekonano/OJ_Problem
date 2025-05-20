#include <math.h>
#include <stdio.h>
#include <string.h>
char kuro[5000][5000];        // 定义足够大的字符型数组
int nano(int n, int x, int y) // 用于计算并递归坐标值的自定义函数
{
  if (n == 0) // 当n=0存取那个坐标的值为字符C
  {
    kuro[y][x] = 'C'; // 每个坐标被赋值为字符C
    return 0;
  } else { // 这里计算的是每个C的坐标，计算的值不是一个Cn的坐标，而是所有Cn的某个位置的坐标，比如C2中就计算所有C1中右下角的C的坐标
    int zb = pow(
        3,
        n - 1); // 此处用上了上一个图形中点的坐标，其中的差值正好是每个相同位置C字符相差位置的距离
    nano(
        n - 1, x,
        y); // 并且这里注意，每次3多n+1次方数值，不是整个图形的面积，而是上一个图形边长的面积，如C3边长是27，C2图形边长便是9，C3面积为27*27
    nano(
        n - 1, x,
        y - 2 * zb); // 因此这里刚好减去加上的是等比例的各个小图形的间距，单个C和坐标，得出的是一个简单的大图形，且是每个小图形的一部分
    nano(n - 1, x - zb, y);
    nano(n - 1, x - zb, y - 2 * zb); // 五个C的位置坐标
    nano(n - 1, x - 2 * zb, y - zb);
  }
}
int main() {
  int n, i, j, t;
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    memset(kuro, ' ', sizeof(kuro));
    int zb = pow(
        3,
        n); // 选取最好算的点的坐标，此时坐标和n的关系，最直接的便是n的3次方位最右下角的点的坐标
    nano(n, zb, zb);
    for (i = 1; i <= zb; i++) // 输出部分
    {
      int stop;
      for (j = 1; j <= zb; j++) {
        if (kuro[i][j] == 'C')
          stop = j;
      }
      for (j = 1; j <= stop; j++) {
        printf("%c", kuro[i][j]);
      }
      printf("\n");
    }
  }
  return 0;
}
