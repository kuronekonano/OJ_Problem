#include <iostream>
#include <queue>
#include <stdio.h> //�ò���printf��scanf�������޷��ö�ά�ַ���������У���֪��Ϊɶ
using namespace std;
int main() {
  queue<string> q; // ����
  int n, m, d;
  string a
      [108]; // ��ά���飬string��һά����Ҫ�趨���ȣ���ά�趨�����ж��ٸ��������ַ���
  while (scanf("%d", &n) != EOF) // ����
  {
    while (!q.empty()) {
      q.pop();
    }
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      q.push(a[i]); // ������
    }
    scanf("%d,%d", &m, &d); // �ӵ�m���˿�ʼ,ÿ������d���˳���
    for (int i = 1; i < m;
         i++) // �ҵ���m���ˣ����Ҫ��ʼ��ת���Ѷ��׵�����m����
    {
      q.push(q.front()); // �����м��������ת
      q.pop();
    }
    while (!q.empty()) // ����Ϊ��ʱ������Ϸ
    {
      for (int i = 1; i < d; i++) // ��ת����С��d����Ϊ��d�����ǳ��е�
      {
        q.push(q.front()); // ����Ҫ�м����ֱ�����תȦ�任
        q.pop();
      }
      cout << q.front() << endl; // ������ǳ��е�˳��ÿһ�εĵ�d����
      q.pop();                   // ����󵯳�����ʤ��
    }
  }
  return 0;
}
