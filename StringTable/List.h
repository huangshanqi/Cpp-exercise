//List.h ����洢��������ṹ����
#ifndef LIST_H_
#define LIST_H_

#ifndef _IOSTREAM_H
#include <iostream>
#endif
//��������Ԫ��
class Link
{
public:
	//����Ԫ�Ĺ��캯��
	Link(Link* pNext,int nId):next(pNext),id(nId){}
	//��������
	~Link(){delete next;}
	//���ָ����һ������Ԫ��ָ��
	Link* Next() const {return next;}
	int Id() const {return id;}
private:
	//�������������
	int id;
	//ָ����һ�������Ա��ָ��
	Link* next;

};

//����洢����������ṹ��
class List
{
public:
	//���캯��
	List():head(0){}
	//����������ʹ�õݹ鷨�������
	~List(){delete head;};
	//�������Ԫ��
	void Add(int id);
	//��������ͷָ��
	const Link* GetHead() const{return head;}
private:
	//���������ͷָ��
	Link* head;

};
#endif