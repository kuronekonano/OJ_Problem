#include<stdio.h>
#include<string.h>//���ڶԱ��ַ����Ƿ���ȵĺ�����
int main()
{
    char c[4],a[3]="NO",b[4]="YES";
    while(scanf("%s",&c)!=EOF)
    {
        if(strcmp(c,b)==0)//����ʹ�ÿ⺯��strcmp�Ƚϡ�strcmp��C���ԱȽ��ַ����Ŀ⺯������ʽΪint strcmp(char *a, char *b);
//�ú������a��b��ÿ���ַ�������ascii��ֵ�Ƚϣ����������ȫ��ͬ����0�����a��ascii��ֵ�ȳ��ֽϴ��ߣ��᷵��1�����򷵻�-1.
//���ԣ�Ҫ�ж��ַ�����ȣ�����ʹ��if(strcmp(string1, string2) == 0)
//�������Ϊ0������ȣ����򲻵ȡ�
        {
            printf("NO\n");
        }
    else if(strcmp(c,a)==0)
        {
            printf("YES\n");
        }
    }
    return 0;
}
