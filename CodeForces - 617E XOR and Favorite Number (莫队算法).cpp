#include<stdio.h>///Ī��
#include<string.h>
#include<algorithm>
#include<math.h>
#define LL long long
using namespace std;
const LL maxn=2000000;///��Ϊ�������������ֵ����
struct node///��¼ѯ�ʵ����ұ߽��ѯ�ʵ�id
{
    int l,r,id;
}qu[maxn];
int pos[maxn];///��������ÿ�������зֿ鴦������¼ÿ��id���ֵ��Ŀ����
LL ans[maxn];///��¼ÿ��ѯ�ʵ�ans
LL flag[maxn];///��¼��������ֵĴ���
bool cmp(node a,node b)///�ֿ�����
{
    if(pos[a.l]==pos[b.l])return a.r<b.r;
    return pos[a.l]<pos[b.l];
}
LL a[maxn];///���ǰ׺�ͣ����ܻᳬint
int L =1,R=0,n,m,k;///�߽�ָ����Ϊȫ�ֱ���������ԭ���������ƶ�����ʼ��Ϊ1��0����ΪL�������ƣ���Rֻ������
LL cnt=0;///��¼��L��R�߽�ָ��ָ��һ����Χʱ���������洢�����ֵ�����ݱ߽�仯���ϱ仯
void add(int x)
{
    cnt+=flag[a[x]^k];///add�����У�����һ��λ�õ���Ϣ����Ϊa[x]^a[y]=k���ʾǰ׺����x+1���y�����������ͣ���ôa[x]^k=a[y],��������ֵ������LR���䷶Χ����ô��Ϊû�б����µ��ý�������Ŀǰ�Ǹ�λ�õ����ֵǰ׺��Ϊ0���������Ӱ��
    flag[a[x]]++;///���ڵ�ǰλ�õ�ǰ׺���͵�ֵ�����ִ�������
}
void del(int x)
{
    flag[a[x]]--;
    cnt-=flag[a[x]^k];
}
int main()
{
    while(scanf("%d%d%d",&n,&m,&k)!=EOF)
    {
        int sz=sqrt(n);
        for(int i=1;i<=n;i++)
        {
            scanf("%lld",&a[i]);
            a[i]=a[i-1]^a[i];///���ǰ׺��
            pos[i]=i/sz;///�ֿ�,��¼ÿ���±������ĸ��ֿ������pos
        }
        for(int i=1;i<=m;i++)///���벢��¼M��ѯ��
        {
            scanf("%d%d",&qu[i].l,&qu[i].r);
            qu[i].id=i;
        }
        flag[0]=1;
        sort(qu+1,qu+m+1,cmp);
        for(int i=1;i<=m;i++)
        {
            while(L<qu[i].l) del(L-1),L++;///����֪��Χ����߽�С��ѯ�ʷ�Χ����߽磬˵����֪��Χ�ϴ�ɾ����߽�-1λ����Ϣ�����ƶ���߽�ָ��
            while(L>qu[i].l) L--,add(L-1);///����֪��Χ��߽����ѯ�ʷ�Χ����߽磬˵����֪��Χ��С��Ӧ����Lָ���ؿ�Χ��������L-1λ�ö�ans��ѯ�����Ӱ��
            while(R<qu[i].r) add(++R);///����֪��Χ�ұ߽�С��ѯ�ʷ�Χ�ұ߽磬˵����֪��Χ��С��Ӧ�����ұ߽�ָ������R+1λ�öԵ�ǰ�����Ӱ��
            while(R>qu[i].r) del(R--);///����֪��Χ�ұ߽����ѯ�ʷ�Χ�ұ߽磬˵����֪��Χ�ϴ�Ӧ�����ұ߽�ָ���������෶Χ�Խ����Ӱ��
            ans[qu[i].id]=cnt;///����ƶ�ָ�뵽ѯ��λ�ã���õ�cnt����ǰѯ�ʽ��
        }
        for(int i=1;i<=m;i++)printf("%lld\n",ans[i]);
    }
}
