#include<stdio.h>
#include<iostream>
#include<stack>
using namespace std;
int main()
{
    int i,n,a[105];
    while(scanf("%d",&n)!=EOF)
    {
        stack<int>s;//����һ��int�͵�ջ����Ϊs
        for(i=1; i<=n; i++)
        {
            scanf("%d",&a[i]);//��ʼѭ���������֣�����˳���������
        }
        int j=1;//��ʼ��j
        for(i=1; i<=n; i++)//��������
        {
            s.push(i);//��1��n��������
            while(!s.empty()&&s.top()==a[j])//��˳����ջ���ж����ǿ�ջ����ջ����������ĵ�һ����
            {
                s.pop();//��ջ
                j++;//����������˳���ջ������˳������ջ��Ϊ�գ�����������������ֲ��������
            }
        }
        if(j==n+1)//j������������1���ȶ�ʱӦ��n+1
        {
            printf("Yes\n");
        }
        else
        {
            printf("No\n");
        }
    }
    return 0;
}
