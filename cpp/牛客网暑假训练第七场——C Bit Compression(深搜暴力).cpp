#include <bits/stdc++.h>
using namespace std;
const int maxn = 1 << 18 + 3;
char str[maxn]; /// ������Ц���ˣ��ַ���д����int�ͣ�������Ȼ�ܹ�
int num[maxn];
int DFS(int x) {
  int ans = 0;
  if (x == -1)
    if (num[1] == 1)
      return 1;
    else
      return 0;
  int s = 1 << x;
  for (int i = 0; i < 3; i++) {
    int cnt = 0;
    for (int j = 0; j < s; j++) {
      int tmp = j + s;
      if (i == 0)
        num[tmp] = num[tmp << 1] ^ num[tmp << 1 | 1];
      else if (i == 1)
        num[tmp] = num[tmp << 1] | num[tmp << 1 | 1];
      else
        num[tmp] = num[tmp << 1] & num[tmp << 1 | 1];
      if (!num[tmp])
        cnt++;
    }
    if (cnt == s)
      continue; /// ���������1�ˣ���ô�������˳�򲻻�õ�1����û��������ȥ�ı�Ҫ�ˣ���һ��С��֦
    else
      ans += DFS(x - 1);
  }
  return ans;
}
int main() {
  int n;
  scanf("%d", &n);
  scanf("%s", str);
  int s = 1 << n; /// ��2^n��������n������������� �� ����������
  for (int i = 0; i < s; i++)
    num[i + s] = str[i] - '0'; /// ��ôһ��ʼ����Щ�ַ����뵽2^n֮����±괦
  int ans = DFS(n - 1);        /// ���ѱ��������n��ʾʣ���������
  printf("%d\n", ans);
}
