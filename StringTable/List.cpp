//List.cpp--List.h��ʵ���ļ���ʵ��������Ĺ���
#include "List.h"

//������Ԫ����ӵ��б�ͷ
void List::Add(int id)
{
	
	Link* pLink=new Link(head,id);
	head=pLink;
}

