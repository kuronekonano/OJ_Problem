#include <stdio.h> ///输入人数，将这些人选出一些队长，剩余的人平分给这些队长，看有几种方案。
#include <string.h> ///也是就判断总人数-队长人数，看剩余人数可否被队长人数整除。
int main() /// 直接从2遍历到1e5然后每个数减去再判断会超时，那么正着来，直接看队长数*分配人数+队长数=对应的n总人数
{
  int ans[100005], n;
  memset(ans, 0, sizeof(ans));
  for (int i = 1; i <= 100000; i++)
    for (int j = 1; i * j + i <= 100000; j++)
      ans[i * j + i]++;
  while (scanf("%d", &n) != EOF)
    printf("%d\n", ans[n]);
}
