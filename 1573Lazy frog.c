#include<stdio.h>
#include<math.h>
int main()
{
    int x;
    while(scanf("%d",&x)!=EOF)//�Բ���ô�ǻ���������
    {
        if(x<=3)
            printf("1\n");
        else
            printf("%d\n",x-2);//4��ʱ����һ�������׵����ף��ڶ���һ�׼����״ﵽ4��
    }
    return 0;
}
