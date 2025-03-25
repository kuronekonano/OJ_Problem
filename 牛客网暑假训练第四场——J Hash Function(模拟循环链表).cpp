#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
int n;
struct node {
  int num, id;                        /// 值和位置
  bool operator<(const node &a) const /// 优先队列按值从小到大排序
  {
    return num > a.num;
  }
} a[maxn];
int pre[maxn], nxt[maxn]; /// 循环链表数组
bool vis[maxn];
priority_queue<node> q; /// 保证按最小字典序输出
vector<int> ans;
bool judge(int a, int b, int c) {
  if (a < c)
    return a < b && b < c;
  return a < b || b < c;
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
      scanf("%d", &a[i].num);
      a[i].id = i;
    }
    bool flag = true;
    ans.clear();
    int cnt = 0;
    while (!q.empty())
      q.pop();
    memset(vis, false, sizeof vis);
    for (int i = 0; i < n; i++)
      pre[i] = i == 0 ? n - 1 : i - 1, nxt[i] = i == n - 1 ? 0 : i + 1;
    for (int i = 0; i < n; i++) {
      if (a[i].num != -1)
        cnt++;
      if (a[i].num % n == i && a[i].num != -1)
        vis[i] = true, q.push(a[i]);
    }
    while (!q.empty()) {
      node tmp = q.top();
      ans.push_back(tmp.num);
      q.pop();
      nxt[pre[tmp.id]] = nxt[tmp.id];
      pre[nxt[tmp.id]] = pre[tmp.id];
      int pos = nxt[tmp.id];
      if (a[pos].num != -1 && !vis[pos] && judge(pre[pos], a[pos].num % n, pos))
        vis[pos] = true, q.push(a[pos]);
    }
    if (cnt != ans.size())
      flag = false;
    if (flag) {
      for (int i = 0; i < ans.size(); i++)
        printf("%d%c", ans[i], i == ans.size() - 1 ? '\n' : ' ');
      if (ans.size() == 0)
        printf("\n");
    } else
      printf("-1\n");
  }
}
/*
#include<bits/stdc++.h>
using namespace std;
const int maxn=200005;
int n;
struct node
{
    int v,id;///值和位置
    bool operator < (const node& o)const///优先队列按值大小排序
    {
        return v>o.v;
    }
} data[maxn];
void readin()
{
    scanf("%d",&n);
    for(int i=0; i<n; i++)
    {
        scanf("%d",&data[i].v);
        data[i].id=i;
    }
}
priority_queue<node> buf;
vector<int> ans;
bool vis[maxn];
int back[maxn],Next[maxn];
bool judge(int a,int b,int c)
{
    if(c>a) return b>a&&b<=c;
    else return b>a||b<=c;
}
bool solve()
{
    ans.clear();
    while(!buf.empty()) buf.pop();
    memset(vis,false,sizeof vis);
    for(int i=0; i<n; i++)///初始化循环链表
    {
        back[i]= i==0? n-1:i-1;
        Next[i]= i==n-1? 0:i+1;
    }

    for(int i=0; i<n; i++)
        if(data[i].v!=-1 && data[i].v%n==i)///值不为空 且 值未移动
        {
            vis[i]=true;///放置标记
            buf.push(data[i]);///对于固定位置也要维持最小字典序，因此即使是固定位置也不一定是较先输入的，还得足够小
        }
    while(!buf.empty())///所有固定位置的值被放置到优先队列中，此时可以按照从小到大的顺序输出
    {
        node k=buf.top();
        ans.push_back(k.v);///因为每一个固定元素后面都有可能有被后移的元素，通过遍历每一个固定，得到所有非固定元素的位置，并且元素与元素之间因为后移而两两相邻
        buf.pop();

        Next[back[k.id]]=Next[k.id];///循环链表删除已经被确定的元素
        back[Next[k.id]]=back[k.id];

        int key=Next[k.id];///安排下一个不在自己位置上的元素
        if(data[key].v!=-1&&!vis[key]&&judge(back[key],data[key].v%n,key))///如果下一个位置被占用
且 下一个元素没有被安排 且 保证前后位置是递增的才合法
        {///因为如果b<a<c这种情况，我前面的back还没输出，即使我是本体b后面的值，但我也不能入队，因为要等我之前的那个数输出了，才轮到我被后移，不然会出现我先输入，但我位置比后输入的还后移
            vis[key]=true;
            buf.push(data[key]);///入队即合法位置
        }
    }
    int cnt=0;
    for(int i=0; i<n; i++)
        if(data[i].v!=-1) cnt++;///非空缺位数量应该等于输出序列数量
    if(ans.size()!=cnt) return false;

    for(int i=0; i<ans.size(); i++)///输出结果
        printf("%d%c",ans[i],i==ans.size()-1?'\n':' ');
    return true;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        readin();///读入序列
        if(!solve()) printf("-1\n");
    }
    return 0;
}
*/
