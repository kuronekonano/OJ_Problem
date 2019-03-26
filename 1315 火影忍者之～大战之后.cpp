#include<stdio.h>///简单贪心
#include<algorithm>///对结束时间排序，然后选择结束时间最短的，然后把选择的任务的开始时间作标准
using namespace std;///一旦下一个可选任务的开始时间>=已选择任务的结束时间，那么那个任务就是可选的
struct npc
{
    int s,t;
    bool friend operator < (npc a ,npc b)///重载运算符------>格式： bool friend operator<(结构体名 a，结构体名 b)
    {                                                         ///    return   a.xxx < b.xxx
        return a.t < b.t;          ///     此时进行sort排序就不需要导入cmp了，直接进行sort操作，因为结构体中运算符已经被重载
    }
}a[108];
//bool cmp(npc a,npc b)
//{
//    return a.t<b.t;
//}
int main()
{
    int n,i;
    while(scanf("%d",&n)!=EOF)
    {
        if(!n)return 0;
        for(i=0;i<n;i++)
        {
            scanf("%d%d",&a[i].s,&a[i].t);
        }
        sort(a,a+n);
        int sum=1,flag=a[0].t;
        for(i=1;i<n;i++)
        {
            if(a[i].s>=flag)
            {
                sum++;
                flag=a[i].t;
            }
        }
        printf("%d\n",sum);
    }
    return 0;
}
