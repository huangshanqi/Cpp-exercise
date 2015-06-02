//HashTable.h
//�����ϣ���࣬��ϣ�����ݽṹ�ǻ���ʹ�ñ��������������ӳ���ʵ�ֵ�
#ifndef LIST_H_
#include "List.h"
#endif

#ifndef HASHTABLE_H_
#define HASHTABLE_H_

//�����ϣ���б���б��������
const int LISTSIZE=127;
class HashTable
{
public:
	//�����ַ������ڵĶ��б�
	const List& Find(const char* str) const;
	//���string->ID��ӳ��
	void Add(const char* str, int id);
private:
	
	
	//�����ϣ����
	int Hash(const char* str) const;
	//������б�
	List shortList[LISTSIZE];  

};
#endif