#include<stdio.h>
#include<math.h>
#include<algorithm>
using namespace std;
int main()
{
    int n,t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        double a=log(n)/log(2);
        double b=ceil(log(n)/log(2));
        if(a-b==0)
        {
            printf("IMPOSSIBLE\n");
            continue;
        }
        if(n&1) printf("%d = %d + %d\n",n,n/2,n/2+1);///����n����ֱ�ӳ�2���n/2+1��n/2
        else
        {
            int k=0x7fffffff,f=0;
            for(int i=2; i<=sqrt(n); i++)
            {
                if(n%i)continue;///�������ӵ�������
                int odd=i,even=n/i;///ȡ����
                if(!(odd&1)&&!(even&1))continue;///����һ��һż����
                if(!(odd&1))swap(odd,even);///ȷ������oddΪ������evenΪż��
                f=1;
                odd=odd>even*2?even*2:odd;
                k=min(k,odd);
            }
            if(!f)///��������2�Ĵη����޽��⣬���ܻ������޽⣬������һ�����
            {
                printf("IMPOSSIBLE\n");
                continue;
            }
            int aa=(n*2/k+1-k)/2;///��������
            printf("%d = ",n);
            for(int i=aa; i<aa+k; i++)
            {
                printf("%d",i);
                if(i!=aa+k-1)printf(" + ");
                else printf("\n");
            }
        }
    }
}
///����͹�ʽ�ɵã�n=((a+b)*k)/2,kΪ���г��ȣ�aΪ����ߵ����bΪĩ��
///һ����n���Էֳ��������ĳ˻�����������������n1��n2��ӣ���ô������n1��n2������Ϊ����k����ĿҪ��ѡȡ��С��һ��
///Ψ������������һ��һżʱ���н⣬������ʱ����ż���������Լ���������+1��ż����������Ϊż��ʱ�������ڣ���˽�������Ϊż��*2���Թ���������Ӻ�
///����ȡѰ�ҿ������������ӣ����ҷ���һ��һż��������Ȼ��������������������ȡ��С�����������õ��������Ը��ݹ�ʽ���Ƴ�����Ϊa��ĩ��b=a+k-1
///2*n=(a+b)*k     2*n/k=a+a+k-1   2*n/k=2*a+k-1     (2*n/k+1-k)/2=a
///ֱ�������Χa��b��ֵ����
