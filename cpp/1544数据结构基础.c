#include<stdio.h>
struct student//����һ����������������ǰ���壬������Ϊstudent,��������Ϊstruct
{
   char name[20];//�����������ַ���[20]
   int mark;//�����α���
}student[10];//�������Щ��������10��
int main()
{
    int i;
    for(i=0;i<10;i++)
    {
        scanf("%s %d",&student[i].name,&student[i].mark);//������������ĸ�ʽΪ�ˣ�student[i].nameΪ����ֵ���뺯���е�name��ַ�ڣ���Ϊ���������ĵ�i������
    }
    for(i=0;i<10;i++)
    {
        printf("%s %d\n",student[i].name,student[i].mark);
    }
    return 0;
}
