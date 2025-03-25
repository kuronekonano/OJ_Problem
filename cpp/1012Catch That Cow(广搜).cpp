#include <queue>
#include <stdio.h>
#include <string.h>
using namespace std;
int main() {
  int st, k;
  queue<int> cow;                       // 建立队列
  int vis[100009];                      // 声明标记数组
  while (scanf("%d%d", &st, &k) != EOF) // 输入初始位置和目标位置
  {
    memset(vis, 0, sizeof(vis)); // 清空标记数组
    while (!cow.empty())         // 清空队列，若不为空，则弹出队列内元素
    {
      cow.pop();
    }
    cow.push(st);        // 将初始位置放入队列
    vis[st] = 1;         // 标记初始位置为1
    while (!cow.empty()) // 开始循环走步骤，条件是队列不为空
    {
      int walk =
          cow.front(); // 每次走一步都要记录队首的坐标值，记录队首坐标值以确定你下一步的行走方式
      cow.pop();                           // 出队列
      if (walk - 1 >= 0 && !vis[walk - 1]) // 后退一步
      {
        cow.push(walk - 1);
        vis[walk - 1] =
            vis[walk] +
            1; // 这里vis不仅标记了每个坐标是否被走过，同时也记录了已经行走的步数
      }
      if (walk + 1 <= 100000 && !vis[walk + 1]) // 前进一步
      {
        cow.push(walk + 1);
        vis[walk + 1] = vis[walk] + 1;
      }
      if (walk * 2 <= 100000 && !vis[walk * 2]) // 跳跃
      {
        cow.push(walk * 2);
        vis[walk * 2] = vis[walk] + 1;
      }
      if (vis[k]) // 若目的位置被标记，则结束循环
      {
        break;
      }
    }
    printf("%d\n", vis[k] - 1); // 输出步数，并减掉初始位置标记的多余的一步
  }
  return 0;
}
