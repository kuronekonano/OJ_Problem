#include <algorithm>
#include <iostream> ///����string�Ͷ�������ͷ�ļ�
#include <stdio.h>
#include <string.h>
using namespace std;
struct gun {
  // string
  // name;///string�͵Ķ����������Լ�ʹ�õķ������Լ��Ƿ���Ҫ���������С������char����Ϊ�˱ȽϷ��㣬������ʱ�������ֶ������ַ���
  char name[205];
  int a;
  int money;
} guns[1000005];
int cmp(gun a, gun b) // cmp�ԱȺ���
{
  if (a.a == b.a) {
    if (a.money == b.money) {
      // return
      // a.name<b.name;///�Ƚ��ַ�����������Ϊʹ��string�Ͷ��������֣���ʹ��char�ͱȽ��������strcmp�������ҷ��ص����ַ��ͣ�����int�͵ĺ����лᱨ��
      return (
          strcmp(a.name, b.name) <
          0); /// ʹ��strcmp����ʱֱ�ӷ��رȽ�ֵ���ڻ�С�ڻ����0����������ַ��ص�ֵΪchar�͵����
    }
    return a.money <
           b.money; /// ��Ҫע�����������ýṹ���ڵ�Ԫ�ؽ������Ƚ�ʱ������ע��Ҫa��b��x,y��ǰ�棬Ԫ�������ں���
  }
  return a.a > b.a;
}
int main() /// ������
{
  int t, i, j, n;
  scanf("%d", &t);
  for (i = 0; i < t; i++) {
    cin >> guns[i].name; /// string���Ǳ�����cin cout���������
    scanf("%d%d", &guns[i].a, &guns[i].money);
  }
  sort(guns, guns + t, cmp); // �ṹ������Ҫ��cmp�Զ��庯��
  for (i = 0; i < t; i++) {
    cout << guns[i].name << endl;
  }
  return 0;
}
