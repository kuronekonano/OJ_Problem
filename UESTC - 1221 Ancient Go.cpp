#include <bits/stdc++.h> ///�����������
using namespace std;
bool vis[15][15];
char a[20][20];
int t, n, x[100], y[100], walkx[5] = {0, 1, 0, -1}, walky[5] = {1, 0, -1, 0};
int dfs(int x, int y) /// ����o��������
{
  vis[x][y] = true; /// ����ѵ��ĵ�
  int sum =
      0; /// ע��ÿ������ʱ�������Ķ��壬Ҫ���ں����У�����Ӧ�����ӵĳ�·����������
  for (int j = 0; j < 4; j++) {
    //        printf("~~~~~~~~%d    %d      %d\n",x,y,j);
    if (x + walkx[j] >= 0 && x + walkx[j] < 9 && y + walky[j] >= 0 &&
        y + walky[j] < 9) /// ע�����̷�Χ��Ҫ����
    {
      if (a[x + walkx[j]][y + walky[j]] == '.' &&
          !vis[x + walkx[j]][y + walky[j]]) /// �����ո������·
      {
        sum++;
        vis[x + walkx[j]][y + walky[j]] =
            true; /// Ϊ��ֹ�ظ��������ո񣬱�ǿո�
      }
      if (a[x + walkx[j]][y + walky[j]] == 'o' &&
          !vis[x + walkx[j]][y + walky[j]]) /// ����o������dfs
      {
        sum += dfs(x + walkx[j], y + walky[j]); /// ��ͼ�¼һ����ͨ�׿���ܳ�·
      }
    }
  }
  //    printf("--------- %d\n",sum);
  return sum;
}
int main() {
  int cas = 0, i, j;
  scanf("%d", &t);
  while (t--) {
    cas++;
    memset(vis, false, sizeof(vis));
    memset(a, 0, sizeof(a));
    int num = 0;
    for (i = 0; i < 9; i++) {
      scanf("%s", a[i]);
      for (j = 0; j < 9; j++) {
        if (a[i][j] == 'o') {
          num++;
          x[num] = i;
          y[num] = j;
        }
      }
    }
    int flag = 0;
    bool ans = false;
    for (i = 1; i <= num; i++) /// ֻ����o���ӵ�����
    {
      vis[x[i]][y[i]] = true;
      flag += dfs(x[i], y[i]);
      //            printf("======%d\n",flag);
      if (flag < 2) /// �жϳ�·������С�ڵ���1��ɱ
      {
        ans = true;
        break;
      }
      flag = 0; /// ����������ÿ������һ���㣬��ձ������
      memset(vis, false, sizeof(vis));
    }
    if (ans) {
      printf("Case #%d: Can kill in one move!!!\n", cas);
    } else {
      printf("Case #%d: Can not kill in one move!!!\n", cas);
    }
  }
}
/*
........o
.........
.........
.........
x.ox.....
xxxoxxxxx
xooooooox
xoo.oooox
xxxooooox

ooooooooo
ooooooooo
ooooooooo
ooooooooo
oooo.xxxx
xxxxxxxxx
xxxxxxxxx
xxxxxxxxx
xxxxxxxxx
*/
