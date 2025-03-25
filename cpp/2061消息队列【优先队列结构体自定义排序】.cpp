#include <iostream>
#include <queue> ///优先队列
#include <stdio.h>
#include <string>
using namespace std;
struct document /// 结构体打包
{
  char name[20];
  int num;    /// 参数记录
  int getnum; /// 优先级记录
  int equals; /// 先来后到顺序记录
  bool operator()(
      const document &a,
      const document &
          b) /// 比较函数存放于结构体中，bool返回值，命名为operator，参数是结构体类型
  {
    if (a.getnum == b.getnum) /// 自定义结构体排序
    {
      return a.equals > b.equals;
    }
    return a.getnum > b.getnum; /// 从大到小降序排列
  }
} much;

int main() {
  string input;
  int flag = 0;
  priority_queue<document, vector<document>, document>
      q; /// 定义优先队列，首位是队列中元素类型，中间是动态数组，最后是比对函数自定义，因为我放到了结构体中，因此函数名为结构体类型名
  while (cin >> input) {
    if (input == "GET") {
      if (!q.size()) {
        printf("EMPTY QUEUE!\n");
        continue;
      } else {
        printf("%s %d\n", q.top().name,
               q.top().num); /// 输出队列首位中结构体的各项数据，语法为top().xxx
        q.pop();             /// 弹出
      }
    } else {
      scanf("%s %d %d", much.name, &much.num, &much.getnum);
      much.equals = ++flag;
      q.push(much); /// 入列
    }
  }
  return 0;
}
