#include <bits/stdc++.h>
using namespace std;
vector<int> son[100005];
int n, tmp;
int dfs(int i) {
  if (son[i].size() == 0)
    return 0;
  vector<int> pri;
  for (int j = 0; j < son[i].size();
       j++) /// �õ��ýڵ����е��ӽڵ㣬����ÿ���ӽڵ㣬��ȶ����Լ�������
    pri.push_back(dfs(son[i][j]));
  int maxn = 1;
  sort(pri.begin(), pri.end());
  for (int j = 0; j < pri.size();
       j++) /// �ӽڵ�������ҳ��������ģ���Ϊ����ȷ���
  {
    if (pri[j] + pri.size() - j > maxn)
      maxn =
          pri[j] - j +
          pri.size(); /// size��ʾ�ò�ҪӮ�ñ�����Ҫ�ߵ���С��ȣ��ڴ˻����Ͼ�̯ʹ�������С��Ȼ�󷵻�ֵΪ�����ȣ�������Ϊ��ǰ������С��ȼ��Ͼ�̯�������������
  } /// λ��j��ʾ��С�������ȣ�˵����Щ����ں�ʱ��i����սʹ����Ȼ���С��������̯��ʹ��������ȵ����ƣ�Ҳ����ʹ��j��С��ʱ����Ͻϴ���������
  return maxn;
}
int main() {
  while (scanf("%d", &n) != EOF) {
    for (int i = 0; i <= n; i++)
      son[i].clear();
    for (int i = 2; i <= n; i++) {
      scanf("%d", &tmp);
      son[tmp].push_back(i);
    }
    printf("%d\n", dfs(1));
  }
}
