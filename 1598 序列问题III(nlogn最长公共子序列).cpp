#include<stdio.h>///��LCS����ת��ΪLIS���⣬��¼��ͬ���ֵ�λ������һ������λ����ƥ�䣬����LIS
#include<string.h>
#include<algorithm>
using namespace std;
int main()
{
    int t,p,q,pos[10008],a[10008],maxx[10008];
    scanf("%d",&t);
    while(t--)
    {
        memset(pos,0,sizeof(pos));
        scanf("%d%d",&p,&q);
        for(int i=1;i<=p;i++)scanf("%d",&a[i]),pos[a[i]]=i;///��¼A����ÿ���ַ����ֵ�λ���ַ�a[i]������λ��i
        for(int i=1;i<=q;i++)scanf("%d",&a[i]),a[i]=pos[a[i]];///����B��
        maxx[1]=a[1];
        int flag=1;
        for(int i=2;i<=q;i++)
        {
            if(a[i]>maxx[flag])
                maxx[++flag]=a[i];
            else
            {
                int half=lower_bound(maxx+1,maxx+flag,a[i])-maxx;
                maxx[half]=a[i];
            }
        }
        printf("%d\n",flag);
    }
}
