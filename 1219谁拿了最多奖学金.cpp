#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
struct student
{
    char name[25];
    int test;
    int mark;
    char off,west;
    int lit;
    int fin;
    int num;
}stu[105];
bool cmp(student a,student b)
{
    if(a.fin==b.fin)
    {
        return a.num>b.num;///��������ͬʱ�����Ⱥ�˳��������򣬴˴�Ӧ����ԽСԽ�ȣ�����Խ�ұ�
    }
    return a.fin<b.fin;///�˴��ҵ������ֵ����Ϊ������������Ǵ�С��������
}
int main()
{
    int t,n,i;
    while(scanf("%d",&n)!=EOF)
    {
        int sum=0;
        for(i=0;i<n;i++)
        {
            stu[i].fin=0;
            stu[i].num=i;///�˴��и��ӣ�����߽���һ��ʱ�����������Ⱥ�˳�������򣬴˴���ֵ��Ϊ�Ⱥ�˳����
            scanf("%s %d %d %c %c %d",stu[i].name,&stu[i].test,&stu[i].mark,&stu[i].off,&stu[i].west,&stu[i].lit);
            if(stu[i].test>80&&stu[i].lit>=1)///��󽱽���ж�����
            {
                stu[i].fin+=8000;
            }
            if(stu[i].test>85&&stu[i].mark>80)
            {
                stu[i].fin+=4000;
            }
            if(stu[i].test>90)
            {
                stu[i].fin+=2000;
            }
            if(stu[i].test>85&&stu[i].west=='Y')
            {
                stu[i].fin+=1000;
            }
            if(stu[i].mark>80&&stu[i].off=='Y')
            {
                stu[i].fin+=850;
            }
            sum=sum+stu[i].fin;///�˴�����ʱ���ɼ��������˽���֮��
        }
        sort(stu,stu+n,cmp);
        printf("%s\n",stu[n-1].name);///������ǵ�n-1���˵���Ϣ��Ҳ����˵n-1�����ǽ�������
        printf("%d\n",stu[n-1].fin);
        printf("%d\n",sum);
    }
    return 0;
}
