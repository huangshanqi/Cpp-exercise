//HashTable.h��ʵ���ļ�
//ʵ�ֹ�ϣ�����ù�ϣ�������ӳ��Ͳ����ַ����Ĺ���
#include"HashTable.h"
#include <assert.h>

//��ϣ��������
int HashTable::Hash(char const *str) const
{
	//���ַ���Ϊ�գ���������
	assert(str!=NULL && str[0]!=0);
	unsigned h=str[0];
	//��������
	for (int i=1;str[i];i++)
		h=(h<<4)+str[i];
	//���࣬��֤��õ�������List�ķ�Χ��
	return h%LISTSIZE;
}

//����ַ�����������ӳ��
void HashTable::Add(const char *str, int id)
{
	//���й�ϣ�任���������
	int i=Hash(str);
	shortList[i].Add(id);

}

//�õ��ַ������ڵĶ��б�����
const List& HashTable::Find(const char *str) const
{
	//�������
	int i=Hash(str);
	return shortList[i];
}
