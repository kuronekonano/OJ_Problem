#include<stdio.h>///��n���˴�����������Ӯ�������Ҫ����ٳ��������μӱ�����������1�����˲��ܱ���
#include<algorithm>
using namespace std;
int main()
{
    long long n,a[556];
    a[1]=2;///���Ӯ��1����������ô���ٿ�����2���ˣ�������Ӯ��2����������ô������3���˱�������������
    a[2]=3;
    int i=2;
    while(a[i]<=1e18)///�������ű�ʾ���һ��Ӯ�ı������Σ������д������ʾӮ��ô�ೡ�������м��˲μӱ���
    {
        a[++i]=a[i-1]+a[i-2];///�õ�����쳲������ĵ���ʽ�����Ӯ��3���������൱�ڣ���������Ϊ2�˵ľ���Ӯ��1����������3�˾���Ӯ������
    }///���Ӯ3�����������������5�˾���     �������㣬��Ӯ100������ʱ���������ͻᳬ��1e18���ڵ�����������upper_bound�ҵ�nС��ĳ����������λ�ü������Ǹ�������ҪӮ�ĳ���
//    for(i=1;i<=100;i++)printf("%d  %lld\n",i,a[i]);
    while(scanf("%lld",&n)!=EOF)
    {
        int pos=upper_bound(a,a+i+1,n)-a;
        printf("%d\n",pos-1);///��Ϊupper_bound�ҵ����ǵ�һ������n��λ�ã�������λ��Ҫ-1����С�ڵ���n�Ļ�ʤ����
    }
}