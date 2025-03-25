#include <iostream>
#include <iterator> //迭代器是有头文件的
#include <set> ///已重复元素不会再次插入，并且插入元素会自动排序。神特么好用
#include <stdio.h>
using namespace std;
int main() {
  long long n, a, i;
  set<long long> q;
  while (scanf("%lld", &n) != EOF) {
    q.clear(); /// 清空容器
    set<long long>::iterator
        nano; // 迭代器指针的使用，先定义是什么容器的，定义什么型的，定义名字
    for (i = 1; i <= n; i++) {
      scanf("%lld", &a);
      q.insert(a); // 装入容器
    }
    printf(
        "%d\n",
        q.size()); /// size返回的是一个值，目测是一个int型的值，因为%lld会输出奇怪的东西
    printf(
        "%lld",
        *q.begin()); /// 而begin和end返回的是一个地址，因此begin需要指针或者迭代器承接，或者加上*运算符再输出

    for (nano = ++q.begin(); nano != q.end();
         nano++) /// set中的地址是随输入连在一起的所以可以用自增地址来移动指针
    {
      printf(
          " %lld",
          *nano); /// end()返回的是容器中最后一个值的后面那个！不是最后一个值！
    }
    printf(
        "\n"); /// 注意：迭代器中的++
               /// --自增自减符号是被重载过的，和原本意义已经不一样了。通过重载的运算符实现指针移动
  }
  return 0;
}
