//#include<stdio.h>
//#include<string.h>
//int main()
//{
//    int t,n,i,j;
//    char a[100005],b[100005];//����@���У�����#�˸���˿��Ե��Ŵ��ַ���β��ǰ����
//    scanf("%d",&t);//������@ʱ��˵����֮ǰ���ַ�ȫ����Ч����֮����ַ�������Ч��
//    while(t--)//����Ч���ַ���Ų����һ�������У�������#ʱ������ָ�����ǰŲ��λ���������˸���ַ���#�ַ�
//    {
//        scanf("%s",a);//�����Ϊ�ǵ���ģ����Խ��������ҲҪ�������
//        n=strlen(a);
//        j=0;
//        for(i=n-1;i>=0;i--)
//        {
//            if(a[i]=='@')
//            {
//                break;
//            }
//            if(a[i]=='#')
//            {
//                if(i-2>=0)
//                {
//                    i=i-2;
//                }
//                else
//                {
//                    break;
//                }
//            }
//            b[j]=a[i];
//            j++;
//        }
//        for(i=j-1;i>=0;i--)
//        {
//            printf("%c",b[i]);
//        }
//        printf("\n");
//    }
//    return 0;
//}
#include<stdio.h>
#include<string.h>
int main()
{
    char str[100005],str2[100005];
    int i,j,t,n;
    scanf("%d",&t);
    while(t--)
    {
        memset(str2,' ',sizeof(str2));
        memset(str,' ',sizeof(str));
        scanf("%s",str);
        n=strlen(str);
        j=0;
        for(i=0; i<n; i++)
        {
            if(str[i]=='@')
            {
                j=0;
                continue;
            }
            else if(str[i]=='#')
            {
                j--;
                continue;
            }
            else
            {
                str2[j]=str[i];
            }
            j++;
        }
        str2[j]='\0';
        printf("%s\n",str2);
    }
    return 0;
}

