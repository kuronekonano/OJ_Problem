#include<stdio.h>///��̰��
#include<algorithm>///�Խ���ʱ������Ȼ��ѡ�����ʱ����̵ģ�Ȼ���ѡ�������Ŀ�ʼʱ������׼
using namespace std;///һ����һ����ѡ����Ŀ�ʼʱ��>=��ѡ������Ľ���ʱ�䣬��ô�Ǹ�������ǿ�ѡ��
struct npc
{
    int s,t;
    bool friend operator < (npc a ,npc b)///���������------>��ʽ�� bool friend operator<(�ṹ���� a���ṹ���� b)
    {                                                         ///    return   a.xxx < b.xxx
        return a.t < b.t;          ///     ��ʱ����sort����Ͳ���Ҫ����cmp�ˣ�ֱ�ӽ���sort��������Ϊ�ṹ����������Ѿ�������
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
