#include <iostream>
#include <map> ///因为这里并查集的是每个人名字，因此要利用map先将一个名字对应到独一无二的数字上
#include <stdio.h> ///利用并查集，分组忍者村
#include <string.h>
#include <string>
using namespace std;
int team[3008]; /// 关系数组，存储每个忍者的老大
int find(int x) {
  int r = x, t;
  while (r != team[r]) {
    t = r;
    r = team[r];
    team[t] = team[r];
  }
  return r;
}
int join(int a, int b) {
  int na = find(a), nb = find(b);
  if (na != nb) {
    team[nb] = na;
  }
}
int main() {
  int i, j, n, num;
  while (scanf("%d", &n) != EOF) {
    for (i = 0; i <= 3 * n; i++) {
      team[i] = i;
    }
    num =
        1; /// 这里是第num个名字，不能从0开始，每个名字对应一个数字，如果从0开始，会发生的情况是，第1个输入的字符被对应到数字0上，但是后面0是被认为未出现名字的标记
    map<string, int>
        m; /// 出现的后果可能是，第1个名字被对应到0，如果以后再出现和第一个名字一样的，将会被判断为是未出现过的而重新对应新的数字
    string name[3];
    for (i = 0; i < n; i++) {
      for (j = 0; j < 3; j++) {
        cin >> name[j];
        if (m[name[j]] ==
            0) /// 首先map中<string,int>所对应的int初值为0，因此所有未重复出现的新名字对应的int都是0，用这个性质来判断名字是否和之前的有重复
        {
          m[name[j]] = num++;
        }
      }
      join(m[name[0]], m[name[1]]); /// 将每个分组的剩下两人与第一个人结为一个村
      join(m[name[0]], m[name[2]]);
      //            for(int k=0; k<num; k++)
      //            {
      //                printf("%d====%d\n",k,team[k]);
      //            }
      //            printf("---------------------------\n");
    }
    int flag = 0;
    for (
        i = 1; i < num;
        i++) /// 计数，从第一个到num-1(因为是num++，多出来一个)中，自己是老大的那个人就是一个村
    {
      if (team[i] == i)
        flag++;
    }
    printf("%d\n", flag);
  }
}
