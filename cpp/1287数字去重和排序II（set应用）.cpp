#include <iostream>
#include <iterator> //����������ͷ�ļ���
#include <set> ///���ظ�Ԫ�ز����ٴβ��룬���Ҳ���Ԫ�ػ��Զ���������ô����
#include <stdio.h>
using namespace std;
int main() {
  long long n, a, i;
  set<long long> q;
  while (scanf("%lld", &n) != EOF) {
    q.clear(); /// �������
    set<long long>::iterator
        nano; // ������ָ���ʹ�ã��ȶ�����ʲô�����ģ�����ʲô�͵ģ���������
    for (i = 1; i <= n; i++) {
      scanf("%lld", &a);
      q.insert(a); // װ������
    }
    printf(
        "%d\n",
        q.size()); /// size���ص���һ��ֵ��Ŀ����һ��int�͵�ֵ����Ϊ%lld�������ֵĶ���
    printf(
        "%lld",
        *q.begin()); /// ��begin��end���ص���һ����ַ�����begin��Ҫָ����ߵ������нӣ����߼���*����������

    for (nano = ++q.begin(); nano != q.end();
         nano++) /// set�еĵ�ַ������������һ������Կ�����������ַ���ƶ�ָ��
    {
      printf(
          " %lld",
          *nano); /// end()���ص������������һ��ֵ�ĺ����Ǹ����������һ��ֵ��
    }
    printf(
        "\n"); /// ע�⣺�������е�++
               /// --�����Լ������Ǳ����ع��ģ���ԭ�������Ѿ���һ���ˡ�ͨ�����ص������ʵ��ָ���ƶ�
  }
  return 0;
}
