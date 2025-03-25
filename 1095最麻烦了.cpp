#include <algorithm>
#include <cstring>
#include <stdio.h>
using namespace std;
struct man {       // ����һ���ṹ���Ӧ��ʵ������������һ���ṹ��man
  long long mark;  // ���������ˣ���Ϊ�޶����ֵΪ10��9�η�������ȫ����long long
  long long money; // ��Ǯ
  long long rp;    // ��Ʒ����
} men[1005];       // ������������ֵΪ1000��
int cmp(man a, man b) // ���ǶԱȺ����Ķ��壬���У�������Ϊcmp��������������������man
                      // a,man b����a��b���Ƚ�
{
  if (a.mark == b.mark) // ���ɼ���ͬ
  {
    if (a.money == b.money) // ����Ǯ��ͬ
    {
      return a.rp > b.rp; // �Ա���Ʒ
    }
    return a.money > b.money; // �ԱȽ�Ǯ
  }
  return a.mark >
         b.mark; // �Աȳɼ�����Ϊ������������Խ�����ǰ�棬Ϊ��׼�Ľ�������
}
int main() {
  int n, i;
  while (scanf("%d", &n) != EOF) {
    for (i = 0; i < n; i++) {
      scanf("%lld%lld%lld", &men[i].mark, &men[i].money, &men[i].rp);
    }
    sort(men, men + n, cmp);
    for (i = 0; i < n; i++) {
      printf("%lld %lld %lld\n", men[i].mark, men[i].money, men[i].rp);
    }
  }
  return 0;
}
