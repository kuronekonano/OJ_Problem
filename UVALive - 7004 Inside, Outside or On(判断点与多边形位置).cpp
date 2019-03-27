#include<stdio.h>///判断点是否在多边形内，外，或边上，计算所有多边形定点与某点所形成边的夹角，若夹角之和不等于360度则不在多边形内
#include<math.h>///利用余弦定理求出角度，计算和，当点在多边形边上时，与某两点的角度为180度
#include<string.h>
#define PI acos(-1)
double cal(int px,int py,int x1,int y1,int x2,int y2)///计算角度
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
        memset(ans,-1,sizeof(ans));///初始化ans
        for(int i=0;i<n;i++)
        {
            scanf("%d",&k);
            for(int j=0;j<k;j++) scanf("%d%d",&x[j],&y[j]);
            double sum=0;
            for(int j=0;j<k;j++)
            {
                double tmp=cal(px,py,x[j],y[j],x[(j+1)%k],y[(j+1)%k]);///一个点与多边形中相邻两点连线所形成的角度
                if(px==x[j]&&py==y[j]||tmp==1)///在多边形上
                {
                    ans[i]=0;
                    break;
                }
                sum+=tmp;///角度求和
            }
            if(ans[i]==-1&&fabs(sum-2)<0.000000001) ans[i]=1;///若不在多边形上，则在内部或外部
            else if(ans[i]==-1) ans[i]=2;
        }
        for(int i=0;i<n;i++)printf("%d%c",ans[i],i==n-1?'\n':' ');
    }
}
