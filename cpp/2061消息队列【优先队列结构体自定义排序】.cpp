#include <iostream>
#include <queue> ///���ȶ���
#include <stdio.h>
#include <string>
using namespace std;
struct document /// �ṹ����
{
  char name[20];
  int num;    /// ������¼
  int getnum; /// ���ȼ���¼
  int equals; /// ������˳���¼
  bool operator()(
      const document &a,
      const document &
          b) /// �ȽϺ�������ڽṹ���У�bool����ֵ������Ϊoperator�������ǽṹ������
  {
    if (a.getnum == b.getnum) /// �Զ���ṹ������
    {
      return a.equals > b.equals;
    }
    return a.getnum > b.getnum; /// �Ӵ�С��������
  }
} much;

int main() {
  string input;
  int flag = 0;
  priority_queue<document, vector<document>, document>
      q; /// �������ȶ��У���λ�Ƕ�����Ԫ�����ͣ��м��Ƕ�̬���飬����ǱȶԺ����Զ��壬��Ϊ�ҷŵ��˽ṹ���У���˺�����Ϊ�ṹ��������
  while (cin >> input) {
    if (input == "GET") {
      if (!q.size()) {
        printf("EMPTY QUEUE!\n");
        continue;
      } else {
        printf("%s %d\n", q.top().name,
               q.top().num); /// ���������λ�нṹ��ĸ������ݣ��﷨Ϊtop().xxx
        q.pop();             /// ����
      }
    } else {
      scanf("%s %d %d", much.name, &much.num, &much.getnum);
      much.equals = ++flag;
      q.push(much); /// ����
    }
  }
  return 0;
}
