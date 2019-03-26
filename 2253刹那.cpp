#include<stdio.h>//依然是结构体的运用
#include<algorithm>
using namespace std;
struct student//这里用上了结构体函数
{
    char name[105];
    long high;
}stu[1005];
int cmp(student a,student b)//记住结构体的sort排序自定义cmp函数的格式！！！
{
    return a.high<b.high;//升序排列
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
        sort(stu,stu+n,cmp);//结构体排序必须自定义函数
        printf("%s\n",stu[n-1].name);
    }
    return 0;
}
