#include<stdio.h>///两个优先队列组合使用
#include<queue>
using namespace std;
int main()
{
    int t,i,j,m,n,num;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&m,&n);
        priority_queue<int ,vector<int>,less<int> >s;///一个优先级 从 小->大
        priority_queue<int ,vector<int>,greater<int> >q;///一个优先级 从 大->小
        for(i=1; i<=m; i++)///输入m列
        {
            if(i==1)///先将第一列作为基础塞入q队列中
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
                for(j=0; j<n; j++)///几列，存入一个数组中
                {
                    scanf("%d",&numd[j]);
                }
                while(q.size())///从q队列中，一个一个选出元素，分别与后面输入的数组中的每一个值相加
                {
                    sum=q.top();///选出队首元素，记为sum
                    q.pop();///出列
                    for(j=0; j<n; j++)///和输入的数组中每个都加一遍
                    {
                        if(s.size()==n&&s.top()>sum+numd[j])///若超过或等于了n个元素，判断s队列中的队首（放入队列中的最大值）是否大于当前选出的数和数组中元素之和
                        {
                            s.pop();///若大于，弹出那个较大数，重新塞入求和而得的较小的数
                            s.push(sum+numd[j]);
                        }
                        else if(s.size()<n)///s队列中若没达到n个元素，加完就塞进去
                        {
                            s.push(sum+numd[j]);
                        }
                    }///这样一个循环下来，就将下一组数与当前q队列中的某一个元素相加完毕，并筛选出了前n个较小的求和数
                }///while的下一轮将求和队列中的下一个数，并继续筛选求和数中的前n小值
                while(s.size())///所有数筛选完毕此时在s队列中都是最小的前n个数
                {
                    q.push(s.top());
                    s.pop();
                }///每行完成更新后将求和结果统一塞回Q队列中准备下一行筛选求和
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
