#include <bits/stdc++.h> ///������жϣ������ҵ�������˭��*
#define LL long long
#define M(a, b) memset(a, b, sizeof a)
using namespace std;
const int maxn = 2e5 + 7;
int n, t, m;
char a[maxn], b[maxn];
int main() {
  while (scanf("%d%d", &n, &m) != EOF) {
    bool flag = true;
    scanf("%s %s", a, b);
    int pos = -1;
    for (int i = 0; i < n; i++) {
      if (a[i] == '*') {
        pos = i;
        break;
      }
    }
    if (pos == -1) {
      for (int i = 0; i < m; i++)
        if (b[i] == '*') {
          pos = i;
          break;
        }
      if (pos == -1) /// �����߶�û��*
      {
        if (n != m) /// �жϳ���
        {
          printf("NO\n");
          continue;
        }
        for (int i = 0; i < n; i++) /// �ж�ÿ���ַ��Ƿ�һ��
        {
          if (a[i] != b[i]) {
            printf("NO\n");
            flag = false;
            break;
          }
        }
        if (!flag)
          continue; /// ������û��continue������ν��
        else {
          printf("YES\n");
          continue;
        }
      }
      if (pos > n) ///*��b����
      {
        printf("NO\n"); /// ���Ǻ�λ�ô���a�����ȣ���ô�϶����������
        continue;
      }
      if (m - 1 > n) /// ��ʣ��b�����ȴ���a�����ȣ�ͬ��������
      {
        printf("NO\n");
        continue;
      }
      for (int i = 0; i < min(pos, n); i++) /// �����Ǻ�֮ǰλ���Ƿ����
      {
        if (a[i] != b[i]) {
          printf("NO\n");
          flag = false;
          break;
        }
      }
      if (!flag)
        continue;
      for (int i = n - 1, j = m - 1; j > pos && i > 0;
           j--, i--) /// �����Ǻ�֮��λ���Ƿ����
      {
        if (a[i] != b[j]) {
          printf("NO\n");
          flag = false;
          break;
        }
      }
    } else ///*��a����
    {
      if (pos > m) {
        printf("NO\n");
        continue;
      }
      if (n - 1 > m) {
        printf("NO\n");
        continue;
      }
      for (int i = 0; i < min(pos, m); i++) {
        if (a[i] != b[i]) {
          printf("NO\n");
          flag = false;
          break;
        }
      }
      if (!flag)
        continue;
      for (int i = n - 1, j = m - 1; i > pos && j > 0; i--, j--) {
        if (a[i] != b[j]) {
          printf("NO\n");
          flag = false;
          break;
        }
      }
    }
    if (flag)
      printf("YES\n");
  }
}
