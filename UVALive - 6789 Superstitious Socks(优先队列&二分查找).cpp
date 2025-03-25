#include <algorithm> ///有n双不同长度的袜子，每天选择长度不同且尽量短的两只长度差最短的袜子，穿过的长度组合不能再穿，问第k天穿的是什么长度袜子
#include <stdio.h> ///两种方法，一种用优先队列模拟，第一次投入所有排序后相邻长度差值，之后每次取最小差值向后加一双袜子差值投入队列，这样保证投入队列的都是较小值
using namespace std; /// 第二种方法，利用二分查找到在k天内可用的最大差值，每次投入一个二分出来的mid，然后两层for循环找到所有小于等于这个差值袜子差，当满足k种组合时，尽量缩小或扩大mid的值
struct
    sock /// 然后取到第k天的袜子差值，两层for循环查找到所有满足条件的值。排序后取第k大值就是答案
{
  int mi, ma;
  bool operator<(const sock &a) const {
    if (a.ma - a.mi == ma - mi)
      return ma < a.ma;
    return ma - mi < a.ma - a.mi;
  }
} a[1000005]; /// 注意结构体数组，两两配合的数量，明显会超过1e5最大值，多开数组
int n, k, b[100005];
bool judge(int maxn) {
  int flag = 0;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (b[j] - b[i] <= maxn)
        flag++;
      else
        break;
      if (flag == k)
        return true;
    }
  }
  return false;
}
int main() {
  while (scanf("%d%d", &n, &k) != EOF) {
    if (!n && !k)
      break;
    for (int i = 0; i < n; i++)
      scanf("%d", &b[i]);
    sort(b, b + n);
    int l = 1, r = b[n - 1] - b[0];
    while (l <= r) {
      int mid = l + (r - l) / 2;
      if (judge(mid))
        r = mid - 1;
      else
        l = mid + 1;
      //            printf("%d=====%d\n",l,r);
    }
    int num = 0;
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        if (b[j] - b[i] <= l) {
          a[num].mi = b[i];
          a[num++].ma = b[j];
        } else
          break;
      }
    }
    sort(a, a + num);
    printf("%d %d\n", a[k - 1].mi, a[k - 1].ma);
  }
}
// #include<stdio.h>
// #include<queue>
// #include<algorithm>
// using namespace std;
// struct sock
//{
//     int mi,ma,dis;
//     sock(int a,int b,int c)
//     {
//         mi=a,ma=b,dis=c;
//     }
//     bool operator <(const sock &d)const
//     {
//         if(dis==d.dis)
//         {
//             if(mi==d.mi)
//                 return ma>d.ma;
//             return mi>d.mi;
//         }
//         return dis>d.dis;
//     }
// };
// int main()
//{
//     int n,k,a[100008];
//     priority_queue<sock>q;
//     while(scanf("%d%d",&n,&k)!=EOF)
//     {
//         if(!n&&!k)break;
//         for(int i=0; i<n; i++) scanf("%d",&a[i]);
//         sort(a,a+n);
//         while(!q.empty())q.pop();
//         for(int i=1; i<n; i++)
//             q.push(sock(i-1,i,a[i]-a[i-1]));
//         int mii,maa;
//         while(k>0&&!q.empty())
//         {
//             mii=q.top().mi;
//             maa=q.top().ma;
//             q.pop();
//             if(k==1)
//             {
//                 printf("%d %d\n",a[mii],a[maa]);
//                 break;
//             }
//             k--;
//             if(maa+1<n)
//                 q.push(sock(mii,maa+1,a[maa+1]-a[mii]));
//         }
//     }
// }
