#include <stdio.h> //非常大范围的数列去重
#include <string.h>
int a[910305]; // 标记数组
int main() {
  int n, flag, i, j;
  while (scanf("%d", &n) != EOF) // n个数字
  {
    memset(a, 0, sizeof(a)); // 清空标记数组
    flag = 0;                // 总数计数器
    for (i = 0; i < n; i++)  // 循环输入
    {
      scanf("%d", &j);
      if (!a[j])
        flag++; // 若遇到一个数未被标记，则计数器加一
      a[j]++;   // 标记数组标记数字出现次数
    }
    printf("%d\n", flag); // 输出随机数个数
    bool one = false;     // 布尔型用于控制空格
    for (
        i = 0; i < 910306;
        i++) // 遍历标记数组，如遇到被标记的则输出那个数，因为标记只有是否两种情况不会出现重复，并且数组中各个元素是排好序的
    {
      if (a[i]) // 若发现了标记的元素，则输出
      {
        if (one == false) {
          printf("%d", i);
          one = true;
        } else
          printf(" %d", i);
      }
    }
    printf("\n");
  }
  return 0;
}
