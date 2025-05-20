#include<stdio.h>
#include<string.h>//用于对比字符串是否相等的函数库
int main()
{
    char c[4],a[3]="NO",b[4]="YES";
    while(scanf("%s",&c)!=EOF)
    {
        if(strcmp(c,b)==0)//可以使用库函数strcmp比较。strcmp是C语言比较字符串的库函数。形式为int strcmp(char *a, char *b);
//该函数会对a和b的每个字符，按照ascii码值比较，如果二者完全相同返回0；如果a的ascii码值先出现较大者，会返回1；否则返回-1.
//所以，要判断字符串相等，可以使用if(strcmp(string1, string2) == 0)
//如果返回为0，则相等，否则不等。
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
