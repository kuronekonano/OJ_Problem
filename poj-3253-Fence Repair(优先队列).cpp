#include <queue>   ///����vector������Ȼ����Ҫ����ͷ�ļ���
#include <stdio.h> ///���ȶ�����
using namespace std;
int main() {
  int i, n;
  long long a;
  while (scanf("%d", &n) !=
         EOF) /// ע�⣬����·����ұ�ʹ����>>�ᱨ������ճ������Ҫ�ÿո�ֿ�
  {
    priority_queue<long long, vector<long long>, greater<long long>> q;
    for (i = 0; i < n; i++) /// ������greater�Ǵ�С��������ȼ���less�ǴӴ�С
    {
      scanf("%lld", &a);
      q.push(a); /// ����
    }
    if (n == 1) {
      printf("%lld\n", q.top());
      q.pop();
      continue;
    }
    long long sum = 0, small, smaller;
    while (q.size() > 1) {
      small = q.top();
      q.pop(); /// ����
      smaller = small + q.top(); /// ѡȡ���к���С�ģ���ӣ��൱��������С�ĺϳ�һ�ѣ������õ����ǣ�����Ҫ8
                                 /// 5 8���ֳ���ʱ
      q.pop(); /// ȡ����С���������ȣ��ϳ�һ��ľ�壬�ϳɺ�ĳ��Ⱦ�����Ҫ�и�����ĳ��ȣ���ô��Ҫ������ô��
      sum =
          sum +
          smaller; /// �ϳɺ���ͼ���sum�У�Ȼ���ٽ��ϳɺ�ĳ���������У���������ѡ����̵����鳤�Ȳ��ϳ�
      q.push(
          smaller); /// ֱ�����պϳɵ���n��ľ��һ���е��ܳ��ȣ�ֻ�����ϳɵ�·�����и���ã���������С�����
    }
    printf("%lld\n", sum);
  }
  return 0;
}
