#include<stdio.h>//�����ӷ�
#include<string.h>
int main()
{
    int i,j,t,n,k,z;
    int jw,ws;//jw�����λ�������洢��λ������ws����λ���������洢ÿһλ��ӵ���
    char s[105],e[105];
    int r[105];//���ڴ洢���ս��������
    scanf("%d",&t);//����t������
    while(t--)
    {
        jw=0;ws=0;//��ʼ����λ��ÿλ������
        scanf("%s%s",s,e);//������ӵ�A��B����
        n=strlen(s);//��s��eλ���������
        k=strlen(e);
        for(i=0;i<105;i++)//�����ʼ��
        {
            r[i]=0;
        }
        i=n-1;
        j=k-1;
        while(i>=0&&j>=0)//�Ӹ�λ��ʼ���
        {
            jw=(s[i]-'0')+(e[j]-'0')+jw;//jwΪ��Ӧÿһλ�������ӣ�jwΪ��һ�ν�λ��������'0'Ϊ��һ���ַ��͵���ת��Ϊ���ͣ��൱��ASCII�����
            r[ws++]=jw%10;//��ÿһλ����ͷ���ÿһλ�Ĵ洢�У���Ϊ����,ws++Ϊÿ�������ټӣ���ǰ��һλ�����Ὣws���������
            jw=jw/10;
            i--;j--;
        }
        while(i>=0)
        {
            jw=(s[i]-'0')+jw;
            r[ws++]=jw%10;
            jw=jw/10;
            i--;
        }
        while(j>=0)
        {
            jw=(e[j]-'0')+jw;
            r[ws++]=jw%10;
            jw=jw/10;
            j--;
        }
        if(jw>0)
            r[ws++]=jw;
        for(z=ws-1;z>=0;z--)
        {
            printf("%d",r[z]);
        }
        printf("\n");
    }
    return 0;
}
//#include<stdio.h>
//#include<string.h>
//int main()
//{
//    int i,t;
//    char a[1000],b[1000];
//    int c[1000];
//    scanf("%d",&t);
//    while(t--)
//    {
//        scanf("%s",a);
//        memset(c,0,sizeof(c));
//        int lena=strlen(a)-1;
//        scanf("%s",b);
//        int lenb=strlen(b)-1;
//        int lenc=0,getnum=0;
//        while(lena>=0&&lenb>=0)
//        {
//            getnum=(a[lena]-'0')+(b[lenb]-'0')+getnum;
//            c[lenc++]=getnum%10;
//            getnum=getnum/10;
//            lena--;
//            lenb--;
//        }
//        while(lena>=0)
//        {
//            getnum=getnum+a[lena]-'0';
//            c[lenc++]=getnum%10;
//            getnum=getnum/10;
//            lena--;
//        }
//        while(lenb>=0)
//        {
//            getnum=getnum+b[lenb]-'0';
//            c[lenc++]=getnum%10;
//            getnum=getnum/10;
//            lenb--;
//        }
//        if(getnum>0)
//        {
//            c[lenc++]=getnum;
//        }
//        for(i=lenc-1;i>=0;i--)
//        {
//            printf("%d",c[i]);
//        }
//        printf("\n");
//    }
//    return 0;
//}
