#include<stdio.h>///hash
#include<vector>
using namespace std;
int snow[100008][6];///最多十万的雪花，每片雪花有六个花瓣
bool check(int x,int y)///比较部分，投入的数据a表示容器中取出的第j片雪花，b表示正在遍历的花瓣和为key的雪花i
{
    int i,j;
    for(i=0;i<6;i++)///逐片花瓣比较
    {
        bool equalx=true,equaly=true;///初始化是都是TRUE的，遇到了不同的才会变成FALSE，同时函数的结果也会返回FALSE
        for(j=0;j<6;j++)///六片
        {
            equalx=equalx&&(snow[x][j]==snow[y][(i+j)%6]);///正序比较
        }
        for(j=0;j<6;j++)
        {
            equaly=equaly&&(snow[x][j]==snow[y][(i+6-j)%6]);///逆序比较
        }
        if(equalx||equaly)///这里有个很巧妙的比较，用了ok&&，目的是，每转动一下，比较六个花瓣，有一个不相同，那么&&后，都会不同
        {
            return true;///有相同的返回真
        }
    }
    return false;
}
int main()
{
    int t;
    scanf("%d",&t);///T组数据
    while(t--)
    {
        int i,j,n;///定义int型vector容器，有90001个容器
        vector<int>Hash[90001];///网上找的代码是没有清容器的，怪不得会错！！！！！！
        bool flag=false;
        scanf("%d",&n);///n片雪花
        for(i=0;i<n;i++)
        {
            int key,sum=0;
            for(j=0;j<6;j++)
            {
                scanf("%d",&snow[i][j]);
                sum=sum+snow[i][j];///六片花瓣求和,和一样的花瓣，那么有可能是相同的
            }
            key=sum%90001;///将和一样的，求模法缩小数据之后存到key中
            for(j=0;j<Hash[key].size();j++)///这里若key中没有这个和，那么他的size就是0，也就是说这个循环条件顺带判断了是否有可能相同的雪花
            {
                if(check(Hash[key][j],i))///循环比较和为key的j个雪花
                {
                    flag=true;
                }
            }
            Hash[key].push_back(i);///如果没有，跳过上个循环，将这个正在遍历的数组的花瓣和放入容器。放入的是雪花的标号i，或是如果上面的循环中发现不是相同的雪花，也会继续投入相应和key的数组中
        }
        if(flag)
        {
            printf("Twin snowflakes found.\n");
        }
        else
        {
            printf("No two snowflakes are alike.\n");
        }
    }
    return 0;
}
///上面的check函数判断时，里面的内循环等价于
/*if((snow[a][0] == snow[b][i] &&
                snow[a][1] == snow[b][(i+1)%6] &&
                snow[a][2] == snow[b][(i+2)%6] &&
                snow[a][3] == snow[b][(i+3)%6] &&
                snow[a][4] == snow[b][(i+4)%6] &&
                snow[a][5] == snow[b][(i+5)%6])
                ||
                (snow[a][0] == snow[b][i] &&
                 snow[a][1] == snow[b][(i+5)%6] &&
                 snow[a][2] == snow[b][(i+4)%6] &&
                 snow[a][3] == snow[b][(i+3)%6] &&
                 snow[a][4] == snow[b][(i+2)%6] &&
                 snow[a][5] == snow[b][(i+1)%6]))

            return true;*/
