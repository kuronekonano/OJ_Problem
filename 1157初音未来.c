#include<stdio.h>
#include<string.h>
int main()
{
    char pi[10005];
    int i,n,flag;
    while(gets(pi))//��Ϊ�пո�������Բ���scanf���룬�ҿո���һλ��С������һλ��Ҫ�����ո���ռλ��
    {
        n=strlen(pi);
        flag=0;
        for(i=0;i<n;i++)
        {
                switch(pi[i])
              {
                case ' ':continue;//������Ϊ�ո�ʱ�������������»ص�ѭ��
                case '1':printf("ichi");break;
                case '2':printf("ni");break;
                case '3':printf("san");break;
                case '4':printf("yon");break;
                case '5':printf("go");break;
                case '6':printf("roku");break;
                case '7':printf("nana");break;
                case '8':printf("hachi");break;
                case '9':printf("kyu");break;
                case '0':printf("zero");break;
                case '.':printf("ten");break;
               }
               flag++;
               if(flag%100==0)//ÿ��һ�ٸ���ʱ���У�������Ϊ�ո񲻼���������flag���¼���
               {
                   printf("\n");
               }
               else if(i!=n-1)//�޷���flag��������Ϊû�м����ո���˲�һ������n
               {
                   printf(" ");//����i����������Ϊ������㿪ʼ���򵽵�i=n-1λʱ��Ҳ�������һλ������Ҫ������ո�
               }
        }
        if(flag%100!=0)
            printf("\n");//����ѭ������뻻��
    }
    return 0;
}
