#include<stdio.h>
#include<algorithm>
using namespace std;
int main()
{
    int n,a[205];
    while(scanf("%d",&n)!=EOF)
    {
        int ans=0;
        for(int i=0;i<2*n;i++)scanf("%d",&a[i]);
        sort(a,a+(2*n));
        for(int i=2*n-2;i>=0;i-=2) ans+=a[i];
        printf("%d\n",ans);
    }
}
