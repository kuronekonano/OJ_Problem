#include <algorithm> ///ʹ�˷�ԽСԽ�ã����ȫ������1λ*1λ�������п��ܣ�������ﵽ2λ����ʹ�������ĳ������ǻ�ܴ������ȼ�������
#include <stdio.h> ///ʹǰ�澡���ܶ��λ�������������Ǿ��γ���nλ��+1λ���ļӷ�����
#include <string.h> ///��Ϊ����ĳ˺ͳ��Ǳ���ȥ�ģ����Ҫ������С����ô��Ϊ������Ҫ������������Ż�С��
using namespace std; /// ��ô������ʹ��ȥ����Ϊ0�����������˽������С�ڳ�������Ϊ������������81����˳���������һ��2λ������3λ��������ȥ����˷����
int main()           /// ֻ��3�������һ�ַָ��˳�3λ���˳���һλ��
{ /// ���˷�����ʱ���Ӽӷ�λ�������Ųһλ������λ���ټ���ȡ���ֵ����������ָ��˳�4λ���˷���һλ������2λ
  int t, i,
      cas =
          0; /// ���һ�֣�����λ�˷��˻��Դ��ں���λ����ʱ�������Ӽ����м����Ųһλ������������3λ�϶���С��1�ģ��ָ��˳�5λ���˷���һλ��������3λ
  scanf(
      "%d",
      &t); /// ����ǵ�һ�������5λ���س����������ǵڶ��������6λ����ѡһȡ�������������6λ���ڵ�һ�ڶ��������ֵ������������ȡmax���õ����
  while (t--) {
    cas++;
    char str[25];
    int a[25];
    scanf("%s", str);
    int l = strlen(str);
    for (i = 0; i < l; i++)
      a[i] = str[i] - '0';
    long long numa = 0, numb = 0;
    for (i = 0; i < l - 4; i++)
      numa = numa * 10 + a[i];
    numa += a[l - 4];
    for (i = 1; i < l - 3; i++)
      numb = numb * 10 + a[i];
    numb += a[0];
    long long sum = max(numa, numb);
    if (l == 5) {
      printf("Case #%d: %lld\n", cas, sum - (a[l - 3] * a[l - 2] / a[l - 1]));
      continue;
    }
    numa = 0, numb = 0;
    for (i = 0; i < l - 5; i++)
      numa = numa * 10 + a[i];
    numa += a[l - 5];
    for (i = 1; i < l - 4; i++)
      numb = numb * 10 + a[i];
    numb += a[0];
    long long sum2 = max(numa, numb);
    sum = max(sum - (a[l - 3] * a[l - 2] / a[l - 1]),
              sum2 - (a[l - 4] * a[l - 3]) / (a[l - 2] * 10 + a[l - 1]));
    if (l == 6) {
      printf("Case #%d: %lld\n", cas, sum);
      continue;
    }
    numa = 0, numb = 0;
    for (i = 0; i < l - 6; i++)
      numa = numa * 10 + a[i];
    numa += a[l - 6];
    for (i = 1; i < l - 5; i++)
      numb = numb * 10 + a[i];
    numb += a[0];
    sum2 = max(numa, numb);
    sum = max(sum, sum2 - (a[l - 5] * a[l - 4]) /
                              (a[l - 3] * 100 + a[l - 2] * 10 + a[l - 1]));
    printf("Case #%d: %lld\n", cas, sum);
  }
}
