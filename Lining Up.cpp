#include<stdio.h>
struct point//����ṹ��洢����
{
    int x,y;
}poi[708];//���߰�������
int main()
{
    int t,i,n,j,flag;
    while(scanf("%d",&n)!=EOF)
    {
        if(n==0)break;//����0��������
        for(i=0;i<n;i++)
        {
            scanf("%d%d",&poi[i].x,&poi[i].y);
        }
        int big=0;
        for(i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                flag=0;
                for(int k=j+1;k<n;k++)
                {
                    if((poi[k].x-poi[j].x)*(poi[j].y-poi[i].y)==(poi[j].x-poi[i].x)*(poi[k].y-poi[j].y))//��б��������б����ͬ��������������һ��ֱ�ߣ�ǰ����ȷ��б�ʣ��������ж��Ƿ���һ��ֱ��
                        flag++;
                }
                big=big>flag?big:flag;//���������⼸���㶼�ܳ�һ��ֱ�ߣ��������������ֱ��
            }
        }
        printf("%d\n",big+2);//��ʼ��Ϊ����������㣬������һ
    }
    return 0;
}
