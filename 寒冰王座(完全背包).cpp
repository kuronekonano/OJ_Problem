#include<stdio.h>///��̬�滮��ȫ����
#include<algorithm>
#include<string.h>
using namespace std;
int a[100005];
int main()
{
    int b[4]={150,200,350},t,n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);///����Ǯ��
        memset(a,0,sizeof(a));
        for(int i=0;i<3;i++)///ѡ������Ʒ
        {
            for(int j=1;j<=n;j++)///һֱ������Ǯ����ÿ�������Ϳ��Զ���һ�㣬һֱ���㵽��n�����Ž�ʱ���������Ǯ�������򵽵���ණ��
            {
                if(j>=b[i])///�����ǰ��Ǯ�������ڱ�������Ʒ
                {
                    a[j]=max(a[j],a[j-b[i]]+b[i]);//��֮ǰ�ı�ǵ㲻�ϸ������ο��Թ���Ķ���������֤�����ֵ
                }
            }
        }
        printf("%d\n",n-a[n]);///����ǲ���Ǯ
    }
    return 0;
}
