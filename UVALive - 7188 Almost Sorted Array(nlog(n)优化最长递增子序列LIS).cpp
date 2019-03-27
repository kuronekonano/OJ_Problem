#include<stdio.h>///n*log(n)优化最长递增(递减)子序列
#include<string.h>
int t,a[100008],maxn[100008],minn[100008];
int Search(int num,int low,int high)
{
    int mid;
    while(low<=high)
    {
        mid=(low+high)/2;
        if(num>=maxn[mid]) low=mid+1;
        else high=mid-1;
    }
    return low;
}
int Search1(int num,int low,int high)
{
    int mid;
    while(low<=high)
    {
        mid=(low+high)/2;
        if(num<=minn[mid]) low=mid+1;
        else high=mid-1;
    }
    return low;
}
int main()
{
    int i,j,n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
        }
        maxn[1]=a[1];
        minn[1]=a[1];
        int flagmax=1,flagmin=1;
        for(i=2;i<=n;i++)///相当于数组中存的是每个递增(递减)序列的最大值/最小值
        {
            if(a[i]>=maxn[flagmax])
            {
                flagmax++;
                maxn[flagmax]=a[i];
            }
            else
            {
                int pos=Search(a[i],1,flagmax);///递增序列中二分查找
                maxn[pos]=a[i];
            }
            if(a[i]<=minn[flagmin])
            {
                flagmin++;
                minn[flagmin]=a[i];
            }
            else
            {
                int pos=Search1(a[i],1,flagmin);///递减序列中二分查找
                minn[pos]=a[i];
            }
        }
//        printf("=======%d   %d\n",flagmax,flagmin);
        if(flagmin+1>=n||flagmax+1>=n)
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }
}
