#include<stdio.h>
#include<algorithm>
using namespace std;
int main()
{
    int i,n,t;
    int a[10005];
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    sort(a,a+n);//按大小重新排列数组
    t=n/2;//取其中的中位数
    printf("%d\n",a[t]);
    return 0;
}
