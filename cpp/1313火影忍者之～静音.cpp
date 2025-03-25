#include <algorithm>
#include <queue>
#include <stdio.h> ///���ȶ���
#include <string.h>
using namespace std;
struct npcs {
  char name[25];
  int pen, mag;
  bool operator()(
      npcs a,
      npcs
          b) /// ��ѧ������������������ȶ��еĶ�����ʽ��ͬʱ������������ĸ�ʽҲ��ͬ
  {
    if (a.pen == b.pen) /// ��һ��ѡ���ñ�������
    {
      return strcmp(a.name, b.name) > 0;
    }
    return a.pen < b.pen;
  }
} k, top[10800]; /// k��Ϊ�������ʱ��ţ�top�Ǳ�ѡ����Ҫȥ�ڶ�������ѡ�ε���
bool cmp(npcs a, npcs b) /// �ڶ���ѡ��sort���Զ��庯����������������
{
  if (a.mag == b.mag) {
    return strcmp(a.name, b.name) < 0;
  }
  return a.mag > b.mag;
}
int main() {
  int m, n;
  while (scanf("%d%d", &m, &n) != EOF) {
    priority_queue<npcs, vector<npcs>, npcs> q; /// ���з����棬��Ȼ���������
    int flag = 0;
    while (m--) /// m���ˣ��������m�Σ�ÿ��ѡ�����˱��ŵ�������
    {
      for (int i = 0; i < n; i++) {
        scanf("%s%d%d", k.name, &k.pen, &k.mag);
        q.push(
            k); /// �ŵ����ȶ����У�����������δѡ�е���Ҳ����������ĵ�һ��ѡ����
      }
      for (int i = 0; i < 5; i++) /// ÿ��ѡ��5��
      {
        top[flag++] = q.top();
        q.pop();
      }
    }
    sort(top, top + flag, cmp); /// �ڶ���ѡ��
    for (int i = 0; i < 5; i++) {
      printf("%s\n", top[i].name); /// ֻѡ��5��
    }
  }
  return 0;
}
