#include <queue> ///��������С��������������ߴ����źͲ��ߴ��������������ȡ��Сʱ����Ϊans
#include <stdio.h>  ///�����ж�1*1�ĵ�ͼ
#include <string.h> ///�ߴ����ŵ���� ������ѵ���һ�������ŵ�ʱ��+���յ������ѵ��ĵ�һ�������ŵ�ʱ�����
using namespace std;
char ma[108][108];
bool vis[108][108];
int walkx[] = {1, -1, 0, 0};
int walky[] = {0, 0, 1, -1};
struct point {
  int x, y, ans;
} st, ed;
int main() {
  int t, n, m;
  scanf("%d", &t);
  while (t--) {
    scanf("%d%d", &n, &m);
    getchar();
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        scanf("%c", &ma[i][j]);
        if (ma[i][j] == 'Z')
          st.x = i, st.y = j;
        if (ma[i][j] == 'W')
          ed.x = i, ed.y = j;
      }
      getchar();
    }
    memset(vis, false, sizeof(vis));
    bool flag = false;
    queue<point> q;
    while (!q.empty())
      q.pop();
    vis[st.x][st.y] = true;
    st.ans = 0;
    int ans_1 = 0x7fffffff;
    q.push(st);
    while (!q.empty()) {
      point top = q.front(), tmp;
      q.pop();
      for (int i = 0; i < 4; i++) {
        tmp.x = top.x + walkx[i];
        tmp.y = top.y + walky[i];
        tmp.ans = top.ans + 1;
        if (ma[tmp.x][tmp.y] == 'P' || ma[tmp.x][tmp.y] == 'W') {
          ans_1 = tmp.ans;
          flag = true;
          break;
        }
        if (tmp.x >= 0 && tmp.y >= 0 && tmp.x < n && tmp.y < m &&
            !vis[tmp.x][tmp.y] && ma[tmp.x][tmp.y] != '#') {
          vis[tmp.x][tmp.y] = true;
          q.push(tmp);
        }
      }
      if (flag)
        break;
    }
    while (!q.empty())
      q.pop();
    flag = false;
    vis[ed.x][ed.y] = true;
    ed.ans = 0;
    int ans_2 = 0x7fffffff;
    q.push(ed);
    while (!q.empty()) {
      point top = q.front(), tmp;
      q.pop();
      for (int i = 0; i < 4; i++) {
        tmp.x = top.x + walkx[i];
        tmp.y = top.y + walky[i];
        tmp.ans = top.ans + 1;
        if (ma[tmp.x][tmp.y] == 'P' || ma[tmp.x][tmp.y] == 'Z') {
          ans_2 = tmp.ans;
          flag = true;
          break;
        }
        if (tmp.x >= 0 && tmp.y >= 0 && tmp.x < n && tmp.y < m &&
            !vis[tmp.x][tmp.y] && ma[tmp.x][tmp.y] != '#') {
          vis[tmp.x][tmp.y] = true;
          q.push(tmp);
        }
      }
      if (flag)
        break;
    }
    memset(vis, false, sizeof(vis));
    while (!q.empty())
      q.pop();
    flag = false;
    vis[st.x][st.y] = true;
    st.ans = 0;
    q.push(st);
    int ans2 = 0x7fffffff;
    while (!q.empty()) {
      point top = q.front(), tmp;
      q.pop();
      for (int i = 0; i < 4; i++) {
        tmp.x = top.x + walkx[i];
        tmp.y = top.y + walky[i];
        tmp.ans = top.ans + 1;
        if (ma[tmp.x][tmp.y] == 'W') {
          //                    printf("--%c    x=%d   y=%d
          //                    ans=%d\n",ma[top.x][top.y],top.x,top.y,top.ans);
          ans2 = tmp.ans;
          flag = true;
          break;
        }
        if (tmp.x >= 0 && tmp.y >= 0 && tmp.x < n && tmp.y < m &&
            !vis[tmp.x][tmp.y] && ma[tmp.x][tmp.y] != '#') {
          vis[tmp.x][tmp.y] = true;
          q.push(tmp);
        }
      }
      if (flag)
        break;
    }
    if ((ans_1 == 0x7fffffff || ans_2 == 0x7fffffff) &&
        ans2 ==
            0x7fffffff) /// ����ںͳ��������ѵ�ʱ��ע��������κ�һ���Ѳ���������˵�������Ÿ����߲�ͨ
    {
      printf("IMPOSSIBLE\n");
      continue;
    }
    printf("%d\n", ans_1 + ans_2 > ans2 ? ans2 : ans_1 + ans_2);
  }
}
/*
5 5
Z....
###..
.#P##
.....
W...P
6 6
Z....W
##P..P
.#P###
......
....P.
......
*/
