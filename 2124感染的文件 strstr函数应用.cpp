#include<stdio.h>
#include<string.h>///【strstr函数应用，strstr(str1,str2)】检查str1中是否包含str2，若包含，返回第一个查找到的str2首地址，不包含返回NULL空地址
int main()///包含于string.h头文件中
{
    int t,n,i;
    char a[56][25];
    char b[20008];
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%s",a[i]);
        }
        scanf("%s",b);
        bool flag=true;
        for(i=0;i<n;i++)
        {
            if(strstr(b,a[i])!=0)
            {
                printf("infected\n");
                flag=false;
                break;
            }
        }
        if(flag)
        {
            printf("not infected\n");
        }
    }
    return 0;
}
//#include<stdio.h>///手动比较
//#include<string.h>
//int main()
//{
//    char a[58][38],b[46460];
//    int t,n,i;
//    scanf("%d",&t);
//    while(t--)
//    {
//        scanf("%d",&n);
//        bool flag=false;
//        for(i=0; i<n; i++)
//        {
//            scanf("%s",a[i]);
//        }
//        scanf("%s",b);
//        int blen=strlen(b);
//        int i,j,k;
//        for(i=0; i<n; i++)
//        {
//            int alen=strlen(a[i]);
//            for(j=0; j<blen; j++)
//            {
//                int f=j;
//                for(k=0; k<alen; f++,k++)
//                {
//                    if(a[i][k]!=b[f])break;
//                }
//                if(k==alen)
//                {
//                    flag=true;
//                    break;
//                }
//            }
//            if(flag)break;
//        }
//        if(flag)
//        {
//            printf("infected\n");
//        }
//        else printf("not infected\n");
//    }
//    return 0;
//}
