#include <algorithm>
#include <stdio.h> ///��ȫ����
#include <string.h>
using namespace std;
struct brave {
  int cost, w;
} a[1005];
int main() {
  int t, i, j, n, m, s;
  scanf("%d", &t);
  while (t--) {
    scanf("%d%d", &n, &m); /// n������������m����Ҫ������
    for (i = 0; i < n; i++) {
      scanf("%d%d", &a[i].cost, &a[i].w);
    }
    bool flag = false;
    for (i = 1;; i++) /// �ݻ���Ϊ�õ���С�ݻ������1��ʼ,��ôdp����Ҳ����֮����
    {
      int dp[i + 5]; /// �����±�123456��������ʾ��ǰ�ݻ������ܴ��µ�����ֵ
      memset(dp, 0, sizeof(dp));
      for (j = 0; j < n; j++) /// ѡ����Ʒ
      {
        for (
            s = a[j].cost; s <= i;
            s++) /// �����j����Ʒ����Ŀǰ���������ݻ�i����ô�����Ʒ����ʱ����ŵ������������s�ǵ�ǰ�����ݻ���ֵ
        { /// ����dp[s-a[j].cost]��ֱ�ӵ������������Ʒ���ݻ�������ֵ�Ƕ���
          dp[s] = max(
              dp[s],
              dp[s - a[j].cost] +
                  a[j].w); /// ÿ��ֻ��һ����Ʒ���������Ʒ��ʱ�򣬽��ῼ�ǵ�ǰ�ݻ�����������Ƿ���
          if (dp[s] >= m) {
            flag = true; /// ��������Ҫ������ֵʱ������ѭ��
            break;
          }
        }
        if (flag) {
          break;
        }
      }
      if (flag) {
        break;
      }
    }
    printf("%d\n", i); /// ��ô��ǰ���ݻ�i������С����
  }
}
