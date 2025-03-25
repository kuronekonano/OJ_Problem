#include <algorithm>
#include <stack>
#include <stdio.h>
#include <string.h> ///�����޻�ͼDAG   ������
using namespace std;
int n, low[108], dfn[108], cnt, out, in, num,
    id[108]; /// low�������ڴ洢��С����ʱ�䣬id�洢�ڵ������ĸ�ǿ��ͨͼ
bool maps[108][108],
    vis[108]; /// maps�����ڽӾ�������ͨͼ��vis���ڱ�ǽڵ��Ƿ���ջ��
stack<int> q;
void tarjan(int u) /// tarjan�㷨
{
  int i;
  low[u] = dfn[u] = ++cnt;
  q.push(u);     /// ��ջ
  vis[u] = true; /// ���u�ڵ���ջ��
  for (i = 1; i <= n; i++) {
    if (!maps[u][i])
      continue;
    if (!dfn[i]) {
      tarjan(i);
      low[u] = min(low[u], low[i]);
    } else if (vis[i]) /// ע����������ջ�еĵ�����ڸ���u����lowֵ
    {
      low[u] = min(low[u], dfn[i]);
    }
  }
  if (low[u] == dfn[u]) /// �ж�ǿ��ͨͼ����������lowֵ����dfuֵʱ��˵����ʱΪ
                        /// ���������ĸ��ڵ�
  {
    num++;             /// ǿ��ͨͼ��������
    while (!q.empty()) /// ��ʱջ�д洢����ǿ��ͨͼ�����нڵ�
    {
      int tmp = q.top();
      q.pop(); /// ��ջʱӦ��ȡ���ڵ�ı��
      id[tmp] = num;
      vis[tmp] = 0; /// ȡ�����
      if (tmp ==
          u) /// ֱ��Ѱ�ҵ�ջ���еĵ�tmp�������ڱ����ĵ�uʱ�����ǿ��ͨͼ�����е�Ѱ�����
      {
        break;
      }
    }
  }
}
int main() {
  int i, inum[108], outnum[108], j;
  while (scanf("%d", &n) != EOF) {
    memset(vis, false, sizeof(vis));
    memset(maps, false, sizeof(maps));
    memset(low, 0, sizeof(low));
    memset(dfn, 0, sizeof(dfn));
    memset(inum, 0, sizeof(inum));
    memset(outnum, 0, sizeof(outnum));
    memset(id, 0, sizeof(id));
    while (!q.empty())
      q.pop();
    cnt = out = in = num = 0;
    for (i = 1; i <= n; i++) {
      int u;
      while (scanf("%d", &u) && u) {
        maps[i][u] = true;
      }
    }
    for (i = 1; i <= n; i++) /// �����㣬Ҳ����ǿ��ͨ��������
    {
      if (!dfn[i]) {
        tarjan(i); /// ����Ҫ�������е㣬��Ϊ���ͼ��һ�������е�Ķ���ͨ��
      }
    } /// ������󣬾��Ѿ��ҵ�������ǿ��ͨ������
    //        for (i=1; i<=n; ++i)
    //            printf("%3d",id[i]);
    //        puts("");
    for (i = 1; i <= n; i++) /// �����ÿ��������ӽ��б���
    {
      for (j = 1; j <= n; j++) {
        if (maps[i][j] &&
            id[i] != id[j]) /// ������������ӣ�����i����j�㲻����һ��ǿ��ͨ����
        {
          inum[id[j]]++;   /// j����Ϊ��ȣ��൱��i���ڵ�ǿ��ͨ���� �з����
                           /// ����j����ǿ��ͨ����
          outnum[id[i]]++; /// i�ǳ���
        }
      } /// ����������е�ǿ��ͨ��������Ⱥͳ��ȼ�������i��ǿ��ͨ�����������inum������,����λ��outnum������
    }
    for (i = 1; i <= num;
         i++) /// ���ͳ��һ�£�����ǿ��ͨ������0��Ⱥ�0���ȵĸ���
    {
      if (!inum[i])
        in++;
      if (!outnum[i])
        out++;
    }
    if (num ==
        1) /// �������ͼֻ��һ��ǿ��ͨ��������ô��ֻ��һ������Ϊ0��һ�����Ϊ0�ĵ�
    {
      printf("1\n0\n"); /// Ҫ���У�ֻ�÷�һ��������ɣ����Ҳ��üӱ�
    } else {
      printf(
          "%d\n%d\n", in,
          max(in,
              out)); /// ������ǣ��������������0��ȵĵ������(���ڵ�)����Ҫ�ӵı��������ǽ�0��ȵ�����0���ȵģ�˭�������Ǽ�����
    }
  }
  return 0;
}
