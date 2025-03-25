#include <algorithm>
#include <stdio.h> //̰���㷨����ȡ���Ž�
using namespace std;
struct homework {
  int time;
  int mark;
  bool finish;
} each[1005];
bool cmp(homework a, homework b) {
  if (a.time == b.time) {
    return a.mark > b.mark;
  }
  return a.time < b.time;
}
int main() {
  int i, t, n, j;
  scanf("%d", &t); // t������
  while (t--) {
    scanf("%d", &n);        // ��n����ҵ
    for (i = 0; i < n; i++) // ���벿��
    {
      scanf("%d", &each[i].time);
    }
    for (i = 0; i < n; i++) {
      scanf("%d", &each[i].mark);
      each[i].finish = true; // �����ҵ�������
    }

    sort(each, each + n,
         cmp); // ��ҵ��ʱ������ע����������ͬ������ȡ�����۵Ķ����ǰ��

    int sum = 0, day = 1;   // ��ʼ�����۷������Լ��Ѿ���ȥ������
    for (i = 0; i < n; i++) // ���������ޱ����ṹ�壬�����������ٺͿ۷ֶ����ҵ
    {
      if (each[i].time >= day) // ��������ҵ���������ڵ�������
      {
        day++; // ������������ҵ�������������������ҵ����������1
        continue;
      } // ��������ҵ���޲����ϵ���������˵��������������۷�����

      /// ���п۷�������һ���ڿ���ʹĿǰ������ɵ���ҵ���ҵ��Ѿ�������ɵ���ҵ���滻����������ɵ���ҵ�۷�Զ�����Ѿ���ɵ�ĳ����ҵ������ʹ�Ƿݿ۷ֽ��ٵ���ҵ����۷ֶ����ҵ
      int k = each[i].mark, s = i;
      for (
          j = 0; j < i;
          j++) // ��֮ǰ�Ѿ��жϿ�����ɵ���ҵ�����Ƿ���ڿ����Ը�С����Ϊ���ۣ�����ĿǰĿǰ��ҵ�۷ֵ���ҵ����Ϊ��ѭ����������С�۷���һֱ�ڸ��µ�
      {
        if (each[j].mark < k &&
            each[j].finish) // ��֮ǰ����ҵ���۷���С�ڵ�����ҵ���������
        {
          k = each[j].mark; // ����֮ǰ����ҵ�滻����������ҿ۷�̫���
          s = j;            // ��¼��λ�ã��Ա���������䲻�����
        }
      }
      sum = sum + k;          // ��k����ҵ�޷���ɣ��۷ּ���
      each[s].finish = false; // ��¼�䲻�����
    }
    printf("%d\n", sum);
  }
  return 0;
}
