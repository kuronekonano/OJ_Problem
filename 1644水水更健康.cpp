#include <algorithm>
#include <stdio.h>
#include <string.h>
using namespace std;
struct num // ��ΪҪ���������̫���ˣ����ַ�����
{
  int len; // ���ȣ��ַ���ͬʱ�洢
  char number[10000];
} nums[105];
bool cmp(num a, num b) // �ṹ������
{
  if (a.len == b.len) // ������ͬ���ַ�����С��ASCII�룩
  {
    return (strcmp(a.number, b.number) < 0);
  } else
    return a.len < b.len; // ���Ȳ�ͬ�ȳ���
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
