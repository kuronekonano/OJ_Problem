#include <stdio.h>
struct jump // ��Ʒ�������޺ͽ��۶ȴ������
{
  int sub;   // ���ۼ۸�
  int price; // �ﵽ���۵ı�׼
} a[1005];

int main() {
  int t, m, n, x, y, i;
  scanf("%d", &t);
  a[0].sub = 0,
  a[0].price = 0; // �����һ����0�ĳ�ʼ�����Ա�֤���ܽ��۵���Ʒԭ�ۼ���
  while (t--) {
    scanf("%d%d", &n, &m); // ��n����׼��m����Ʒ
    for (i = 1; i <= n; i++) {
      scanf("%d%d", &a[i].sub, &a[i].price);
    }
    int sum = 0, flag;
    for (i = 1; i <= m; i++) {
      scanf("%d", &flag);
      int max = 10000000; // �������ֵ����ȡ����ӽ���ǰ��Ʒ�ۼ۵���߱�׼
      int h = 0;          // ��֤���ڳ�ʼ����λ�ã��Դﵽԭ�۳��۵�Ŀ��
      for (int j = 1; j <= n; j++) {
        if ((max >= flag - a[j].price) &&
            (flag - a[j].price >=
             0)) // ���㵱ǰĿ��
                 // ��Ʒ�͵�ǰ�����Ľ��۱�׼֮���Сֵ��Ϊ��ӽ����Ǹ���׼
        {
          max = flag - a[j].price;
          h = j;
        }
      }
      sum += flag - a[h].sub; // ���
    }
    printf("%d\n", sum);
  }
  return 0;
}
