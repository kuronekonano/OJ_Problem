#include <cstdio>
#include <cstring>

using namespace std;

struct Node {
  int cnt;
  struct Node *next[30];
} node[444444];
int len1;
Node *newnode() {
  memset(&node[len1], 0, sizeof(node[len1])); /// 清空函数
  return &node[len1++];
}

void update(char *s, Node *root) {
  int len = strlen(s);
  for (int i = 0; i < len; i++) {
    int cc = s[i] - 'a';
    if (!root->next[cc]) {
      root->next[cc] = newnode(); /// 创建并清空新结构体函数
    }
    root->cnt++;
    root = root->next[cc];
  }
  root->cnt++;
}

int ask(char *s, Node *root) {
  int len = strlen(s);
  for (int i = 0; i < len; i++) {
    int cc = s[i] - 'a';
    if (!root->next[cc])
      return 0;
    root = root->next[cc];
  }
  return root->cnt;
}

char str[100];
int main() {
  int n, m;
  scanf("%d", &n);
  len1 = 0;
  Node *root = newnode();
  while (scanf("%s", str) != EOF) {
    if (strcmp(str, "END") == 0) {
      break;
    }
    update(str, root);
  }
  while (scanf("%s", str) != EOF) {
    printf("%d\n", ask(str, root));
  }
  return 0;
}
// #include<stdio.h>
// #include<string.h>
// int main()
//{
//     char a[50005][20];
//     int i=0;
//     while(scanf("%s",a[i++])!=EOF)
//     {
//         if(strcmp(a[i-1],"END")==0)
//         {
//             break;
//         }
//     }
//     int k=i;
//     int j;
//     char b[20];
//     while(scanf("%s",b)!=EOF)
//     {
//         if(strcmp(b,"END")==0)
//         {
//             return 0;
//         }
//         int n=strlen(b);
//         int sum=0;
//         for(i=0;i<k;i++)
//         {
//             for(j=0;j<n;j++)
//             {
//                 if(a[i][j]!=b[j])
//                 {
//                     break;
//                 }
//             }
//             if(j==n)
//             {
//                 sum++;
//             }
//         }
//         printf("%d\n",sum);
//     }
//     return 0;
// }
