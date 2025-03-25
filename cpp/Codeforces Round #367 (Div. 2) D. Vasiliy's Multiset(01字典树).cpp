#include <bits/stdc++.h> ///01�ֵ���
#define LL long long
#define M(a, b) memset(a, b, sizeof a)
using namespace std;
const int maxn = 1e5 + 7;
int tre[maxn << 5][2];
int cnt[maxn << 5]; /// ��ǽڵ��߹��������Ͳ��ù���ԭ�ڵ��������ĸ������
int q, tot = 0;
char flag[3];
void insert(int a, int rt, int add) {
  for (int i = 31; i >= 0; i--) {
    int x = (a >> i) & 1;
    if (!tre[rt][x]) {
      tre[rt][x] = ++tot;
      M(tre[tre[rt][x]], 0);
    }
    rt = tre[rt][x];
    cnt[rt] += add; /// ɾ���Ͳ�����Ƕ�ĳ���ڵ�ľ�����������
  }
}
int finds(int a, int rt) {
  int ans = 0;
  for (int i = 31; i >= 0; i--) {
    ans <<= 1;
    int x = (a >> i) & 1;
    if (tre[rt][!x] && cnt[tre[rt][!x]])
      rt = tre[rt][!x], ans |= 1; /// ����ͬʱ������������������������������
    else
      rt = tre[rt][x];
  }
  return ans;
}
int main() {
  int tmp, rt = ++tot;
  M(tre[rt], 0);
  M(cnt, 0);
  scanf("%d", &q);
  while (q--) {
    scanf("%s", flag);
    scanf("%d", &tmp);
    if (flag[0] == '+')
      insert(tmp, rt, 1);
    else if (flag[0] == '-')
      insert(tmp, rt, -1);
    else
      printf(
          "%d\n",
          max(tmp,
              finds(
                  tmp,
                  rt))); /// ��Ϊ0һֱ�ڸ�������˱�����һ����������0(����Լ�)����򼯺���ĳ������ȡ���ֵ
  }
  return 0;
}
