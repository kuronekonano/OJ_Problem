#include <bits/stdc++.h>
using namespace std;
int main() {
  int len, n, a[100005];
  while (scanf("%d%d", &len, &n) != EOF) {
    if (len == 0 && n == 0)
      break;
    for (int i = 0; i < len; i++)
      scanf("%d", &a[i]);
    sort(a, a + len);
    int l = 1, r = 99999999;
    while (l <= r) /// ���ִ𰸣���������Ϊֹ
    {
      int mid = (l + r) / 2, pos = 0, cnt = 0;
      for (int i = 1; i < len; i++) {
        if (a[i] - a[pos] >= mid) {
          cnt++; /// �Է���������·�μ���
          pos =
              i; /// ���Ҽ�¼����������λ�ã��Ա���һ���ҵ����λ�ü����������
        }
      }
      if (cnt >= n - 1)
        l = mid + 1;
      else
        r = mid - 1;
      //            printf("----%d  %d  %d  %d\n",l,r,mid,cnt);
    }
    printf("%d\n",
           r); /// ��Ϊ����߽�����ұ߽�ʱ�Ž������֣�������ұ߽�λ���ս��
  }
}
