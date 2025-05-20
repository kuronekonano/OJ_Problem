#include <stdio.h> //DFS深度优先搜索
#include <string.h>
int vis[1056][1012];  // 标记数组
int high[1007][1024]; // 坐标高度，数组下标代表坐标位置，存储的是坐标的高度
int walkx[4] = {0, 1, -1, 0}; // 行走的路线，一维数组存储x的移动方式
int walky[4] = {1, 0, 0, -1}; // 行走的路线，一维数组存储y的移动方式
int area;                     // 记录总面积
int i, j, n, m, p1, p2;
int dfs(int x, int y) // DFS函数用于移动坐标
{
  if (vis[x][y]) // 若投入坐标已经被标记，则结束
  {
    return 0;
  }
  if (!vis[x]
          [y]) // 若投入坐标未被标记，标记这个坐标，并增加流动面积，一开始的泉眼位置是未被标记的
  {
    area++;
    vis[x][y] = 1;
  }
  for (int i = 0; i < 4; i++) // 从投入坐标的位置开始行走，4个方向
  {
    int nx = x + walkx[i]; // 新坐标位置，为上下左右移动后的x和y值
    int ny = y + walky[i];
    if (nx >= 1 && nx <= n && ny >= 1 && ny <= m &&
        high[nx][ny] <=
            high[p1]
                [p2]) // 若这个新坐标位置符合条件，未被标记且不出地图，且高度不高，则选择从这里走，进入下一个DFS函数中
    {
      dfs(nx, ny); // 这是一层递归关系
    }
  }
  return 0;
}
int main() /// 主函数
{
  while (scanf("%d%d%d%d", &n, &m, &p1, &p2) !=
         EOF) // 输入地图方阵大小，输入泉眼位置
  {
    for (i = 1; i <= n; i++) // 输入部分，输入各个坐标高度
    {
      for (j = 1; j <= m; j++) {
        scanf("%d", &high[i][j]);
      }
    }
    memset(vis, 0, sizeof(vis)); // 清空标记数组
    area = 0;                    // 初始化水域面积
    dfs(p1, p2);                 // 投入初始坐标
    printf("%d\n", area);
  }
  return 0;
}
