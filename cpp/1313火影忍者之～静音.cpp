#include <algorithm>
#include <queue>
#include <stdio.h> ///优先队列
#include <string.h>
using namespace std;
struct npcs {
  char name[25];
  int pen, mag;
  bool operator()(
      npcs a,
      npcs
          b) /// 玄学的重载运算符，当优先队列的定义形式不同时，重载运算符的格式也不同
  {
    if (a.pen == b.pen) /// 第一轮选拔用笔试排序
    {
      return strcmp(a.name, b.name) > 0;
    }
    return a.pen < b.pen;
  }
} k, top[10800]; /// k作为输入的临时存放，top是被选出的要去第二轮忍术选拔的人
bool cmp(npcs a, npcs b) /// 第二轮选拔sort的自定义函数，用忍术来排序
{
  if (a.mag == b.mag) {
    return strcmp(a.name, b.name) < 0;
  }
  return a.mag > b.mag;
}
int main() {
  int m, n;
  while (scanf("%d%d", &m, &n) != EOF) {
    priority_queue<npcs, vector<npcs>, npcs> q; /// 队列放里面，不然总忘了清空
    int flag = 0;
    while (m--) /// m批人，因此输入m次，每次选出的人被放到数组中
    {
      for (int i = 0; i < n; i++) {
        scanf("%s%d%d", k.name, &k.pen, &k.mag);
        q.push(
            k); /// 排到优先队列中，这样队列中未选中的人也会留到后面的第一轮选拔里
      }
      for (int i = 0; i < 5; i++) /// 每批选出5人
      {
        top[flag++] = q.top();
        q.pop();
      }
    }
    sort(top, top + flag, cmp); /// 第二轮选拔
    for (int i = 0; i < 5; i++) {
      printf("%s\n", top[i].name); /// 只选出5人
    }
  }
  return 0;
}
