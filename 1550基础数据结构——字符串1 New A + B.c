#include<stdio.h>//大数加法
#include<string.h>
int main()
{
    int i,j,t,n,k,z;
    int jw,ws;//jw代表进位，用来存储进位的数，ws代表位数，用来存储每一位相加的数
    char s[105],e[105];
    int r[105];//用于存储最终结果的数组
    scanf("%d",&t);//输入t组数据
    while(t--)
    {
        jw=0;ws=0;//初始化进位和每位的数字
        scanf("%s%s",s,e);//输入相加的A、B数字
        n=strlen(s);//有s和e位的数字相加
        k=strlen(e);
        for(i=0;i<105;i++)//数组初始化
        {
            r[i]=0;
        }
        i=n-1;
        j=k-1;
        while(i>=0&&j>=0)//从个位开始相加
        {
            jw=(s[i]-'0')+(e[j]-'0')+jw;//jw为对应每一位的求和相加，jw为上一次进位的数，减'0'为将一个字符型的数转换为整型，相当于ASCII码相减
            r[ws++]=jw%10;//将每一位的求和放入每一位的存储中，并为整型,ws++为每次先用再加，向前增一位【最后会将ws倒序输出】
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
