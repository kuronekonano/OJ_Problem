#include<stdio.h>///卧槽，10^5是100000，数组开小了WA
#include<algorithm>
using namespace std;
int main()
{
    int t,i,a[100050],n,s;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        sort(a,a+n);
        scanf("%d",&s);
        int sum=0,flag=0;
        i=n;
        while(sum<s&&i>=0)
        {
            flag++;
            sum=sum+a[--i];
        }
        if(flag>n)
            flag=n;
        printf("%d\n",flag);
    }
    return 0;
}
