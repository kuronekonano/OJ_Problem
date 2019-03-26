#include<stdio.h>
#include<algorithm>
using namespace std;
int main()
{
    int i,n,m,k,flag=0;
    while(scanf("%d%d%d",&n,&m,&k)!=EOF)
    {
        flag++;
        int stu[n*m+5];//c++因此可以在这里定义数组，+5多加点防止数组不够用
        for(i=0;i<n*m;i++)
        {
            scanf("%d",&stu[i]);

        }
        sort(stu,stu+n*m);
        printf("Scenario #%d\n",flag);
        printf("%d\n",stu[n*m-k]);//因为是第几名，所以是倒着数的
        printf("\n");
    }
    return 0;
}
