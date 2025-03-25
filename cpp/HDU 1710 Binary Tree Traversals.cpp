#include <algorithm>
#include <cmath>
#include <cstdio> ///¶ş²æÊ÷ºóĞò±éÀú
#include <cstring>
#include <iostream>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
int pre[1005], mid[1005], behind[1005];
int num;
struct Node {
  int cnt;
  Node *l, *r;
};
Node *root;

Node *newnode() {
  Node *tmp = new Node;
  tmp->cnt = 0;
  tmp->l = tmp->r = NULL;
  return tmp;
}

Node *creat(int *pre, int len1, int *mid, int len2) {
  int i;
  for (i = 0; i < len2; i++) {
    if (pre[0] == mid[i])
      break;
  }
  Node *pos = newnode();
  pos->cnt = mid[i];
  if (i > 0)
    pos->l = creat(pre + 1, i, mid, i);
  if (i < len2 - 1)
    pos->r = creat(pre + i + 1, len2 - i - 1, mid + i + 1, len2 - i - 1);
  return pos;
}

void behindquery(Node *root) {
  if (root == NULL)
    return;
  behindquery(root->l);
  behindquery(root->r);
  behind[num++] = root->cnt;
}

void release(Node *pos) {
  if (pos == NULL)
    return;
  release(pos->l);
  release(pos->r);
  free(pos);
  return;
}

int main() {
  int n = 0;
  while (~scanf("%d", &n)) {
    for (int i = 0; i < n; i++)
      scanf("%d", &pre[i]);
    for (int i = 0; i < n; i++)
      scanf("%d", &mid[i]);
    release(root);
    root = creat(pre, n, mid, n);
    num = 0;
    behindquery(root);
    for (int i = 0; i < n; i++)
      printf("%d%c", behind[i], i == n - 1 ? '\n' : ' ');
  }
  release(root);
  return 0;
}
