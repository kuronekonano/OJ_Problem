#include <queue>
#include <stdio.h> ///也可以用数组实现
#include <string.h>
using namespace std;
int main() {
  bool vis[1008];
  int i, n, m, x;
  while (scanf("%d%d", &n, &m) != EOF) {
    queue<int> q, p;
    while (!q.empty())
      q.pop();
    while (!p.empty())
      p.pop();
    memset(vis, false, sizeof(vis));
    for (i = 0; i < m; i++) {
      scanf("%d", &x);
      vis[x] = true;
    }
    for (i = n * m; i >= 1; i--) {
      if (vis[i])
        q.push(i);
      else
        p.push(i);
    }
    int ans = 0;
    while (!q.empty()) {
      if (q.front() > p.front()) {
        ans++;
        q.pop();
      } else {
        q.pop();
        p.pop();
      }
    }
    printf("%d\n", ans);
  }
}
// #include<stdio.h>///数组实现
// #include<string.h>
// int main()
//{
//     int i,n,m,x;
//     bool vis[1008];
//     while(scanf("%d%d",&n,&m)!=EOF)
//     {
//         memset(vis,false,sizeof(vis));
//         for(i=0;i<m;i++)
//         {
//             scanf("%d",&x);
//             vis[x]=true;
//         }
//         int flag=1,ans=0,j=n*m;i=j;
//         while(vis[j])j--;
//         while(!vis[i])i--;
//         while(flag<m)
//         {
//             if(i>j)
//             {
//                 ans++;
//                 flag++;
//                 i--;
//                 while(!vis[i])i--;
//             }
//             else
//             {
//                 flag++;
//                 i--;
//                 while(!vis[i])i--;
//                 j--;
//                 while(vis[j])j--;
//             }
//         }
//         printf("%d\n",ans);
//     }
// }
