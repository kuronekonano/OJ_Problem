#include<stdio.h>///���ȶ�����
#include<queue>///����vector������Ȼ����Ҫ����ͷ�ļ���
using namespace std;
int main()
{
    int a,i,n;
    while(scanf("%d",&n)!=EOF)///ע�⣬����·����ұ�ʹ����>>�ᱨ������ճ������Ҫ�ÿո�ֿ�
    {
        priority_queue<int,vector<int>,greater<int> >q;///���ȶ����Զ������ȼ���ԭ���ȼ��ǴӴ�С����ֵԽ�����ȼ�Խ��
        for(i=0;i<n;i++)///������greater�Ǵ�С��������ȼ���less�ǴӴ�С
        {
            scanf("%d",&a);
            q.push(a);///����
        }
        int sum=0,small,smaller;///���ȶ��У����ȼ��ߵ��ȳ�����
        while(q.size()>1)///ģ�����ӹ���
        {
            small=q.top();///ѡȡ��������С��
            q.pop();///����
            smaller=small+q.top();///ѡȡ���к���С�ģ���ӣ��൱��������С�ĺϳ�һ��
            q.pop();///�Ѿ��ϳɵ����ѳ���
            sum=sum+smaller;
            q.push(smaller);///�µ�һ�����У���������������������С��,�����˺ϳ�һ�Ѻ���ֱȵ���һ�Ѹ�������
        }
        printf("%d\n",sum);
    }
    return 0;
}
