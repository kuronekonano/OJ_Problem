#include<cstdio>/*printf只能输出C语言内置的数据，而string不是内置的，只是一个扩展的类，这样肯定是链接错误的。string不等于char*，
&a代表的是这个字符串的存储地址，并不是指向字符串的首地址，aa
对象中包含一个指向"string"的指针, &aar得到的是这个对象的地址,不是"string"的地址。*/
#include<iostream>
#include<algorithm>
using namespace std;
struct student//结构体：struct是结构体函数，表示一个结构体，是定义了一个框架，student是这个结构体框架的名字
{
    int num;//比方说结构体是个名片，student就是这个名片的类型，框定了这个结构体都有什么信息
    string name;//stu是指这个类型的名片的单个名片的名字，说明了这个结构体（名片）中的信息具体是什么内容
    int mark;//还可以定义其他名字的结构体，但是也是student类型的，或者定义一个新类型的结构体
}stu[100005];//stu是一个名为student的类型的结构体的变量名称，如果是数组则表示有100005个名为stu的student类型结构体，每个人可存放三个信息在这个结构体中
int cmp (student a, student b)//自定义函数
{
    return a.num < b.num;//返回值为a.num<b.num,其中表示了这个结构体中的num信息相互比较因此有小数点。
}
int cmt (student a, student b)
{
    if(a.mark==b.mark)//若成绩相同
    {
        return a.num<b.num;//则按照学号排序
    }
    return a.mark < b.mark;
}
int cme(student a,student b)
{
    if(a.name.compare(b.name)==0)//若名字相同
        return a.num < b.num;//则按照学号排序
    return(a.name.compare(b.name)<0);//compare函数用于比较字符串若返回值小于零则为升序排列，返回前者
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
                 printf("%06d ",stu[i].num);//通过%06d可以控制输出整型的宽度，因为cout输出控制精度较麻烦，所以还是用printf单独输出了
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

