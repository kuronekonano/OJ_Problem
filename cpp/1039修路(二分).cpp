#include <stdio.h> ///����Ӧ��
int a[307], time, m, n;
bool ok(int m, int n, int maxi) // Ͷ�����ʱ��
{
  int get = 0;                // �ѷ���·��
  for (int i = 0; i < n; i++) // ѭ���ж�ÿ�����̶ӵĹ�����
  {
    int maxj = 0; // ��ʼ��ÿ�����̶ӵĹ�����
    int j;
    for (j = get; j < m; j++) {
      maxj = maxj + a[j]; // ��͵�i���ӵĹ�����
      if (maxj > maxi)    // ������ʱ�䳬�����ʱ��
      {
        break;
      }
    }
    get = j; // ���䵽��j��·
    if (get == m) {
      return true; // ��·�η�����ɣ��򷵻�true
    }
  }
  return false; // ���򷵻�false
}
int solve(int m, int n, int big) // ���ֺ���
{
  int l = 0, r = big; // �趨�������߼�ֵ
  time = big;         // �����ʱ����Ϊ���ʱ��
  while (l <= r) {
    int mid = (l + r) / 2; // ȡ�е��ж�
    if (ok(m, n, mid))     // Ͷ�е�ʱ��
    {
      time = mid; // �����ؿ��Է����꣬���ʾʵ��ʹ��ʱ��С���е�
      r = mid - 1;
    } else {
      l = mid + 1; // ���ܷ��������ʾʵ��ʩ��ʱ������е�ʱ��
    }
  }
  return time; // ������ֵ�������ֵ������ѭ����������ʱ��
}
int main() {
  int i, t;
  scanf("%d", &t);
  while (t--) {
    scanf("%d%d", &m, &n);
    int sum = 0;
    for (i = 0; i < m; i++) {
      scanf("%d", &a[i]);
      sum = sum + a[i]; // ����������ʱ��
    }
    time = solve(m, n, sum);
    printf("%d\n", time);
  }
  return 0;
}
