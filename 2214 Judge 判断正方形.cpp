#include<stdio.h>
#include<algorithm>
#include<math.h>///�ж��ĸ��������Ƿ���������Σ�ֻ���ж��ı���ȣ����ҶԽ������
using namespace std;
int main()
{
    double x1,y1,x2,y2,x3,y3,x4,y4;
    while(scanf("%lf%lf%lf%lf%lf%lf%lf%lf",&x1,&y1,&x2,&y2,&x3,&y3,&x4,&y4)!=EOF)
    {
        if(x1==x2&&x2==x3&&x3==x4&&y1==y2&&y2==y3&&y3==y4)///�ӣ��ĸ�����ͬһλ���غ�ʱ�����������㷨Ҳ���yes��Ӧ���⿼��
        {
            printf("No\n");
            continue;
        }
        double dis[6];///��������洢�������볤�ȣ���������
        dis[0]=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
        dis[1]=sqrt((x1-x3)*(x1-x3)+(y1-y3)*(y1-y3));///�������빫ʽ
        dis[2]=sqrt((x4-x2)*(x4-x2)+(y4-y2)*(y4-y2));
        dis[3]=sqrt((x4-x3)*(x4-x3)+(y4-y3)*(y4-y3));
        dis[4]=sqrt((x1-x4)*(x1-x4)+(y1-y4)*(y1-y4));
        dis[5]=sqrt((x3-x2)*(x3-x2)+(y3-y2)*(y3-y2));
        sort(dis,dis+6);///��������Ϊ�޷��жϸ������ĸ��������Ժ���˳�����Ҫ���򣬽϶̵Ŀ϶�Ϊ�ıߣ��ϳ��ľ��ǶԽ���
        if(dis[0]==dis[1]&&dis[0]==dis[2]&&dis[0]==dis[3]&&dis[4]==dis[5])
        {
            printf("Yes\n");///֤��Ϊ�����ε����������ı���ȣ��ҶԽ�����ȣ��˴������жϱ���Խ��߳� ���Ŷ���sqrt(2) �Ĺ�ϵ��
        }
        else
        {
            printf("No\n");
        }
    }
    return 0;
}
