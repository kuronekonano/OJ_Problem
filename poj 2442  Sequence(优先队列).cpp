#include<stdio.h>///�������ȶ������ʹ��
#include<queue>
using namespace std;
int main()
{
    int t,i,j,m,n,num;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&m,&n);
        priority_queue<int ,vector<int>,less<int> >s;///һ�����ȼ� �� С->��
        priority_queue<int ,vector<int>,greater<int> >q;///һ�����ȼ� �� ��->С
        for(i=1; i<=m; i++)///����m��
        {
            if(i==1)///�Ƚ���һ����Ϊ��������q������
            {
                for(j=0; j<n; j++)
                {
                    scanf("%d",&num);
                    q.push(num);
                }
            }
            else
            {
                int numd[n+10],sum;
                for(j=0; j<n; j++)///���У�����һ��������
                {
                    scanf("%d",&numd[j]);
                }
                while(q.size())///��q�����У�һ��һ��ѡ��Ԫ�أ��ֱ����������������е�ÿһ��ֵ���
                {
                    sum=q.top();///ѡ������Ԫ�أ���Ϊsum
                    q.pop();///����
                    for(j=0; j<n; j++)///�������������ÿ������һ��
                    {
                        if(s.size()==n&&s.top()>sum+numd[j])///�������������n��Ԫ�أ��ж�s�����еĶ��ף���������е����ֵ���Ƿ���ڵ�ǰѡ��������������Ԫ��֮��
                        {
                            s.pop();///�����ڣ������Ǹ��ϴ���������������Ͷ��õĽ�С����
                            s.push(sum+numd[j]);
                        }
                        else if(s.size()<n)///s��������û�ﵽn��Ԫ�أ����������ȥ
                        {
                            s.push(sum+numd[j]);
                        }
                    }///����һ��ѭ���������ͽ���һ�����뵱ǰq�����е�ĳһ��Ԫ�������ϣ���ɸѡ����ǰn����С�������
                }///while����һ�ֽ���Ͷ����е���һ������������ɸѡ������е�ǰnСֵ
                while(s.size())///������ɸѡ��ϴ�ʱ��s�����ж�����С��ǰn����
                {
                    q.push(s.top());
                    s.pop();
                }///ÿ����ɸ��º���ͽ��ͳһ����Q������׼����һ��ɸѡ���
            }
        }
        while(q.size())
        {
            printf("%d%c",q.top(),(q.size()-1==0)?'\n':' ');
            q.pop();
        }
    }
    return 0;
}
