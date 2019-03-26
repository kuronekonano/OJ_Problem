#include<stdio.h>///���ؾ���:������Ȼ��ð�ݴ����������������ǽ������ظ������ֳ��֣���͵���һ�����ѷ��ֵ����⣬������ʱ����ͬ���ֵ�λ������ʱ������֪��˭ǰ˭��
#include<string.h>///�������ʱע�⣡�������ֵ��ͬ������λ���С��������
#include<algorithm>
using namespace std;
struct num
{
    int n,i;
} a[500005];
int tree[500005],ls[500005],n;
int lowbit(int x)
{
    return x&(-x);
}
int sum(int p)
{
    int sum=0;
    while(p>0)
    {
        sum+=tree[p];
        p-=lowbit(p);
    }
    return sum;
}
void update(int p)
{
    while(p<=n)
    {
        tree[p]++;
        p+=lowbit(p);
    }
}
bool cmp(num a,num b)
{

    if(a.n==b.n)
        return a.i<b.i;
    return a.n<b.n;
}
int main()
{
    while(scanf("%d",&n)&&n)
    {
        for(int i=1; i<=n; i++)
        {
            scanf("%d",&a[i].n);
            a[i].i=i;
        }
        sort(a+1,a+n+1,cmp);
        for(int i=1; i<=n; i++) ls[a[i].i]=i;
        memset(tree,0,sizeof(tree));
        long long ans=0;
        for(int i=1; i<=n; i++)
        {
            update(ls[i]);
            ans+=i-sum(ls[i]);
            printf("---->%d  %d\n",i,sum(ls[i]));
        }
        printf("%lld\n",ans);
    }
}
