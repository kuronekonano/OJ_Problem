#include <algorithm> //̰��
#include <stdio.h>
using namespace std;
struct tv // ����ṹ��洢����ÿ����Ŀ�Ŀ�ʼʱ��ͽ���ʱ��
{
  int s;
  int t;
} time[105];
bool cmp(tv a, tv b) // ������ǵ��ӽ�Ŀ�Ľ���ʱ��
{
  return a.t < b.t; // ˭�Ƚ����Ϳ��ĸ���Ŀ
}
int main() {
  int n, i;
  while (scanf("%d", &n) != EOF) // n����Ŀ
  {
    if (n == 0) {
      return 0;
    }
    for (i = 0; i < n; i++) // ÿ����Ŀ�Ŀ�ʼʱ�������ʱ��
    {
      scanf("%d%d", &time[i].s, &time[i].t);
    }
    sort(time, time + n, cmp); // �������ʱ��
    int sum = 0;               // �ɿ���Ŀ����������
    int last = 0;
    for (i = 0; i < n; i++) // ��������ú��Ŀ�Ŀ�ʼ����ʱ��
    {
      if (i == 0) {
        sum = 1;          // ��һ����Ŀ�϶����ܿ���
        last = time[i].t; // �ѿ�ʼʱ�����Ϊ��ǰ�ۿ���Ŀ�Ľ���ʱ��
      } else {
        if (time[i].s >= last) // ����ʼʱ����ڵ�����һ������ʱ��
        {
          last = time[i].t; // �Ϳ������Ŀ
          sum++;
        }
      }
    }
    printf("%d\n", sum);
  }
  return 0;
}
