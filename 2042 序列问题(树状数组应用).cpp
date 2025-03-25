#include <algorithm>
#include <stdio.h>
#include <string.h>
using namespace std;
int tree[50005], n;
struct num /// 结构体用于存储数值大小以及每个数的位序
{
  int val, i;
} a[50005]; /// 因为要按照数的大小排序，位序将会变乱，因此要存储位序
bool cmp(num a, num b) { return a.val < b.val; }
int lowbit(
    int x) /// 树状数组不能从0位序开始赋值，应该从1位序开始，因为0位序&0仍是0，无法做到指数级增长
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
        cmp); /// 按数大小排序，相当于从小到大遍历每一个数，并且因为是按从小大的顺序，对于较大的数，已经完成了所有小于那个数的位序标记，这样从就能求出每个小于当前遍历数的左右分布个数
    memset(tree, 0,
           sizeof(tree)); /// 树状数组用于记录每个标号是否出现，出现过的就作为
    update(a[1].i, 1);
    int ans = 0;
    for (
        int i = 2; i <= n;
        i++) /// 相当于在遍历那个数之前，先数清楚了小于那个数的个数，并对位序分段求和
    {
      ans += (sum(n) - sum(a[i].i)) * sum(a[i].i - 1); /// 然后乘积就是配对数
      update(a[i].i, 1); /// 遍历完这个数后也要标记这个数
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
