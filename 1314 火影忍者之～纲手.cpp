#include<stdio.h>///����map����һһ��Ӧ
#include<map>
#include<string>
#include<iostream>
#include<string.h>
using namespace std;
bool flag[1008][1009];///��ϵ����
int main()
{
    int m,n;
    string win,lose;
    while(scanf("%d",&m)!=EOF)
    {
        map<string,int>q;
        memset(flag,false,sizeof(flag));
        int sum=1;
        while(m--)
        {
            cin>>win>>lose;
            if(!q[win])q[win]=sum++;///sum��һֱ�����ӵģ���˶���map��˵���Ƕ�һ�޶��Ķ�Ӧint
            if(!q[lose])q[lose]=sum++;
            flag[q[win]][q[lose]]=true;///�ڹ�ϵ��Ǿ����У���¼map��Ӧ�ı�ŵĹ�ϵ
        }
        scanf("%d",&n);
        while(n--)///����
        {
            cin>>win>>lose;
            if(flag[q[win]][q[lose]])
            {
                printf("win\n");
            }
            else if(flag[q[lose]][q[win]])
            {
                printf("lose\n");
            }
            else
            {
                printf("unknown\n");
            }
        }
    }
}
