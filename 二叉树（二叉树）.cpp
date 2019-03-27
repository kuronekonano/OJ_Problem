//#include<stdio.h>//ÕâÊÇ¼ÙµÄ
//#include<string.h>
//int a[100000],b[100000];
//int main()
//{
//    int x,y,i,t,k;
//    while(scanf("%d%d",&x,&y)!=EOF)
//    {
//        a[1]=x;b[1]=y;
//        for(i=2;;i++)
//        {
//            a[i]=(a[i-1])/2;
//            if(a[i]==1)
//            {
//                k=i;
//                break;
//            }
//        }
//        for(i=2;;i++)
//        {
//            b[i]=(b[i-1]/2);
//            if(b[i]==1)
//            {
//                t=i;
//                break;
//            }
//        }
//        bool flag=false;
//        for(i=1;i<=k;i++)
//        {
//            for(int j=1;j<=t;j++)
//            {
//                if(a[i]==b[j])
//                {
//                    printf("%d\n",a[i]);
//                    flag=true;
//                    break;
//                }
//            }
//            if(flag==true)
//                break;
//        }
//    }
//    return 0;
//}
