#include <bits/stdc++.h> ///��Ҫע����ǣ�ֻҪ���һ��ѯ��Ⱦɫû�г���λ�ã���һ������
#define LL                                                                     \
  long long /// ������0�Ĵ��������ѯ��û�а���λ��ʱ�����Ȱ������ѯ��ʹ���н⣬�����н��������������޽���
#define M(a, b)                                                                \
  memset(                                                                      \
      a, b,                                                                    \
      sizeof a) /// ʣ�������ֻҪ��֤�����ڲ����ڱ��Լ�С���������ˣ���ôֱ��������һ��������һ������
#define pb(x) push_back(x)
using namespace std;
const int maxn = 2e5 + 7;
int a[maxn], lpos[maxn];
int main() {
  int n, q;
  while (scanf("%d%d", &n, &q) != EOF) {
    int cnt = 0;
    bool flag = true;
    M(lpos, 0);
    for (int i = 1; i <= n; i++) {
      scanf("%d", &a[i]);
      if (a[i])
        lpos[a[i]] = i;
      else
        cnt++;
    }
    for (int i = 2; i <= n; i++)
      if (a[i]) {
        if (a[i] < a[i - 1] && lpos[a[i - 1]] > i) {
          flag = false;
          break;
        }
      } else {
        if (!lpos[q]) {
          a[i] = q;
          lpos[q] = i;
        } else
          a[i] = a[i - 1];
      }
    if (!lpos[q] && cnt == 0)
      flag = false; /// ���û�а���λ�ã��������ѯ��û�а��壬�Ǿ�GG��
    if (!flag)
      printf("NO\n");
    else {
      printf("YES\n");
      if (cnt == n)
        for (int i = 1; i <= n; i++)
          printf("%d%c", q, i == n ? '\n' : ' ');
      else {
        for (int i = n - 1; i >= 1; i--)
          if (!a[i])
            a[i] = a[i + 1];
        for (int i = 1; i <= n; i++)
          printf("%d%c", a[i], i == n ? '\n' : ' ');
      }
    }
  }
}
