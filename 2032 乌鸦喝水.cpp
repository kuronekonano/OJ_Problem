#include<stdio.h>///��̰��
#include<algorithm>
using namespace std;
struct stone
{
    int x,y,v;
    long long dis;
}a[1008];
bool cmp(stone a,stone b)
{
    if(a.dis==b.dis)
    {
        return a.v>b.v;///��������ͬ���������С����(�����ǰ)
    }
    return a.dis<b.dis;///���Ȱ�ʯ�ӵ�ƿ�ľ�������(����̿�ǰ)
}
int main()
{
    int n,m,b,i;
    while(scanf("%d%d%d",&n,&m,&b)!=EOF)
    {
        int sum=0;
        for(i=0;i<n;i++)
        {
            scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].v);
            a[i].dis=a[i].x*a[i].x+a[i].y*a[i].y;///�������룬û����
            sum+=a[i].v;
        }
        if(sum+b<m)///������ʯͷ�������ˮ�����С��ƿ��������򲻿��ܹ��ȵ�
        {
            printf("-1\n");
            continue;
        }
        sort(a,a+n,cmp);///ʯ��ѡ��˳������
        sum=b;///��ʼֵΪˮ�����
        i=0;
        int flag=0;///ʯ����������
        while(sum<m&&i<=n)
        {
            sum+=a[i++].v;///������
            flag++;
        }
        printf("%d\n",flag);
    }
}
