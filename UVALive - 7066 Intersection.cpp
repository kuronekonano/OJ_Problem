#include<stdio.h>
#include<math.h>
#include<algorithm>
#define Pi acos(-1)
using namespace std;
double cal(int r,int R,int x1,int x2,int y1,int y2)
{
    double dis=sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
    if(R<r)swap(r,R);
    if(R+r<=dis)return 0;///����
    if(dis<=R-r)///�ں�
    {
        return Pi*r*r;
    }
    if(dis>R-r&&dis<R+r)///�ཻ
    {
        double S1=Pi*r*r*2*acos((r*r+dis*dis-R*R)/(2*r*dis))/(2*Pi);///���Ҷ���������������cosֵ
        double S2=Pi*R*R*2*acos((R*R+dis*dis-r*r)/(2*R*dis))/(2*Pi);
        double S3=sin(acos((R*R+dis*dis-r*r)/(2*R*dis)))*R*dis;///�����������ֱ�ĶԽ��߳��ȳ�2,��ֱ��Բ�ľ�ĶԽ�����sinֵ���󳤶�
        return S1+S2-S3;///�����������ȥ������������(�ݳ�ԭ��)
    }

}
int main()
{
    int cas=0,i,r,R,x1,x2,y1,y2,t;
    scanf("%d",&t);
    while(t--)
    {
        cas++;
        scanf("%d%d%d%d%d%d",&r,&R,&x1,&y1,&x2,&y2);
        double area=cal(R,R,x1,x2,y1,y2)-2*cal(r,R,x1,x2,y1,y2)+cal(r,r,x1,x2,y1,y2);///�ݳ�ԭ��
        printf("Case #%d: %.6lf\n",cas,area);
    }
}
///�����ཻ���=����Բ�ཻ���-2*һ��Բ��һСԲ�ཻ���+��СԲ�ཻ���
