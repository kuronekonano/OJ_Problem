#include<stdio.h>
#include<string.h>
int main()
{
    char pi[10005];
    int i,n,flag;
    while(gets(pi))//因为有空格存在所以不用scanf输入，且空格不算一位，小数点算一位，要跳过空格所占位数
    {
        n=strlen(pi);
        flag=0;
        for(i=0;i<n;i++)
        {
                switch(pi[i])
              {
                case ' ':continue;//当输入为空格时，不计数，重新回到循环
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
               if(flag%100==0)//每到一百个数时换行，其中因为空格不计数所以用flag重新计数
               {
                   printf("\n");
               }
               else if(i!=n-1)//无法用flag计数，因为没有计数空格，因此不一定等于n
               {
                   printf(" ");//若用i计数，则因为数组从零开始，则到第i=n-1位时，也就是最后一位，不需要再输出空格
               }
        }
        if(flag%100!=0)
            printf("\n");//跳出循环后必须换行
    }
    return 0;
}
