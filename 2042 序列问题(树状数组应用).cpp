#include <algorithm>
#include <stdio.h>
#include <string.h>
using namespace std;
int tree[50005], n;
struct num /// �ṹ�����ڴ洢��ֵ��С�Լ�ÿ������λ��
{
  int val, i;
} a[50005]; /// ��ΪҪ�������Ĵ�С����λ�򽫻���ң����Ҫ�洢λ��
bool cmp(num a, num b) { return a.val < b.val; }
int lowbit(
    int x) /// ��״���鲻�ܴ�0λ��ʼ��ֵ��Ӧ�ô�1λ��ʼ����Ϊ0λ��&0����0���޷�����ָ��������
{
  return x & (-x);
}
void update(int p, int x) {
  while (p <= n) {
    tree[p] += x;
    p += lowbit(p);
  }
}
int sum(int p) {
  int sum = 0;
  while (p > 0) {
    sum += tree[p];
    p -= lowbit(p);
  }
  return sum;
}
int main() {
  while (scanf("%d", &n) != EOF) {
    for (int i = 1; i <= n; i++) {
      scanf("%d", &a[i].val);
      a[i].i = i;
    }
    sort(
        a + 1, a + n + 1,
        cmp); /// ������С�����൱�ڴ�С�������ÿһ������������Ϊ�ǰ���С���˳�򣬶��ڽϴ�������Ѿ����������С���Ǹ�����λ���ǣ������Ӿ������ÿ��С�ڵ�ǰ�����������ҷֲ�����
    memset(tree, 0,
           sizeof(tree)); /// ��״�������ڼ�¼ÿ������Ƿ���֣����ֹ��ľ���Ϊ
    update(a[1].i, 1);
    int ans = 0;
    for (
        int i = 2; i <= n;
        i++) /// �൱���ڱ����Ǹ���֮ǰ�����������С���Ǹ����ĸ���������λ��ֶ����
    {
      ans += (sum(n) - sum(a[i].i)) * sum(a[i].i - 1); /// Ȼ��˻����������
      update(a[i].i, 1); /// �������������ҲҪ��������
    }
    printf("%d\n", ans);
  }
}
// #include<stdio.h>
// #include<string.h>
// int main()
//{
//     int a[50008],n,b[50008];
//     while(scanf("%d",&n)!=EOF)
//     {
//         long long sum=0;
//         memset(b,0,sizeof(b));
//         for(int i=0; i<n; i++)
//         {
//             scanf("%d",&a[i]);
//             for(int j=i-1; j>=0; j--)
//                 if(a[j]<a[i])b[i]++;
//         }
//         for(int i=n-1; i>=0; i--)
//         {
//             int num=0;
//             for(int j=i+1; j<n; j++)
//                 if(a[i]>a[j])num++;
//             sum+=b[i]*num;
//         }
//         printf("%lld\n",sum);
//     }
// }
