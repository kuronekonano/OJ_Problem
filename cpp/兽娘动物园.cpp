/// What Kind of Friends Are You?
#include <map>
#include <stdio.h>
#include <string.h>
using namespace std;
struct anim {
  char name[25];
  bool ans[28];
} cc[208];
int main() {
  int n, q, i, j, t, c, m;
  scanf("%d", &t);
  while (t--) {
    scanf("%d%d", &n, &q);
    scanf("%d", &c);
    for (i = 0; i < c; i++) {
      scanf("%s", cc[i].name);
      memset(cc[i].ans, false, sizeof(cc[i].ans));
    }
    char str[30];
    for (i = 0; i < q; i++) /// 问题
    {
      scanf("%d", &m); /// 回答人数
      for (j = 0; j < m; j++) {
        scanf("%s", str); /// 每人名字
        for (int k = 0; k < c; k++) {
          if (strcmp(str, cc[k].name) == 0) {
            cc[k].ans[i] = true;
          }
        }
      }
    }
    //        for(i=0;i<c;i++)
    //        {
    //            printf("%s ",cc[i].name);
    //            for(j=0;j<q;j++)
    //            {
    //                printf(" %d",cc[i].ans[j]);
    //            }
    //            printf("\n");
    //        }
    bool ansn[130][29];
    memset(ansn, false, sizeof(ansn));
    for (i = 0; i < n; i++) {
      for (j = 0; j < q; j++) {
        scanf("%d", &ansn[i][j]);
      }
    }
    for (i = 0; i < n; i++) /// 朋友
    {
      int flag = 0;
      int num = -1;
      for (int r = 0; r < c; r++) /// 从朋友中找相符的
      {
        for (j = 0; j < q; j++) /// 问题
        {
          if (cc[r].ans[j] != ansn[i][j])
            break;
        }
        if (j == q) {
          num = r;
          flag++;
        }
      }
      //            printf("%d\n",flag);
      if (flag != 1) {
        printf("Let's go to the library!!\n");
      } else {
        printf("%s\n", cc[num].name);
      }
    }
  }
  return 0;
}
