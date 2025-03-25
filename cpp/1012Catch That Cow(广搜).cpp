#include <queue>
#include <stdio.h>
#include <string.h>
using namespace std;
int main() {
  int st, k;
  queue<int> cow;                       // ��������
  int vis[100009];                      // �����������
  while (scanf("%d%d", &st, &k) != EOF) // �����ʼλ�ú�Ŀ��λ��
  {
    memset(vis, 0, sizeof(vis)); // ��ձ������
    while (!cow.empty())         // ��ն��У�����Ϊ�գ��򵯳�������Ԫ��
    {
      cow.pop();
    }
    cow.push(st);        // ����ʼλ�÷������
    vis[st] = 1;         // ��ǳ�ʼλ��Ϊ1
    while (!cow.empty()) // ��ʼѭ���߲��裬�����Ƕ��в�Ϊ��
    {
      int walk =
          cow.front(); // ÿ����һ����Ҫ��¼���׵�����ֵ����¼��������ֵ��ȷ������һ�������߷�ʽ
      cow.pop();                           // ������
      if (walk - 1 >= 0 && !vis[walk - 1]) // ����һ��
      {
        cow.push(walk - 1);
        vis[walk - 1] =
            vis[walk] +
            1; // ����vis���������ÿ�������Ƿ��߹���ͬʱҲ��¼���Ѿ����ߵĲ���
      }
      if (walk + 1 <= 100000 && !vis[walk + 1]) // ǰ��һ��
      {
        cow.push(walk + 1);
        vis[walk + 1] = vis[walk] + 1;
      }
      if (walk * 2 <= 100000 && !vis[walk * 2]) // ��Ծ
      {
        cow.push(walk * 2);
        vis[walk * 2] = vis[walk] + 1;
      }
      if (vis[k]) // ��Ŀ��λ�ñ���ǣ������ѭ��
      {
        break;
      }
    }
    printf("%d\n", vis[k] - 1); // �����������������ʼλ�ñ�ǵĶ����һ��
  }
  return 0;
}
