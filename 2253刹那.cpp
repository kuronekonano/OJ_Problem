#include<stdio.h>//��Ȼ�ǽṹ�������
#include<algorithm>
using namespace std;
struct student//���������˽ṹ�庯��
{
    char name[105];
    long high;
}stu[1005];
int cmp(student a,student b)//��ס�ṹ���sort�����Զ���cmp�����ĸ�ʽ������
{
    return a.high<b.high;//��������
}
int main()
{
    int i,t,n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%s%d",stu[i].name,&stu[i].high);
        }
        sort(stu,stu+n,cmp);//�ṹ����������Զ��庯��
        printf("%s\n",stu[n-1].name);
    }
    return 0;
}
