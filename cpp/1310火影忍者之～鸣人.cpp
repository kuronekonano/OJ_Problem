#include <algorithm>
#include <stdio.h> /// 清空结构体数组：memset（结构体数组名称，0，sizeof(结构体数组名称)）
#include <string.h>
using namespace std;
int m, n;
struct nijia {
  char message[503][103];
  int att, lea;
} fir[505];
bool cmp(nijia a, nijia b) {
  if (a.att == b.att) {
    if (a.lea == b.lea) {
      for (int i = 0; i < n; i++) /// 二维数组字符串比较
      {
        if (strcmp(a.message[i], b.message[i]) != 0) {
          return (strcmp(a.message[i], b.message[i]) <
                  0); /// 字典序排序是小于0的
        }
      }
    }
    return a.lea > b.lea; /// 从大到小排序时大于号
  }
  return a.att > b.att;
}
int main() {
  int k, i, j;
  while (scanf("%d%d%d", &m, &n, &k) != EOF) {
    for (i = 0; i < m; i++) {
      for (j = 0; j < n; j++) {
        scanf("%s", fir[i].message[j]);
      }
      scanf("%d%d", &fir[i].att, &fir[i].lea);
    }
    sort(fir, fir + m, cmp); /// 结构体排序
    for (i = 0; i < k; i++) {
      printf("%s\n", fir[i].message[0]);
    }
  }
  return 0;
}
