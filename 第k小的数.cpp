#include<stdio.h>
#include<algorithm>
using namespace std;
int main()
{
    int i,n,k;
    while(scanf("%d%d",&n,&k)!=EOF)
    {
        int a[n+5];
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        sort(a,a+n);//���򷽱����
        printf("%d\n",a[k-1]);//��Ϊ�ǵ�KС�������������Ӧ���������еĵ�k-1����
    }
    return 0;
}
