#include<stdio.h>///注意，不仅绿洲的面积要大于等于右边，并且整块地的总面积也要完全大于右边，因此当绿洲不在分割线上时，要将右边第一块绿洲的左边线作为分割线
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
        long long tmp2=tmp;///因为要找的不只是绿洲面积大于等于，当绿洲面积可以平分且不在分割线上时，就要分总面积了
        for(i=i+1;i<=r-1;i++)///也就是，将除了绿洲之外的面积，尽可能分给左边，且保持分好绿洲面积不变
        {
            tmp2+=a[i];
            if(tmp2!=tmp)break;///将其往后一直加绿洲面积0，直到分到下一个绿洲改变了左边面积
        }
        printf("%lld\n",i);
    }
}
