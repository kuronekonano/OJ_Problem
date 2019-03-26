#include<stdio.h>///巧用map进行一一对应
#include<map>
#include<string>
#include<iostream>
#include<string.h>
using namespace std;
bool flag[1008][1009];///关系矩阵
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
            if(!q[win])q[win]=sum++;///sum是一直在增加的，因此对于map来说都是独一无二的对应int
            if(!q[lose])q[lose]=sum++;
            flag[q[win]][q[lose]]=true;///在关系标记矩阵中，记录map对应的标号的关系
        }
        scanf("%d",&n);
        while(n--)///提问
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
