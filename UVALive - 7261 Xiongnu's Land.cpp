#include<stdio.h>///ע�⣬�������޵����Ҫ���ڵ����ұߣ���������ص������ҲҪ��ȫ�����ұߣ���˵����޲��ڷָ�����ʱ��Ҫ���ұߵ�һ�����޵��������Ϊ�ָ���
#include<string.h>
long long a[1000008];
int main()
{
    long long k,n,l,h,w,r,i,t;
    scanf("%lld",&k);
    while(k--)
    {
        long long sum=0;
        memset(a,0,sizeof(a));
        scanf("%lld%lld",&r,&n);
        for(i=1;i<=n;i++)
        {
            scanf("%lld%lld%lld%lld",&l,&t,&w,&h);
            sum+=w*h;
            for(int j=l;j<=l+w-1;j++)
            {
                a[j]+=h;
            }
        }
        long long tmp=0;
        for(i=0;i<=r-1;i++)
        {
            tmp+=a[i];
            if(tmp*2>=sum)
                break;
        }
        long long tmp2=tmp;///��ΪҪ�ҵĲ�ֻ������������ڵ��ڣ��������������ƽ���Ҳ��ڷָ�����ʱ����Ҫ���������
        for(i=i+1;i<=r-1;i++)///Ҳ���ǣ�����������֮�������������ָܷ���ߣ��ұ��ַֺ������������
        {
            tmp2+=a[i];
            if(tmp2!=tmp)break;///��������һֱ���������0��ֱ���ֵ���һ�����޸ı���������
        }
        printf("%lld\n",i);
    }
}
