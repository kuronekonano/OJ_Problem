#include<stdio.h>
#define m 317000011
using namespace std;
int main()
{
    long long a,b,c,sum,res;
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lld%lld%lld",&a,&b,&c);
        while(c--)
        {
            sum=b;
            res=1;
            while(sum)
            {
                if(sum%2!=0)
                {
                    res=(a%m)*(res%m)%m;
                }
                a=(a%m)*(a%m)%m;
                sum/=2;
            }
            a=res;
        }
        printf("%lld\n",a);
    }
    return 0;
}
//#include<iostream>
//#include<string.h>
//#define m 317000011
//using namespace std;
//int main()
//{
//    long long  res,tmp,a,b,c; int n;
//    cin>>n;
//    while(n--)
//    {
//        cin >> a>> b >> c;
//        while(c--)
//        {
//            tmp = b;res = 1;
//            while(tmp)
//            {
//                if(tmp & 1)
//                res = (a%m)*(res%m)%m;
//                a = (a%m)*(a%m)%m;
//                tmp >>= 1;
//            }
//            a = res;
//        }
//        cout<<a<<endl;
//    }
//    return 0;
//}
