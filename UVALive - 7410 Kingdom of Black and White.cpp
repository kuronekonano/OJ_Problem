#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int main()
{
    long long t,i,n,cas=0,b[100008];
    char a[100008];
    scanf("%lld",&t);
    while(t--)
    {
        cas++;
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        scanf("%s",a);
        n=strlen(a);
        long long flag=0,num=0,ans=0;
        for(i=0;i<n;i++)
        {
            flag++;
            if(a[i]!=a[i+1])
            {
                b[num++]=flag;
                ans+=flag*flag;
                flag=0;
            }
        }
        long long tmp=ans;
        for(i=0;i<num-1;i++)///题目只能改一个位置，所以对每个边界都修改一次取最大值
        {
            if(b[i]==1)
            {
                tmp=max(tmp,ans-b[i-1]*b[i-1]-b[i]*b[i]-b[i+1]*b[i+1]+(b[i-1]+b[i]+b[i+1])*(b[i-1]+b[i]+b[i+1]));
            }
            else
            {
                tmp=max(tmp,ans-b[i]*b[i]-b[i+1]*b[i+1]+(b[i]-1)*(b[i]-1)+(b[i+1]+1)*(b[i+1]+1));
            }
            if(b[i+1]==1)
            {
                tmp=max(tmp,ans-b[i+1]*b[i+1]-b[i]*b[i]-b[i+2]*b[i+2]+(b[i]+b[i+1]+b[i+2])*(b[i]+b[i+1]+b[i+2]));
            }
            else
            {
                tmp=max(tmp,ans-b[i]*b[i]-b[i+1]*b[i+1]+(b[i]+1)*(b[i]+1)+(b[i+1]-1)*(b[i+1]-1));
            }
        }
        printf("Case #%lld: %lld\n",cas,tmp);
    }
}
