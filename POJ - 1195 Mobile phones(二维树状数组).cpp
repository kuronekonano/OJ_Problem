#include <stdio.h> ///��ά��״����ģ����
#include <string.h>
#define LL long long
LL tre[1036][1036];
int n;
int lowbit(int x) { return x & (-x); }
void update(
    int x, int y,
    int add) /// ������£��Ա���������ǰ׺�͸���x��y������n ������Ϊlowbit(i)
{
  for (int i = x; i <= n; i += lowbit(i))
    for (int j = y; j <= n; j += lowbit(j))
      tre[i][j] += add;
}
LL sum(int x, int y) /// ���
{
  LL sum = 0;
  for (int i = x; i > 0; i -= lowbit(i))
    for (int j = y; j > 0; j -= lowbit(j))
      sum += tre[i][j];
  return sum;
}
int main() {
  int flag;
  while (scanf("%d", &flag) != EOF) {
    if (flag == 0) /// ����0ʱ�������
    {
      memset(tre, 0, sizeof(tre));
      scanf("%d", &n);
    } else if (flag == 1) /// ����1ʱ�������޸�
    {
      int x, y, add;
      scanf("%d%d%d", &x, &y, &add);
      x++;
      y++; /// ע����Ŀ�Ǵ�0,0�����꿪ʼ�ģ�ֱ��n-1������״������ΪҪlowbit�����ش�1��ʼn����������������Ӧ+1��ʾ��״�����д洢��λ��
      update(x, y, add);
    } else if (flag == 2) /// ����2ʱ������Ͳ�ѯ
    {
      int x1, y1, x2, y2;
      scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
      x1++;
      y1++;
      x2++;
      y2++;
      printf("%lld\n",
             sum(x2, y2) - sum(x1 - 1, y2) - sum(x2, y1 - 1) +
                 sum(x1 - 1, y1 - 1)); /// �ݳ�ԭ��ɾ�������ظ���ȥ������
    } else
      break;
  }
}
