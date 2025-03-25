#include <algorithm> //̰�ģ������Ž�
#include <stdio.h>
using namespace std;
struct water // ����ṹ�壬ÿ���˵ı�����ˮʱ����ƥ��
{
  int id;
  int time;
} man[100005];
bool cmp(water a, water b) // ��ʱ����ͬ��˭��ſ�ǰ˭��ǰ��
{
  if (a.time == b.time) {
    return a.id < b.id;
  }
  return a.time < b.time;
}
int main() {
  int n, i;
  while (scanf("%d", &n) != EOF) // n����
  {
    for (i = 0; i < n; i++) // ÿ�˵Ľ�ˮʱ��
    {
      scanf("%d", &man[i].time);
      man[i].id =
          i +
          1; // ��ţ���ΪҪsort���Դ�0��ʼ��ֵ������Ϊ�����0�����ÿ���˵ı��������λ�ü�1
    }
    sort(man, man + n, cmp); // �ṹ��sort����Ŀ��������Ҫʱ���ٵ����Ƚ�ˮ
    long long waitsum = 0;   // ÿ���˵ȴ�ʱ���ܺ�
    long long first = 0;     // ��i���˵ȴ���ʱ��
    for (
        i = 0; i < n;
        i++) // ��Ϊ��ÿ���˵�ƽ�����ʱ�������ÿ�˵ĵȴ�ʱ����ǰ�������˵�ʱ��֮��
    {
      waitsum =
          waitsum +
          first; // ��һ���ˣ�Ҳ�������ڽ�ˮ���˵ȴ���ʱ�������뵽�����ܺ���
      first =
          first +
          man[i]
              .time; // ÿ���˵ȴ���ʱ�����൱��ǰ���ǰ����˵�ʱ������ǰ����˵�ʱ��
      printf("%d%c", man[i].id, (i == n - 1) ? '\n' : ' '); // ������������
    }
    printf(
        "%.2f\n",
        waitsum * 1.00 /
            n); // ��Ϊ��long long
                // �͵ģ�Ҫ������λСС���޷�ǿ��ת����������Գ�1.00������ƽ��ֵ
  }
  return 0;
}
