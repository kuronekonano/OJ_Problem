#include<cstdio>/*printfֻ�����C�������õ����ݣ���string�������õģ�ֻ��һ����չ���࣬�����϶������Ӵ���ġ�string������char*��
&a�����������ַ����Ĵ洢��ַ��������ָ���ַ������׵�ַ��aa
�����а���һ��ָ��"string"��ָ��, &aar�õ������������ĵ�ַ,����"string"�ĵ�ַ��*/
#include<iostream>
#include<algorithm>
using namespace std;
struct student//�ṹ�壺struct�ǽṹ�庯������ʾһ���ṹ�壬�Ƕ�����һ����ܣ�student������ṹ���ܵ�����
{
    int num;//�ȷ�˵�ṹ���Ǹ���Ƭ��student���������Ƭ�����ͣ���������ṹ�嶼��ʲô��Ϣ
    string name;//stu��ָ������͵���Ƭ�ĵ�����Ƭ�����֣�˵��������ṹ�壨��Ƭ���е���Ϣ������ʲô����
    int mark;//�����Զ����������ֵĽṹ�壬����Ҳ��student���͵ģ����߶���һ�������͵Ľṹ��
}stu[100005];//stu��һ����Ϊstudent�����͵Ľṹ��ı������ƣ�������������ʾ��100005����Ϊstu��student���ͽṹ�壬ÿ���˿ɴ��������Ϣ������ṹ����
int cmp (student a, student b)//�Զ��庯��
{
    return a.num < b.num;//����ֵΪa.num<b.num,���б�ʾ������ṹ���е�num��Ϣ�໥�Ƚ������С���㡣
}
int cmt (student a, student b)
{
    if(a.mark==b.mark)//���ɼ���ͬ
    {
        return a.num<b.num;//����ѧ������
    }
    return a.mark < b.mark;
}
int cme(student a,student b)
{
    if(a.name.compare(b.name)==0)//��������ͬ
        return a.num < b.num;//����ѧ������
    return(a.name.compare(b.name)<0);//compare�������ڱȽ��ַ���������ֵС������Ϊ�������У�����ǰ��
}

int main()
{
    int n,c,i,flag=0;
    while(~scanf("%d%d",&n,&c))
    {
        flag++;
        if(n==0)
        {
            break;
        }
        for(i=0;i<n;i++)
        {
            cin>>stu[i].num>>stu[i].name>>stu[i].mark;
        }
        if(c==1)
        {
            sort(stu,stu+n,cmp);
            printf("Case %d:\n",flag);
            for(i=0;i<n;i++)
            {
                 printf("%06d ",stu[i].num);//ͨ��%06d���Կ���������͵Ŀ�ȣ���Ϊcout������ƾ��Ƚ��鷳�����Ի�����printf���������
                 cout<<stu[i].name<<" "<<stu[i].mark<<endl;
            }
        }
        else if(c==2)
        {
            sort(stu,stu+n,cme);
            printf("Case %d:\n",flag);
            for(i=0;i<n;i++)
            {
                printf("%06d ",stu[i].num);
                cout<<stu[i].name<<" "<<stu[i].mark<<endl;
            }
        }
        else if(c==3)
        {
            sort(stu,stu+n,cmt);
            printf("Case %d:\n",flag);
            for(i=0;i<n;i++)
            {
                 printf("%06d ",stu[i].num);
                 cout<<stu[i].name<<" "<<stu[i].mark<<endl;
            }
        }
    }
    return 0;
}

