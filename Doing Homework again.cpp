#include <algorithm>
#include <stdio.h> //贪心算法优先取最优解
using namespace std;
struct homework {
  int time;
  int mark;
  bool finish;
} each[1005];
bool cmp(homework a, homework b) {
  if (a.time == b.time) {
    return a.mark > b.mark;
  }
  return a.time < b.time;
}
int main() {
  int i, t, n, j;
  scanf("%d", &t); // t组数据
  while (t--) {
    scanf("%d", &n);        // 有n份作业
    for (i = 0; i < n; i++) // 输入部分
    {
      scanf("%d", &each[i].time);
    }
    for (i = 0; i < n; i++) {
      scanf("%d", &each[i].mark);
      each[i].finish = true; // 标记作业可以完成
    }

    sort(each, each + n,
         cmp); // 作业按时间排序，注意若期限相同，优先取分数扣的多的在前面

    int sum = 0, day = 1;   // 初始化被扣分数，以及已经过去的天数
    for (i = 0; i < n; i++) // 从最少期限遍历结构体，优先做期限少和扣分多的作业
    {
      if (each[i].time >= day) // 若当份作业期限天数在当天天数
      {
        day++; // 则可以做这份作业，做完后因当天用于做作业所以天数加1
        continue;
      } // 若当份作业期限不符合当天天数，说明不能做，进入扣分流程

      /// 其中扣分流程有一环节可以使目前不能完成的作业，找到已经可以完成的作业来替换，若不能完成的作业扣分远大于已经完成的某项作业，可以使那份扣分较少的作业代替扣分多的作业
      int k = each[i].mark, s = i;
      for (
          j = 0; j < i;
          j++) // 从之前已经判断可以完成的作业中找是否存在可以以更小分数为代价，代替目前目前作业扣分的作业，因为是循环，所以最小扣分是一直在更新的
      {
        if (each[j].mark < k &&
            each[j].finish) // 若之前的作业所扣分数小于当份作业，且能完成
        {
          k = each[j].mark; // 则让之前的作业替换掉不能完成且扣分太多的
          s = j;            // 记录其位置，以便于最后标记其不能完成
        }
      }
      sum = sum + k;          // 第k份作业无法完成，扣分计入
      each[s].finish = false; // 记录其不能完成
    }
    printf("%d\n", sum);
  }
  return 0;
}
