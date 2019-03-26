#include<stdio.h>///判断两个超长数字是否相等，用字符串处理成相同格式
#include<string.h>///比如1.000000和1比较，1.12000000和1.12比较
int main()
{
    char a[105900],b[100460];///数组要开大，否则什么错误都可能经历
    while(scanf("%s %s",a,b)!=EOF)
    {
        int lena=strlen(a);
        int lenb=strlen(b);
        if(strchr(a,'.')!=NULL)///只用判断小数，所以用strchr函数先查找字符串内是否有小数点
        {
            while(a[--lena]=='0');///长度比实际下标大1，所以先--，判断最后一位是否是0，是0则用--循环减掉
            if(a[lena]=='.')///一直减到不是0时，判断是小数点还是一个数
            {
                lena--;///是小数点则忽略掉
            }
            a[++lena]='\0';///不是则在最后一位加1的位置放上结束标识符\0，注意这里可以使用lena+1，或++lena，注意是先加后赋值，否则会先赋值后加
        }
        if(strchr(b,'.')!=NULL)///同样处理第二个数
        {
            while(b[--lenb]=='0');
            if(b[lenb]=='.')
            {
                lenb--;
            }
            b[++lenb]='\0';
        }
        if(strcmp(a,b)==0)///最后拿处理好的字符串再比较
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }
    return 0;
}
