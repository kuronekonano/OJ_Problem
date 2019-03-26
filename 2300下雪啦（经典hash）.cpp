#include<stdio.h>///hash
#include<vector>
using namespace std;
int snow[100008][6];///���ʮ���ѩ����ÿƬѩ������������
bool check(int x,int y)///�Ƚϲ��֣�Ͷ�������a��ʾ������ȡ���ĵ�jƬѩ����b��ʾ���ڱ����Ļ����Ϊkey��ѩ��i
{
    int i,j;
    for(i=0;i<6;i++)///��Ƭ����Ƚ�
    {
        bool equalx=true,equaly=true;///��ʼ���Ƕ���TRUE�ģ������˲�ͬ�ĲŻ���FALSE��ͬʱ�����Ľ��Ҳ�᷵��FALSE
        for(j=0;j<6;j++)///��Ƭ
        {
            equalx=equalx&&(snow[x][j]==snow[y][(i+j)%6]);///����Ƚ�
        }
        for(j=0;j<6;j++)
        {
            equaly=equaly&&(snow[x][j]==snow[y][(i+6-j)%6]);///����Ƚ�
        }
        if(equalx||equaly)///�����и�������ıȽϣ�����ok&&��Ŀ���ǣ�ÿת��һ�£��Ƚ��������꣬��һ������ͬ����ô&&�󣬶��᲻ͬ
        {
            return true;///����ͬ�ķ�����
        }
    }
    return false;
}
int main()
{
    int t;
    scanf("%d",&t);///T������
    while(t--)
    {
        int i,j,n;///����int��vector��������90001������
        vector<int>Hash[90001];///�����ҵĴ�����û���������ģ��ֲ��û������������
        bool flag=false;
        scanf("%d",&n);///nƬѩ��
        for(i=0;i<n;i++)
        {
            int key,sum=0;
            for(j=0;j<6;j++)
            {
                scanf("%d",&snow[i][j]);
                sum=sum+snow[i][j];///��Ƭ�������,��һ���Ļ��꣬��ô�п�������ͬ��
            }
            key=sum%90001;///����һ���ģ���ģ����С����֮��浽key��
            for(j=0;j<Hash[key].size();j++)///������key��û������ͣ���ô����size����0��Ҳ����˵���ѭ������˳���ж����Ƿ��п�����ͬ��ѩ��
            {
                if(check(Hash[key][j],i))///ѭ���ȽϺ�Ϊkey��j��ѩ��
                {
                    flag=true;
                }
            }
            Hash[key].push_back(i);///���û�У������ϸ�ѭ������������ڱ���������Ļ���ͷ����������������ѩ���ı��i��������������ѭ���з��ֲ�����ͬ��ѩ����Ҳ�����Ͷ����Ӧ��key��������
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
///�����check�����ж�ʱ���������ѭ���ȼ���
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
