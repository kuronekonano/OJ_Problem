#include<stdio.h>///����󰴴�С�����˳���������Ϊ�Ѿ���������˲��ù�tiֵ��ɸѡ����Ϊÿ�ζ����㹻���
#include<algorithm>///���ֻ���ڱ�����һ���������ʱ��¼���ж����i�Ƿ��㹻С��ע���ظ�������ֱ���Թ��ж�
using namespace std;///��Ϊ��Сmini��tiֵ������i��tiֵ��ȣ�������ͬ�ļ�������i�ϴ�������ǰ�棬ʣ���i�Ͳ��ж���
struct num
{
    int n,i;
}a[1000006];
int aa[1000006];
bool cmp(num a,num b)
{
    if(a.n==b.n)return a.i>b.i;
    return a.n<b.n;
}
int main()
{
    int t,n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%d",&aa[i]);
            a[i].i=i,a[i].n=aa[i];
        }
        sort(a,a+n,cmp);
        int ans=0,mini=n;
        for(int i=0;i<n;i++)
        {
            if(a[i].i==aa[mini])continue;
            if(a[i].i<mini) mini=a[i].i;
            else ans=a[i].i-mini>ans?a[i].i-mini:ans;
        }
        printf("%d\n",ans);
    }
}
