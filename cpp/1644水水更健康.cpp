#include <algorithm>
#include <stdio.h>
#include <string.h>
using namespace std;
struct num // 因为要排序的数字太大了，用字符串存
{
  int len; // 长度，字符串同时存储
  char number[10000];
} nums[105];
bool cmp(num a, num b) // 结构体排序
{
  if (a.len == b.len) // 长度相同比字符串大小（ASCII码）
  {
    return (strcmp(a.number, b.number) < 0);
  } else
    return a.len < b.len; // 长度不同比长度
}
int main() {
  int n, i;
  while (scanf("%d", &n) != EOF) {
    for (i = 0; i < n; i++) {
      scanf("%s", nums[i].number);
    }
    for (i = 0; i < n; i++) {
      nums[i].len = strlen(nums[i].number);
    }
    sort(nums, nums + n, cmp);
    for (i = 0; i < n; i++) {
      printf("%s\n", nums[i].number);
    }
  }
  return 0;
}
