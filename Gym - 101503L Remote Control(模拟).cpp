#include<stdio.h>///ģ��
#include<string.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
int a[20];
bool judge(int x)///�ж�xλ�Ƿ����
{
    if(x<10)
        if(a[x])return true;
        else return false;
    else
    {
        if(a[x/10]&&a[x%10]&&a[12])return true;///������ж�ʮλ�Ͱ�λ����ô˫λ������������
        else return false;
    }
}
int main()
{
    int n,m;
    while(~scanf("%d",&a[1]))
    {
        int n,m,ans=0x7fffffff;
        scanf("%d%d%d%d%d%d%d%d%d%d%d%d",&a[2],&a[3],&a[10],&a[4],&a[5],&a[6],&a[11],&a[7],&a[8],&a[9],&a[12],&a[0]);
        scanf("%d%d",&n,&m);
        if(n==m)///������Լ����Լ�����Ҫ�������ÿ����ĸ������Ƿ���
        {
            printf("0\n");
            continue;
        }
        int dis=abs(m-n);///������̨����
        if(a[10])///ֻ����ǰ
            if(n<m) ans=min(ans,dis);
            else ans=min(ans,m+100-n);
        if(a[11])///ֻ������
            if(n<m)ans=min(ans,n+100-m);
            else ans=min(ans,dis);
        if(m<10)///Ŀ��λ��Ϊ��λ
        {
            if(judge(m))///��ֱ������ȥ�ж�
            {
                ans=min(ans,1);
            }
            if(!judge(m)&&a[10])///�����Լ�ֱ�������������������̨��Ȼ��ֻ��ǰ�������
            {///��Ծ����ǰ
                int tmp=m,sum=0;
                while(!judge(tmp)&&sum<101)///�����������ͨ������;�������ô���ѭ����������ȥ�����Ҫ�趨һ�����������ѭ��
                {
                    tmp--;
                    sum++;
                    if(tmp<0)tmp+=100;///Ƶ����ѭ����
                }
                int num=tmp<10?1:3;///ע����������̨�Ǹ�λ����ôֻ�ð�һ�β���������Ҫ��3��
                ans=min(ans,num+sum);///����ֱ�Ӽ�����Ӧ�ò��������ϱ���
            }
            if(!judge(m)&&a[11])
            {///��Ծ�����
                int tmp=m,sum=0;
                while(!judge(tmp)&&sum<101)
                {
                    tmp++;
                    sum++;
                    if(tmp>99)tmp%=100;///Ƶ��ѭ��
                }
                int num=tmp<10?1:3;
                ans=min(ans,num+sum);///����ȡ��Сֵ
            }
        }
        else///Ŀ��λ�ô���10
        {
            if(judge(m))
                ans=min(3,ans);///ֱ����Ծ˫λ
            if(!judge(m)&&a[10])
            {
                int tmp=m,sum=0;
                while(!judge(tmp)&&sum<101)
                {
                    tmp--;
                    sum++;
                    if(tmp<0)tmp+=100;
                }
                int num=tmp<10?1:3;
                ans=min(ans,num+sum);
            }
            if(!judge(m)&&a[11])
            {
                int tmp=m,sum=0;
                while(!judge(tmp)&&sum<101)
                {
                    tmp++;
                    sum++;
                    if(tmp>99) tmp%=100;
                }
                int num=tmp<10?1:3;
                ans=min(ans,sum+num);
            }
        }
        if(ans==0x7fffffff)ans=-1;///���û���κ�;�������Ǹ�̨�����������ᱻ���£��������ֵ
        printf("%d\n",ans);

    }
}
