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
    sort(a,a+n);//����С������������
    t=n/2;//ȡ���е���λ��
    printf("%d\n",a[t]);
    return 0;
}
