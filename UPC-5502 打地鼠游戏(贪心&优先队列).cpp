#include<bits/stdc++.h>///̰��
#define LL long long
using namespace std;
const int maxn=1e5+10;
struct node
{
    int ti;
    LL vi;
} a[maxn];
priority_queue<int,vector<int>,less<int> >q;///�Ӵ�С�����ȶ���
bool cmp(node a,node b)///�Ȱ�ʱ������Խ����ʧ��Խ�ȱ�������ͬʱ��Ĵ��ֵ���
{
    if(a.ti==b.ti)return a.vi>b.vi;
    return a.ti>b.ti;
}
int n;
int main()
{
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=0; i<n; i++)scanf("%d",&a[i].ti);
        for(int i=0; i<n; i++)scanf("%lld",&a[i].vi);
        while(!q.empty())q.pop();
        sort(a,a+n,cmp);
        int now=a[0].ti;///��ʼʱ��Ϊ���һ����ʧ��
        LL ans=0;
        int i=0;
        while(now)///���ű�����ʧ�ĵ��󣬱�֤��ֵ����ȴ�
        {
            while(a[i].ti==now)///���������ĵ����ڴ�ʱСʱ
                q.push(a[i++].vi);///����ŵ������б�ʾ��Ŀǰ��֮���ʱ�䶼�ǿ��Դ��
            if(!q.empty())///�ڶ�����һֱȡ��ǰʱ���¿��Դ�ĵ���
                ans+=q.top(),q.pop();
            now--;///��һֻ����ʱ���С
        }
        printf("%lld\n",ans);
    }
}///���ű���ʱ�䣬��֤��ÿ����ͬһʱ���£���������������ʧ�ĵ��󣬽���ŵ�����������ֵ��ߵ�ɸѡ�����һֻ�����ܴ򣬻�û��ʧ���������ļ�ֵ�жϴ򲻴�
/*

5
5 3 6 1 4
7 9 2 1 5

6
1 1 2 2 3 3
1 1 1 1 1 1000

7
1 2 3 4 4 5 6
1000 0 2000 300 4000 500 20

4
1 2 3 3
2 3 50 51
*/
