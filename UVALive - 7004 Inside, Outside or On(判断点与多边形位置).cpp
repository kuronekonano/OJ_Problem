#include<stdio.h>///�жϵ��Ƿ��ڶ�����ڣ��⣬����ϣ��������ж���ζ�����ĳ�����γɱߵļнǣ����н�֮�Ͳ�����360�����ڶ������
#include<math.h>///�������Ҷ�������Ƕȣ�����ͣ������ڶ���α���ʱ����ĳ����ĽǶ�Ϊ180��
#include<string.h>
#define PI acos(-1)
double cal(int px,int py,int x1,int y1,int x2,int y2)///����Ƕ�
{
    double a=sqrt((px-x1)*(px-x1)+(py-y1)*(py-y1));
    double b=sqrt((px-x2)*(px-x2)+(py-y2)*(py-y2));
    double c=sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
    return acos((a*a+b*b-c*c)/(2*a*b))/PI;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int k,n,px,py,x[20],y[20],ans[20];
        scanf("%d%d%d",&n,&px,&py);
        memset(ans,-1,sizeof(ans));///��ʼ��ans
        for(int i=0;i<n;i++)
        {
            scanf("%d",&k);
            for(int j=0;j<k;j++) scanf("%d%d",&x[j],&y[j]);
            double sum=0;
            for(int j=0;j<k;j++)
            {
                double tmp=cal(px,py,x[j],y[j],x[(j+1)%k],y[(j+1)%k]);///һ���������������������������γɵĽǶ�
                if(px==x[j]&&py==y[j]||tmp==1)///�ڶ������
                {
                    ans[i]=0;
                    break;
                }
                sum+=tmp;///�Ƕ����
            }
            if(ans[i]==-1&&fabs(sum-2)<0.000000001) ans[i]=1;///�����ڶ�����ϣ������ڲ����ⲿ
            else if(ans[i]==-1) ans[i]=2;
        }
        for(int i=0;i<n;i++)printf("%d%c",ans[i],i==n-1?'\n':' ');
    }
}
