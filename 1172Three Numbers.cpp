#include<stdio.h>
#include<algorithm>
using namespace std;
bool cmp(int a,int b)
{
    return a>b;
}
int main()
{
    long long a[3];
    while(scanf("%lld%lld%lld",&a[0],&a[1],&a[2])!=EOF)
    {
        sort(a,a+3,cmp);
        for(int i=0;i<3;i++)
        {
            printf("%lld%c",a[i],i==2?'\n':' ');
        }
    }
    return 0;
}
