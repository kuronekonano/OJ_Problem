#include <queue>
#include <stdio.h> ///���ѣ���ʵ�õ��˶����Ҹо����ǹ���
#include <string.h>
using namespace std;
struct location /// ��������Ͳ�������ṹ��
{
  int x, y, step;
} now, nexts;
char maps[109][109];          /// ����n*n���ַ������൱�ڵ�ͼ
bool vis[109][109];           /// ������飬����Ƿ��߹�ĳ������
int walkx[4] = {0, 1, 0, -1}; /// �������飬�ĸ���������
int walky[4] = {1, 0, -1, 0};
int i, j, n, q, hx, hy;
int dfs(int x, int y) /// ��������
{
  memset(vis, false, sizeof(vis)); /// ��ձ������
  queue<location> s;               /// �����ṹ��location�Ͷ���
  now.x = x;
  now.y = y; /// now�ṹ���ŵ�ʱʹ�õ�����Ͳ���
  now.step = 0;
  vis[x][y] = true;  /// С����������Ҫ��ǣ����ܷ�������
  s.push(now);       /// ����ʼ�����������
  while (!s.empty()) /// �����в�Ϊ��
  {
    now = s.front();               /// ȡ������
    s.pop();                       /// ��ȡ���ĵ���ȥ
    if (maps[now.x][now.y] == 'G') /// �ȼ��ȡ��������������Ƿ���Ů����
    {
      return now
          .step; /// �еĻ����Է��ز����ˣ�������ĿҪ�������С��������Ϊÿ��ִ������ѭ��������ֻ����һ���ģ����ԣ���С������������ҵ�Ů���ӵ�·�ߣ��������˳�����ѭ��
    } /// ͬʱ��Ϊ��Ŀ��������С��������ʹ����ͬ����С����Ҳ����Ӱ��
    for (int i = 0; i < 4; i++) /// �Ĳ���
    {
      nexts.x = now.x + walkx[i]; /// next�ṹ������һ����Ҫ���������
      nexts.y = now.y + walky[i];
      nexts.step = now.step + 1; /// �����ǵü�1
      if (nexts.x < n && nexts.x >= 0 && nexts.y < n && nexts.y >= 0 &&
          maps[nexts.x][nexts.y] != '#' &&
          vis[nexts.x][nexts.y] == false) /// ����������:
      { /// ���겻�ܳ�����ͼ�����굽�����Ϊ�߹���·�ߣ����겻���߽�����
        vis[nexts.x][nexts.y] =
            true;      /// �����������������������ߵ����꣬�����߹�
        s.push(nexts); /// ����������У���ʾ���������̽�����ĸ���������ȥ
      }
    }
  }
  return -1; /// ���������һ����˵���������в��趼�����ˣ����п��ˣ�ÿ���ط����߹���Ҳû���ҵ�Ů���ӣ�ֻ��cry�ˣ�����-1
}
int main() {

  while (scanf("%d%d", &n, &q) != EOF) /// ����n*n�����Լ�q��Ů����
  {
    for (i = 0; i < n; i++) /// ���벿��
    {
      scanf("%s", maps[i]);
      for (j = 0; j < n; j++) {
        if (maps[i][j] == '*') /// ����ʱ���ɲ���*С�����꣬�ҵ�����¼������
        {
          hx = i;
          hy = j;
        }
      }
    }
    int gx, gy; /// Ů���ӵ�����
    while (q--) /// ��q��Ů���Ӿͱ��q�Σ�����q��
    {
      scanf("%d%d", &gx, &gy);
      maps[gx][gy] = 'G'; /// ���������map�У�ֱ�ӱ��Ϊһ���ַ����ȽϺò���
    }
    int flag = dfs(hx, hy); /// ������������ʼֵ����ʼѰ�ҵ��������С�Ե�����
    if (flag != -1)         /// ��鷵��ֵ
    {
      printf("%d\n", flag);
    } else {
      printf("cry\n");
    }
  }
  return 0;
}
