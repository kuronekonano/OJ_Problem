#include<stdio.h>
#define LL long long
const int mod=1000000007;
LL poww(LL a,LL b)
{
    LL sum=1;
    while(b!=0)
    {
        if(b%2!=0) sum=((sum%mod)*(a%mod))%mod;
        a=((a%mod)*(a%mod))%mod;
        b/=2;
    }
    return sum;
}
LL inv(LL a)
{
    return poww(a,mod-2);///���÷���С������Եõ���a����Ԫ���ɷ���С�����֪��a����Ԫ=a^(p-2),pΪ����һ��������������������1e9+7
}///ע�⣬��ֻ��a p����ʱ���÷����������������Ԫ��a p��������a^(p-2)��һ��ȡģ����������֮���ʵģ�����������ľͲ�����Ԫ��

int main()
{
    int t,i,n,cas=0;
    scanf("%d",&t);
    while(t--)
    {
        cas++;
        LL ans=1,x,y,a;
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%lld%lld%lld",&a,&x,&y);
            if(a==1)
            {
                ans=((ans%mod)*((y-x+1)%mod))%mod;
            }
            else
            {
                ans=(ans%mod*(poww(a,x)%mod*(poww(a,y-x+1)-1)%mod)%mod*(inv(a-1)%mod)%mod)%mod;///������Ԫ���еȱ�������͹�ʽ�г�����ȡģ����һ�������ڳ������������Ԫ
            }
        }
        printf("Case #%d: %lld\n",cas,ans);
    }
}
///����С����
///����a��һ������p�����Լ��Ϊ1��gcd(a,p)=1
///�ɶ���֪ a��p-1�η�ģp�����1ģp
///(a*x)%p=1%p
///a*x=a^p-1
///x=a^(p-2)
///xΪ����a����Ԫ���ÿ������a����ԪΪ��������ֵ�a^(p-2),pΪ����һ������
