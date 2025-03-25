#include <stdio.h>
#include <string.h>
struct man {
  int num;
  char name[3];
  bool life;
} a[108];
int main() {
  int t, n, m;
  scanf("%d", &t);
  while (t--) {
    int fz = 0, zc = 0, nj = 0,
        njj = -1; /// 因为各个角色从0开始，因此不存在的位置应该被定为-1而不是0
    bool zgg = false, fzz = false;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
      scanf("%s", a[i].name);
      a[i].num = 0;
      a[i].life = true;
      if (a[i].name[1] == 'Z')
        fz++;
      if (a[i].name[1] == 'C')
        zc++;
      if (a[i].name[1] == 'J')
        nj++;
    }
    int x[109], y[109];
    for (int q = 1; q <= m; q++) {
      scanf("%d%d", &x[q], &y[q]);
    }
    for (int q = 1; q <= m; q++) {
      if (a[y[q]].name[1] == 'G') /// 主公被杀
      {
        a[y[q]].life = false;
        if (a[x[q]].name[1] == 'Z') /// 反贼杀死主公必定反贼赢
        {
          a[x[q]].num += 2;
          fzz = true;
        }
        if (a[x[q]].name[1] == 'J') {
          if (nj == 1 && fz == 0 &&
              zc ==
                  0) /// 内奸只有通过和主公单挑才能赢，因此仅仅是当剩余1个内奸和1个主公时才判定内奸杀主公时内奸赢，否则是反贼赢
          {
            a[x[q]].num += 4 + n * 2;
            njj = x[q]; /// 记录最终杀死主公的是哪位内奸，算分时只有这个内奸得分
          } else {
            fzz = true;
          }
        } /// 忠臣不会杀主公
        break;
      }
      if (a[y[q]].name[1] == 'C') /// 忠臣被杀
      {
        zc--;
        a[y[q]].life = false;
        if (a[x[q]].name[1] == 'Z') /// 只有被反贼杀才有额外加分
        {
          a[x[q]].num++;
        }
      }
      if (a[y[q]].name[1] == 'J') /// 内奸被杀
      {
        if (a[x[q]].name[1] == 'G') /// 内奸被主公杀时判断是否是单挑情况
        {
          if (nj == 1 && zc == 0 && fz == 0) {
            a[y[q]].num =
                n; /// 如果单挑，那么记录这个单挑的内奸，分数单独被定为n
            njj = y[q];
          }
        }
        nj--;
        a[y[q]].life = false;
        if (a[x[q]].name[1] != 'J')
          a[x[q]].num++; /// 内奸可能被内奸杀，只有不被内奸杀时才有额外加分
        if (nj == 0 && fz == 0) {
          zgg = true;
          break;
        }
      }
      if (a[y[q]].name[1] == 'Z') /// 反贼被杀
      {
        fz--;
        a[y[q]].life = false;
        if (a[x[q]].name[1] != 'J' &&
            a[x[q]].name[1] !=
                'Z') /// 反贼会被反贼杀，因此反贼只被忠臣和主公杀时加分
        {
          a[x[q]].num++;
        }
        if (nj == 0 && fz == 0) {
          zgg = true;
          break;
        }
      }
    }
    if (zgg) /// 主公赢
    {
      for (int i = 0; i < n; i++) {
        if (a[i].name[1] == 'G') {
          printf("%d%c", a[i].num + 4 + zc * 2, i == n - 1 ? '\n' : ' ');
        }
        if (a[i].name[1] == 'C') {
          printf("%d%c", a[i].num + 5 + zc, i == n - 1 ? '\n' : ' ');
        }
        if (a[i].name[1] == 'Z') {
          printf("0%c", i == n - 1 ? '\n' : ' ');
        }
        if (a[i].name[1] == 'J') {
          printf("%d%c", i == njj ? a[i].num : 0,
                 i == n - 1 ? '\n'
                            : ' '); /// 主公赢时，单挑的内奸有分，否则为0分
        }
      }
    } else if (njj != -1 && !zgg) /// 内奸赢
    {
      for (int i = 0; i < n; i++) {
        if (a[i].name[1] == 'G') {
          printf("%d%c", 1, i == n - 1 ? '\n' : ' ');
        }
        if (a[i].name[1] == 'C') {
          printf("0%c", i == n - 1 ? '\n' : ' ');
        }
        if (a[i].name[1] == 'Z') {
          printf("0%c", i == n - 1 ? '\n' : ' ');
        }
        if (a[i].name[1] == 'J') {
          printf("%d%c", i == njj ? a[i].num : 0,
                 i == n - 1 ? '\n'
                            : ' '); /// 内奸赢时，只有单挑的内奸有分，其余0分
        }
      }
    } else if (fzz) /// 反贼赢
    {
      for (int i = 0; i < n; i++) {
        if (a[i].name[1] == 'G') {
          printf("0%c", i == n - 1 ? '\n' : ' ');
        }
        if (a[i].name[1] == 'C') {
          printf("0%c", i == n - 1 ? '\n' : ' ');
        }
        if (a[i].name[1] == 'Z') {
          a[i].num += fz * 3;
          printf("%d%c", a[i].num,
                 i == n - 1 ? '\n'
                            : ' '); /// 反贼都有分，在额外加分的基础上加基础得分
        }
        if (a[i].name[1] == 'J') {
          printf("%d%c", a[i].life ? 1 : 0,
                 i == n - 1 ? '\n' : ' '); /// 只有活着的内奸有1分，否则为0分
        }
      }
    }
  }
}
/*
1）主公死亡。此时若内奸是唯一存活的角色（有且仅有一名内奸存活），则内奸获胜，除此之外的情况为反贼获胜（不论反贼角色死活）。
2）所有的反贼和内奸都已死亡：主公和忠臣（不论死活）都获胜。
*/
