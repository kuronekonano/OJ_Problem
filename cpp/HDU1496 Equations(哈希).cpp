#include <bits/stdc++.h>
using namespace std;
short int hashi[2333333];
int main() {
  int a, b, c, d;
  while (scanf("%d%d%d%d", &a, &b, &c, &d) != EOF) {
    int ans = 0;
    if (a > 0 && b > 0 && c > 0 && d > 0 || a < 0 && b < 0 && c < 0 && d < 0)
      printf("%d\n", ans);
    else {
      memset(hashi, 0, sizeof hashi);
      for (int i = -100; i <= 100; i++)
        if (i)
          for (int j = -100; j <= 100; j++)
            if (j) {
              int sum = (a * i * i + b * j * j) * (-1);
              if (sum < 0)
                sum += 2000000;
              hashi[sum]++;
            }
      for (int i = -100; i <= 100; i++)
        if (i)
          for (int j = -100; j <= 100; j++)
            if (j) {
              int sum = c * i * i + d * j * j;
              if (sum < 0)
                sum += 2000000;
              if (hashi[sum])
                ans += hashi[sum];
            }
      printf("%d\n", ans);
    }
  }
}
/**
//#include<stdio.h>
//#include<string.h>
//short int hashi[2333333];///���ֵ 100*100*50*2
//int main()
//{
//    int a1,a2,a3,a4,i,j;
// while(scanf("%d%d%d%d",&a1,&a2,&a3,&a4)!=EOF)///a1~a5,x1~x5�ķ�Χ����-50~50��
//    {
//        memset(hashi,0,sizeof(hashi));
//        for(i=-100; i<=100; i++)
//        {
//            if(i)///x1�൱��i����һֱ�仯��������if��Ϊ���ų�0
//            {
//                for(j=-100; j<=100; j++)
//                {
//                    if(j)
//                    {
//                        int
sum=(a1*(i*i)+a2*(j*j))*(-1);///ܳ��ע��˷��Ⱥ�˳�򣬾������˼�����
//                        if(sum<0) sum=sum+2000000;
//                        hashi[sum]++;
//                    }
//                }
//            }
//        }
////        for(int i=0;i<=2000000;i++)
////        {
////            printf("%d\n",hashi[i]);
////        }
//        int flag=0;
//        for(i=-100; i<=100; i++)
//        {
//            if(i)
//            {
//                for(j=-100; j<=100; j++)
//                {
//                    if(j)
//                    {
//                        int sum=(a3*(i*i)+a4*(j*j));
//                        if(sum<0) sum=sum+2000000;
//                        if(hashi[sum]) flag=flag+hashi[sum];
//                    }
//                }
//            }
//        }
//        printf("%d\n",flag);
//    }
//    return 0;
//}
**/
