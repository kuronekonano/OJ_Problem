//#include<stdio.h>///A�����
//#include<string.h>
//int main()
//{
//    int t;
//    char s[50005];
//    scanf("%d",&t);
//    while(t--)
//    {
//        scanf("%s",s);
//        int n=strlen(s);
//        if(s[0]==s[n-1]&&n>2)
//        {
//            printf("YES\n");
//        }
//        else
//        {
//            printf("NO\n");
//        }
//    }
//    return 0;
//}
//#include<stdio.h>///I��ԽԼ��
//#include<math.h>
//int main()
//{
//    int t;
//    scanf("%d",&t);
//    while(t--)
//    {
//        int n,p,i;
//        scanf("%d%d",&n,&p);
//        int flag=0;
//        for(i=2;i<=sqrt(n);i++)///��������ע�ⷶΧ������n
//        {
//            if(n%i==0)
//            {
//                flag+=2;
//            }
//            if(i*i==n)
//            {
//                flag--;
//            }
//        }
//        if(flag+2==p)
//        {
//            printf("YES\n");
//        }
//        else
//        {
//            printf("NO\n");
//        }
//    }
//}
#include<stdio.h>///�ⷽ�̣����Ǳ���
int main()
{
    int n,k,a,b,c;
    while(scanf("%d%d%d%d%d",&n,&k,&a,&b,&c)!=EOF)
    {
        int i,j;
        bool flag=false;
        for(i=0;i<=k;i++)///�����ѣ����Χ10000
        {
            for(j=0;j<=k-i;j++)
            {
                int m=k-i-j;
                if(i*a+j*b+m*c==n)
                {
                    printf("Yes\n");
                    flag=true;
                    break;
                }
            }
            if(flag)
                break;
        }
        if(flag==false)
        {
            printf("No\n");
        }
    }
    return 0;
}
