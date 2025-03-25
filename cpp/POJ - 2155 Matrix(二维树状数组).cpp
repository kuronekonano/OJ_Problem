#include <stdio.h>
#include <string.h>
int tre[1005][1005];
int n, t;
int lowbit(int x) { return x & (-x); }
void update(int x, int y) /// ��ά���º���
{
  for (int i = x; i <= n; i += lowbit(i))
    for (int j = y; j <= n; j += lowbit(j))
      tre[i][j]++; /// ����������£������ݳ�ԭ����������ĸ��ڵ���и��²���
}
int sum(int x, int y) /// ��ά��ѯ
{
  int sum = 0;
  for (int i = x; i > 0; i -= lowbit(i))
    for (int j = y; j > 0; j -= lowbit(j))
      sum += tre[i][j];
  return sum;
}
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%d%d", &n, &t);
    memset(tre, 0, sizeof(tre));
    while (t--) {
      char flag[3];
      scanf("%s", flag);
      if (flag[0] == 'C') {
        int x1, y1, x2, y2;
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        update(x1,
               y1); /// ע���ݳ�ԭ����£�ÿ�θ����ĸ��ڵ㣬ÿ���ڵ�Ӵ��δ���ʼ
        update(x1, y2 + 1); /// �����ұ߽���±߽磬��+1�Ĵ���
        update(x2 + 1, y1);
        update(x2 + 1, y2 + 1);
      } else {
        int x, y;
        scanf("%d%d", &x, &y);
        printf("%d\n", sum(x, y) % 2); /// ��ѯǰ׺�ͽ��%2����ѯ�ڵ㵱ǰ״̬
      } /// ����һ������L��R����ǰ׺��ʱ����ȡ�������֮�ڵ����꣬���ֻ��Lλ�õ�1��δȡ��Rλ�õ�1�����ʱ1����2����ô%2�����õ���λ������Ϊ1������Ϊ0�����ڸ��ǵ�����Ҳ����ˣ�����1�ĸ����õ�ȡ������״̬
    }
    printf("\n");
  }
}
