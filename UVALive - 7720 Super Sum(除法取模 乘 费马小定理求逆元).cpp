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
    return poww(a,mod-2);///利用费马小定理可以得到数a的逆元，由费马小定理可知数a的逆元=a^(p-2),p为任意一个素数，这里利用素数1e9+7
}///注意，当只有a p互质时，用费马定理求出来的是逆元，a p互质能用a^(p-2)，一旦取模的数不是与之互质的，这样求出来的就不是逆元了

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
                ans=(ans%mod*(poww(a,x)%mod*(poww(a,y-x+1)-1)%mod)%mod*(inv(a-1)%mod)%mod)%mod;///利用逆元进行等比数列求和公式中除法的取模，除一个数等于乘上这个数的逆元
            }
        }
        printf("Case #%d: %lld\n",cas,ans);
    }
}
///费马小定理：
///数字a和一个素数p的最大公约数为1：gcd(a,p)=1
///由定理知 a的p-1次方模p恒等于1模p
///(a*x)%p=1%p
///a*x=a^p-1
///x=a^(p-2)
///x为数字a的逆元因此每个数字a的逆元为，这个数字的a^(p-2),p为任意一个素数
