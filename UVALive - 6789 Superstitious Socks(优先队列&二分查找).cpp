#include <algorithm> ///��n˫��ͬ���ȵ����ӣ�ÿ��ѡ�񳤶Ȳ�ͬ�Ҿ����̵���ֻ���Ȳ���̵����ӣ������ĳ�����ϲ����ٴ����ʵ�k�촩����ʲô��������
#include <stdio.h> ///���ַ�����һ�������ȶ���ģ�⣬��һ��Ͷ��������������ڳ��Ȳ�ֵ��֮��ÿ��ȡ��С��ֵ����һ˫���Ӳ�ֵͶ����У�������֤Ͷ����еĶ��ǽ�Сֵ
using namespace std; /// �ڶ��ַ��������ö��ֲ��ҵ���k���ڿ��õ�����ֵ��ÿ��Ͷ��һ�����ֳ�����mid��Ȼ������forѭ���ҵ�����С�ڵ��������ֵ���Ӳ������k�����ʱ��������С������mid��ֵ
struct
    sock /// Ȼ��ȡ����k������Ӳ�ֵ������forѭ�����ҵ���������������ֵ�������ȡ��k��ֵ���Ǵ�
{
  int mi, ma;
  bool operator<(const sock &a) const {
    if (a.ma - a.mi == ma - mi)
      return ma < a.ma;
    return ma - mi < a.ma - a.mi;
  }
} a[1000005]; /// ע��ṹ�����飬������ϵ����������Իᳬ��1e5���ֵ���࿪����
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
