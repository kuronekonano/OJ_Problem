#include <stdio.h> ///����ȡģ
#include <string.h>
char a[109];
int num[109], pri[1000008];
bool vis[1000008];
int tp = 0;
int poww(int a, int b) /// ������(��Ϊ��math��pow������ֵľ�����ʧ)
{
  int tmp = a, ans = 1;
  while (b != 0) {
    if (b & 1)
      ans *= tmp;
    tmp *= tmp;
    b /= 2;
  }
  return ans;
}
void inti() /// ������
{
  memset(vis, true, sizeof(vis));
  for (int i = 2; i <= 1000003; i++) {
    if (vis[i]) {
      pri[tp++] = i;
      for (int j = i + i; j <= 1000003; j += i) {
        vis[j] = false;
      }
    }
  }
}
int main() {
  inti();
  int low;
  while (scanf("%s %d", a, &low) != EOF) {
    memset(num, 0, sizeof(num));
    if (a[0] == '0' && strlen(a) == 1 && low == 0)
      break;
    int n = strlen(a), sum = 0, flag = 0, ww = 0;
    for (int i = n - 1; i >= 0; i--) /// ������ǧ���Ʋ��
    {
      sum += (a[i] - '0') * poww(10, flag); /// �Ӹ�λ��ʼÿ3λΪһ����
      flag++;
      if (flag == 3) {
        num[ww++] = sum;
        flag = 0;
        sum = 0;
      }
    }
    if (sum != 0)
      num[ww++] = sum;
    bool ans = false;
    for (int i = 0; i < tp; i++) {
      if (pri[i] >= low)
        break; /// ����ǰ������������lowֵ˵����lowֵ�����Ҳ���һ������ʹ����������ô��С������������lowֵ֮��
      flag = 0;
      for (int j = ww - 1; j >= 0; j--) /// ��ͬ��ģ��ģ����ʽ��ģ(����ȡģ)
      {
        flag = (flag * 1000 + num[j]) % pri[i];
      }
      if (flag ==
          0) /// ���ҵ�һ����������������˵���������С������޶�lowֵ���Ϸ��Ѿ��жϣ�ֱ�ӱ��BAD����¼����
      {
        n = pri[i];
        ans = true;
        break;
      }
    }
    if (ans)
      printf("BAD %d\n", n);
    else
      printf("GOOD\n");
  }
}
