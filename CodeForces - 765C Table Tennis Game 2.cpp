#include<stdio.h>
int main()
{
    int k,a,b;
    while(scanf("%d%d%d",&k,&a,&b)!=EOF)
    {
        if(a%k&&b/k==0||b%k&&a/k==0)printf("-1\n");
        else printf("%d\n",a/k+b/k);
    }
}
///ƹ���������һ����Ӯ���˵�1�֣�����˲��÷֣�����һ�˵õķ����ﵽk��ʱ�����˷����������㣬����һ����һ��
///�������˵õ������з�����a��b�������ܹ������˶��پֱ������ܷ�����k����֪������һ���˴ﵽ�˼���k
///��ô�ܾ����������˴ﵽk�ֵĴ���֮�͡�a%k��b%k���Եõ���ûӮ��ĳһ���У�����˵õ����֡�
///���Կ�������һ����Ӯ��ʱ����һ���˵���0�֣�ֱ��ĳһ�֣�һ����Ӯ�ˣ���һ���˵õ��ܷ���%k�֡������������µ����������һ����Ӯ������һ��
///��һ�����ܷ�%k����0ʱ��������Ϊ�����ÿ��Ӯ������ʤ����һ����һ��û�á�
///����һ�����ܷ���%k��Ϊ0ʱ����һ������ȫûӮ������͵���Ӯ���˶���ķ���û�еط����䣬�ǲ����ܷ����������������-1