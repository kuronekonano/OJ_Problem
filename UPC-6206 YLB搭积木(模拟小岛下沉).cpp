#include<stdio.h>
#define LL long long
int n,a[100005];
bool check()
{
    for(int i=1;i<=n;i++)
        if(a[i])return false;
    return true;
}
int main()
{
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=1;i<=n;i++)scanf("%d",&a[i]);
        LL ans=0;
        while(!check())///���ѭ���ж����д�¥�߶��Ƿ�Ϊ0
        {
            int i=1;///��ʼ����ʼ����λ��
            while(i<=n)///���������n���б���
            {
                if(a[i])///���ڱ��������������и߶ȴ���
                {
                    int minn=0x7fffffff;///��ʼ��¼��ģ����Сֵ�����
                    int st=i;///��¼���
                    while(a[i]>0)
                    {
                        if(a[i]<minn)minn=a[i];
                        i++;
                    }
                    for(int j=st;j<i;j++)if(a[j])a[j]-=minn;///�ü�¼������Сֵ��������ģ��ĸ߶�
                    ans+=minn;///�������������Ӹ߶�
                }
                i++;///����û�и߶ȵ�����
            }
        }
        printf("%lld\n",ans);
    }
}
