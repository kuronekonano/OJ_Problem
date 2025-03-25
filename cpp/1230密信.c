#include<stdio.h>
#include<string.h>
int main()
{
    char c[10000];
    int n,i;
    while(scanf("%s",c)!=EOF)//switch˫�ⷨ
    {
        n=strlen(c);
        for(i=0;i<n;i++)
        {
            switch(c[i])
            {
                case 'b':printf(" ");break;//c[i]=' ';break;
                case 'q':printf(",");break;//c[i]=',';break;
                case 't':printf("!");break;//c[i]='!';break;
                case 'm':printf("l");break;//c[i]='l';break;
                case 'i':printf("e");break;//c[i]='e';break;
                case 'c':printf("a");break;//c[i]='a';break;
                case 'a':printf("c");break;//c[i]='c';break;
                case 'e':printf("i");break;//c[i]='i';break;
                case 'l':printf("m");break;//c[i]='m';break;
                default:printf("%c",c[i]);
            }
        }
        printf("\n");//printf("%s\n",c);
    }
    return 0;
}
