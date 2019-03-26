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
        return a.num>b.num;///当奖金相同时按照先后顺序标码排序，此处应标码越小越先，排在越右边
    }
    return a.fin<b.fin;///此处找的是最大值，但为保险起见，还是从小到大排序
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
            stu[i].num=i;///此处有个坑，当最高奖金一样时，按照输入先后顺序来排序，此处赋值是为先后顺序标号
            scanf("%s %d %d %c %c %d",stu[i].name,&stu[i].test,&stu[i].mark,&stu[i].off,&stu[i].west,&stu[i].lit);
            if(stu[i].test>80&&stu[i].lit>=1)///五大奖金的判定条件
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
            sum=sum+stu[i].fin;///此处输入时即可计算所有人奖金之和
        }
        sort(stu,stu+n,cmp);
        printf("%s\n",stu[n-1].name);///输出的是第n-1个人的信息，也就是说n-1个人是奖金最多的
        printf("%d\n",stu[n-1].fin);
        printf("%d\n",sum);
    }
    return 0;
}
