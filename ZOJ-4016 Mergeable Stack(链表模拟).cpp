#include <malloc.h>
#include <stdio.h> ///链表模拟
#include <string.h>
const int maxn = 300005;
struct node /// 链表结点定义
{
  int val;
  node *next, *pre;
};
node *newnode() /// 新结点创建并初始化
{
  node *p = (node *)malloc(sizeof(node));
  p->next = NULL;
  p->pre = NULL;
  return p;
}
int n, q;
node *head[maxn]; /// 头结点指针
node *tail[maxn]; /// 队首指针
int main() {
  int t, flag, s, val;
  scanf("%d", &t);
  while (t--) {
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; i++) /// 头结点初始化
    {
      head[i] = newnode();
      head[i]->val = 0;
      head[i]->next = NULL;
      head[i]->pre = NULL;
      tail[i] = head[i];
    }
    while (q--) {
      scanf("%d", &flag);
      if (flag == 1) /// 新结点进栈，创建新结点
      {
        scanf("%d%d", &s, &val);
        head[s]->val++;
        node *p = newnode();
        p->val = val;
        p->pre = tail[s];
        tail[s]->next = p;
        tail[s] = p;
      } else if (flag == 2) /// 弹出队首
      {
        scanf("%d", &s);
        if (head[s]->val == 0)
          printf("EMPTY\n");
        else {
          printf("%d\n", tail[s]->val);
          node *p = tail[s];
          tail[s] = tail[s]->pre;
          tail[s]->next = NULL;
          free(p);
          head[s]->val--;
        }
      } else /// 合并栈
      {
        scanf("%d%d", &s, &val);
        if (head[val]->val != 0) {
          tail[s]->next = head[val]->next;
          head[val]->next->pre = tail[s];
          tail[s] = tail[val];
          head[s]->val += head[val]->val;
          head[val]->val = 0;
          head[val]->next = NULL;
          tail[val] = head[val];
        }
      }
    }
  }
}
/*
2
2 15
1 1 10
1 1 11
1 2 12
1 2 13
3 1 2
1 2 14
2 1
2 1
2 1
2 1
2 1
3 2 1
2 2
2 2
2 2
3 7
3 1 2
3 1 3
3 2 1
2 1
2 2
2 3
2 3
*/
