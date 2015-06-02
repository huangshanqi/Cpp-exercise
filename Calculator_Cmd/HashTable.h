//HashTable.h
//�����ϣ���࣬��ϣ�����ݽṹ�ǻ���ʹ�ñ��������������ӳ���ʵ�ֵ�
#ifndef LIST_H_
#include "List.h"
#endif

#ifndef HASHTABLE_H_
#define HASHTABLE_H_

class HashTable
{
public:
	//��������������
	explicit HashTable(int s);
	~HashTable();
	//�����ַ������ڵĶ��б�
	const List& Find(const char* str) const;
	//���string->ID��ӳ��
	void Add(const char* str, int id);
private:
	
	//��ϣ���б������
	int size;
	//�����ϣ����
	int Hash(const char* str) const;
	//������б�
	List *shortList;

};
#endif