#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
struct Node {
  int data;
  Node *l, *r;
} *root;
int a[100008], ans[100008], num;
Node *newnode() {
  Node *tmp = new Node;
  tmp->data = -1;
  tmp->l = tmp->r = NULL;
  return tmp;
}
void creat(int n) {
  root = newnode();
  root->data = a[0];
  for (int i = 1; i < n; i++) {
    Node *pos = root;
    while (pos != NULL)
      if (a[i] > pos->data && pos->r != NULL)
        pos = pos->r;
      else if (a[i] < pos->data && pos->l != NULL)
        pos = pos->l;
      else
        break;
    Node *next = newnode();
    next->data = a[i];
    if (a[i] > pos->data)
      pos->r = next;
    else
      pos->l = next;
  }
}
void inOrderTraverse(Node *T) /// 先序遍历
{
  if (T) {
    ans[num++] = T->data;
    inOrderTraverse(T->l); // 遍历左子树
    inOrderTraverse(T->r); // 遍历右子树
  }
}

int main() {
  int n;
  while (scanf("%d", &n) != EOF) {
    num = 0;
    for (int i = 0; i < n; i++)
      scanf("%d", &a[i]);
    creat(n);
    inOrderTraverse(root);
    for (int i = 0; i < num; i++)
      printf("%d%c", ans[i], i == num - 1 ? '\n' : ' ');
  }
}
