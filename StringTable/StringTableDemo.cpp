//�����ַ�����Ĺ��ܵ�main����
#ifndef _IOSTREAM_
#include<iostream>
#endif

#ifndef LIST_H_ 
#include "List.h"
#endif

#ifndef HASHTABLE_H_
#include "HashTable.h"
#endif

#ifndef STRINGTABLE_H_
#include "StringTable.h"
#endif

int main(int argc,char* argu)
{
	//�����ַ�����
	StringTable stringTable;
	//���ַ������뻺����������ӳ��
	stringTable.ForceAdd("One");
	stringTable.ForceAdd("Two");
	stringTable.ForceAdd("Three");
	//ͨ���ַ���Ѱ��id
	int id=stringTable.Find("One");
	//���id
	std::cout<<"One at "<<id<<std::endl;
	//ͨ��idѰ���ַ���
	std::cout<<"String 0 is "<<stringTable.GetString(0)<<std::endl;
	return 0;
}

