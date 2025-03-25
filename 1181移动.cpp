#include <queue>
#include <stdio.h>
#include <string.h> //����
#include <string.h>
using namespace std;
int x1, y1, x2, y2, i;
int vis[305][309]; // ������飬���Χ���ᳬ��300��300
int walkx[10] = {
    2,  1,  1,  2,
    -1, -2, -1, -2}; // ���߷�ʽ�����飬ÿ�β�����Ӧxֵ�ƶ���yֵ�ƶ��ľ���
int walky[10] = {-1, -2, 2, 1, 2, 1, -2, -1};
int walk;
struct point // Ϊ����ÿ����Ϊһ�����꣬��Ϊһ���ṹ����
{
  int x, y;
} a, b;
queue<point> q; // point�ͽṹ����У�����������ȥ����һ����point�ͽṹ��
int main() {
  point s, t; // �����ʼ������յ�����
  while (scanf("%d%d%d%d", &s.x, &s.y, &t.x, &t.y) != EOF) // ��ʼ������յ�����
  {
    while (!q.empty()) // ��ն���
    {
      q.pop();
    }
    memset(vis, 0, sizeof(vis)); // ��ձ������
    vis[s.x][s.y] = 1;           // ����ʼλ�ñ���ǹ�
    q.push(s);                   // ��ʼλ������

    while (!q.empty()) {
      a = q.front(); // �Ӷ�����ʼ
      q.pop();
      for (i = 0; i < 8; i++) {
        b.x = a.x + walkx[i]; // �ӵ�ǰ�㿪ʼ�ƶ�xֵ��yֵ
        b.y = a.y + walky[i];
        if (b.x >= 0 && b.x <= 300 && b.y >= 0 && b.y <= 300 &&
            !vis[b.x][b.y]) // ����ǰ����δ�������Ʒ�Χ
        {
          vis[b.x][b.y] = vis[a.x][a.y] + 1; // ����߹���λ�ã������赱ǰ����
          q.push(b);                         // ��������һ����
        }
      }
      if (vis[t.x][t.y]) // �����յ㱻������˳�ѭ��
      {
        break;
      }
    }
    printf("%d\n",
           vis[t.x][t.y] -
               1); // ������յ��λ��-1�Ĳ�������Ϊ��ʼ�㲻�㲽����ȴ�������1
  }
  return 0;
}
