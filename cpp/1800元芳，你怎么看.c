#include<stdio.h>
int main()
{
    int sum,x,y,j,i;
    while(scanf("%d%d%d%d",&x,&y,&i,&j)!=EOF)
    {
        if(i>x&&(j+y)%(i-x)==0)//��(����)*x+y=(����)*i-j,������(����)*(i-x)=y+j,���(����)=(y+j)/(i-x)
            printf("He is right\n");//���������̶����Ҳ�ΪС��������(y+j)/(i-x)�ض�������(j+y)%(i-x)==0
        else
            printf("Back to the adult, it surely has something\n");
    }
    return 0;
}
