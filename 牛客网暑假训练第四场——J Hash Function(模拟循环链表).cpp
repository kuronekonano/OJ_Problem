#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
int n;
struct node {
  int num, id;                        /// ֵ��λ��
  bool operator<(const node &a) const /// ���ȶ��а�ֵ��С��������
  {
    return num > a.num;
  }
} a[maxn];
int pre[maxn], nxt[maxn]; /// ѭ����������
bool vis[maxn];
priority_queue<node> q; /// ��֤����С�ֵ������
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
    int v,id;///ֵ��λ��
    bool operator < (const node& o)const///���ȶ��а�ֵ��С����
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
    for(int i=0; i<n; i++)///��ʼ��ѭ������
    {
        back[i]= i==0? n-1:i-1;
        Next[i]= i==n-1? 0:i+1;
    }

    for(int i=0; i<n; i++)
        if(data[i].v!=-1 && data[i].v%n==i)///ֵ��Ϊ�� �� ֵδ�ƶ�
        {
            vis[i]=true;///���ñ��
            buf.push(data[i]);///���ڹ̶�λ��ҲҪά����С�ֵ�����˼�ʹ�ǹ̶�λ��Ҳ��һ���ǽ�������ģ������㹻С
        }
    while(!buf.empty())///���й̶�λ�õ�ֵ�����õ����ȶ����У���ʱ���԰��մ�С�����˳�����
    {
        node k=buf.top();
        ans.push_back(k.v);///��Ϊÿһ���̶�Ԫ�غ��涼�п����б����Ƶ�Ԫ�أ�ͨ������ÿһ���̶����õ����зǹ̶�Ԫ�ص�λ�ã�����Ԫ����Ԫ��֮����Ϊ���ƶ���������
        buf.pop();

        Next[back[k.id]]=Next[k.id];///ѭ������ɾ���Ѿ���ȷ����Ԫ��
        back[Next[k.id]]=back[k.id];

        int key=Next[k.id];///������һ�������Լ�λ���ϵ�Ԫ��
        if(data[key].v!=-1&&!vis[key]&&judge(back[key],data[key].v%n,key))///�����һ��λ�ñ�ռ��
�� ��һ��Ԫ��û�б����� �� ��֤ǰ��λ���ǵ����ĲźϷ�
        {///��Ϊ���b<a<c�����������ǰ���back��û�������ʹ���Ǳ���b�����ֵ������Ҳ������ӣ���ΪҪ����֮ǰ���Ǹ�������ˣ����ֵ��ұ����ƣ���Ȼ������������룬����λ�ñȺ�����Ļ�����
            vis[key]=true;
            buf.push(data[key]);///��Ӽ��Ϸ�λ��
        }
    }
    int cnt=0;
    for(int i=0; i<n; i++)
        if(data[i].v!=-1) cnt++;///�ǿ�ȱλ����Ӧ�õ��������������
    if(ans.size()!=cnt) return false;

    for(int i=0; i<ans.size(); i++)///������
        printf("%d%c",ans[i],i==ans.size()-1?'\n':' ');
    return true;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        readin();///��������
        if(!solve()) printf("-1\n");
    }
    return 0;
}
*/
