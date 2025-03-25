#include<stdio.h>
struct student//创建一个函数，在主函数前定义，函数名为student,函数类型为struct
{
   char name[20];//声明其中有字符串[20]
   int mark;//有整形变量
}student[10];//最后定义这些变量共有10组
int main()
{
    int i;
    for(i=0;i<10;i++)
    {
        scanf("%s %d",&student[i].name,&student[i].mark);//调用这个函数的格式为此，student[i].name为，将值放入函数中的name地址内，且为整个函数的第i个数据
    }
    for(i=0;i<10;i++)
    {
        printf("%s %d\n",student[i].name,student[i].mark);
    }
    return 0;
}
