//List.cpp--List.h��ʵ���ļ���ʵ��������Ĺ���
#include "List.h"

void List::Add(int id)
{
	//������Ԫ����ӵ��б�ͷ
	Link* pLink=new Link(head,id);
	head=pLink;
}

