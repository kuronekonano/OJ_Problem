#include<stdio.h>
#include<algorithm>
using namespace std;
int main()
{
    int a[109],i,n;
    while(scanf("%d",&n)!=EOF)
    {
        if(n==0)
        {
            return 0;
        }
        for(i=0; i<n; i++)
        {
            scanf("%d",&a[i]);
        }
        sort(a,a+n);///����󷽱��ҵ��������ٵ��ݣ��������ܴﵽ��ȡѡƱ���ٵ�Ŀ��
        int sum=0;///������
        if(n%2==0)///����������ۣ������ݺ�ż������������������ʱ������ֻ��+1�ٳ�2,ż������ʱ��Ϊ�˹��룬��2�����1
        {
            for(i=0; i<n/2+1; i++)
            {
                sum=sum+(a[i]+1)/2;///ͬ����ÿ������������Ҳ����ż��
                if(a[i]%2==0)///����+1�ٳ�2�������϶����룬�������ż������պôﵽһ�룬�ж��Ƿ���ż��������ż�����ټ�һ�ﵽ����
                {
                    sum++;
                }
            }
        }
        if(n%2!=0)
        {
            for(i=0; i<(n+1)/2; i++)
            {
                sum=sum+(a[i]+1)/2;
                if(a[i]%2==0)
                {
                    sum++;
                }
            }
        }
        printf("%d\n",sum);
    }
    return 0;
}