// #include<stdio.h>///LCA����������Ȳ�ѯ�������㷨
// #include<string.h>
// int fa[10008];
// int deep(int x)///����x�ڵ����
//{
//     int cnt=0;
//     while(x)
//     {
//         cnt++;
//         x=fa[x];
//     }
//     return cnt;
// }
// int main()
//{
//     int t,n;
//     scanf("%d",&t);
//     while(t--)
//     {
//         memset(fa,0,sizeof(fa));///�������¼ÿ���ڵ�ĸ��ף����ڵ㸸��Ϊ0
//         int s,f;
//         scanf("%d",&n);
//         for(int i=0;i<n-1;i++)
//         {
//             scanf("%d%d",&f,&s);
//             fa[s]=f;
//         }
//         int a,b;
//         scanf("%d%d",&a,&b);
//         int aa=deep(a),bb=deep(b);
//         if(aa<bb)///��ѯ������������ڵ���Ȳ�ͬ��������Ľڵ�������
//         {
//             int tt=bb-aa;
//             while(tt--)
//                 b=fa[b];
//         }
//         else if(aa>bb)
//         {
//             int tt=aa-bb;
//             while(tt--)
//                 a=fa[a];
//         }
//         while(a!=b)///�����ڵ������ͬʱͬʱ����Ѱ�Ҹ��ף�ֱ��������ͬ
//             a=fa[a],b=fa[b];
//         printf("%d\n",a);
//     }
// }
/// LCA������
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
#define M(a, b) memset(a, b, sizeof(a))
#define pb push_back
int n;
int fa[15][10005], dep[10005];
vector<int> g[10005];
void dfs(int u) /// �������
{
  if (g[u].size() == 0) /// û�ж��ӵ�Ҷ�ӽ��ֱ�ӷ���
    return;
  for (int i = 0; i < g[u].size(); ++i) /// �����ý�����ж���
  {
    int v = g[u][i];
    dep[v] = dep[u] + 1; /// ���ӽ��v����ȵ��ڸ��׵����+1
    dfs(v);              /// �������Ҷ��ӵĶ��ӵ����
  }
}
void init() /// Ԥ����������
{
  for (int i = 0; i < 13; ++i)   /// ĳ���������2��13���ݵ����ȼ�¼
    for (int j = 1; j <= n; ++j) /// �������н��
    {
      if (fa[i][j] == -1)
        continue; /// ���ڵ�����
      fa[i + 1][j] = fa
          [i]
          [fa[i]
             [j]]; /// ������2��i+1���ݵĽ��j�ĸ��ף�����2��i���ݵĽ��j�ĸ��׵ĸ���
    }
}
int lca(int u, int v) {
  if (dep[u] > dep[v])
    swap(u, v);                 /// �涨v������Ǵ���u��ȵĽ��
  for (int i = 13; i >= 0; --i) /// ���������Ȳ�ͬ
    if ((dep[v] - dep[u]) &
        (1 << i)) /// �������֮��Ķ����ƣ��жϵ�iλ��0����1����1��������
      v = fa[i][v];

  if (u ==
      v) /// ͳһ���֮�����������ͬ����ֱ�ӷ��ظý��������ʾ�����Ǹ���ȵ͵��ǹ�������
    return u;

  for (int i = 13; i >= 0; --i) /// �����ͬʱ��������
    if (fa[i][u] != fa[i][v]) {
      u = fa[i][u];
      v = fa[i][v];
    }
  return fa[0][u];
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
      g[i].clear();
    M(fa, -1);
    M(dep, 0);
    for (int i = 1; i < n; ++i) /// ����
    {
      int u, v;
      scanf("%d%d", &u, &v);
      fa[0][v] = u; /// ��¼ÿ���ڵ�v��ֱ�Ӹ���u
      g[u].pb(v);   /// ��u��ֱϵ���������ӽ��v
    }
    int rt;
    for (int i = 1; i <= n; ++i) /// �Ҹ��ڵ�
      if (fa[0][i] == -1) {
        rt = i;
        break;
      }
    dep[rt] = 1; /// ���������ȶ�Ϊ1
    dfs(rt);     /// �������н��
    init();
    int u, v;
    scanf("%d%d", &u, &v);
    printf("%d\n", lca(u, v));
  }
  return 0;
}
