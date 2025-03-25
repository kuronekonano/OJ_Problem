#include <algorithm>
#include <iostream> ///这是string型定义必须的头文件
#include <stdio.h>
#include <string.h>
using namespace std;
struct gun {
  // string
  // name;///string型的定义条件，以及使用的方法，以及是否需要定义数组大小，不用char型是为了比较方便，并返回时返回数字而不是字符串
  char name[205];
  int a;
  int money;
} guns[1000005];
int cmp(gun a, gun b) // cmp对比函数
{
  if (a.a == b.a) {
    if (a.money == b.money) {
      // return
      // a.name<b.name;///比较字符串，这里因为使用string型而返回数字，若使用char型比较则必须用strcmp函数，且返回的是字符型，这在int型的函数中会报错
      return (
          strcmp(a.name, b.name) <
          0); /// 使用strcmp函数时直接返回比较值大于或小于或等于0，否则则出现返回的值为char型的情况
    }
    return a.money <
           b.money; /// 需要注意的是这里调用结构体内的元素进函数比较时，必须注意要a，b或x,y在前面，元素名字在后面
  }
  return a.a > b.a;
}
int main() /// 主函数
{
  int t, i, j, n;
  scanf("%d", &t);
  for (i = 0; i < t; i++) {
    cin >> guns[i].name; /// string型是必须用cin cout输入输出的
    scanf("%d%d", &guns[i].a, &guns[i].money);
  }
  sort(guns, guns + t, cmp); // 结构体排序要用cmp自定义函数
  for (i = 0; i < t; i++) {
    cout << guns[i].name << endl;
  }
  return 0;
}
