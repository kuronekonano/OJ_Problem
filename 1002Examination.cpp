#include<stdio.h>
#include<algorithm>
using namespace std;
int main()
{
    int i,n,m,k,flag=0;
    while(scanf("%d%d%d",&n,&m,&k)!=EOF)
    {
        flag++;
        int stu[n*m+5];//c++��˿��������ﶨ�����飬+5��ӵ��ֹ���鲻����
        for(i=0;i<n*m;i++)
        {
            scanf("%d",&stu[i]);

        }
        sort(stu,stu+n*m);
        printf("Scenario #%d\n",flag);
        printf("%d\n",stu[n*m-k]);//��Ϊ�ǵڼ����������ǵ�������
        printf("\n");
    }
    return 0;
}
