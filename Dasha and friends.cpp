#include<stdio.h>///�����̶�һȦ��ÿ���ϰ���Ͷ����λ�ã�
int main()
{
    int n,l,i,a[55],b[55],disa[105],disb[105],j;///�ĸ����飬����������������ԭ˳�����֣������������洢�����ϰ���֮��ľ��룬��ԭ���鳤�ȷ���������Ѱ����ͬ�Ĺ��ɣ���˳һ��Ȧ������˳��
    while(scanf("%d%d",&n,&l)!=EOF)///n���ϰ��Բ�ܳ�Ϊl
    {
        for(i=0;i<n;i++)///���벿��
        {
            scanf("%d",&a[i]);
        }
        for(i=0;i<n;i++)
        {
            scanf("%d",&b[i]);
        }
        bool flag;
        for(i=0;i<n-1;i++)///����ÿ�����ϰ���֮��ľ��룬ͷβ�����������㣬�����ܳ�������
        {
            disa[i]=a[i+1]-a[i];
            disb[i]=b[i+1]-b[i];
        }
        disa[n-1]=l-a[n-1]+a[0];///���һ���͵�0(1)������
        disb[n-1]=l-b[n-1]+b[0];
        for(i=n;i<2*n;i++)///������������飬�����ظ�����
        {
            disa[i]=disa[i-n];
            disb[i]=disb[i-n];
        }
        bool yes=false;
        for(i=0;i<n;i++)///��ʼѰ�������
        {
            if(disa[0]==disb[i])///��һ�������еĵ�һ����ʼһ��һ����ڶ���������ȣ�����ͬ
            {
                flag=true;///���ҵ�����ͬ�ģ�����һ����ʼ��ͬʱ�������������ָ�룬��ǰ�ȣ������ܷ���Ԥ���������ϰ��������еľ��붼һ��
                int k=1;///��һ���������һ�������Ƚϣ����ҵ��˵�0����һ���ģ���ô�������Ǵӵ�1����
                for(j=i+1;j<i+n;j++)
                {
                    if(disa[k]!=disb[j])///һ��������һ���ģ��˳����ѭ��������һ��ѭ�������ҿ�ͷһ��������
                    {
                        flag=false;
                        break;
                    }
                    k++;
                }
                if(flag)///�����һ��ѭ���ҵ��ˣ���ô�Ͳ��ü�������ȥ��
                {
                    yes=true;
                    break;
                }
            }
        }
        if(yes)///����������������2�ķ�������˳����ҵ����飬Ȼ���ٱȽ��Ƿ�һ��
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }
    return 0;
}