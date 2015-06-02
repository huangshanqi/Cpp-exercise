//ʵ�ַ��ű���SymbolTable
#include "SymbolTable.h"
#ifndef _IOSTREAM_
#include <iostream>
#endif
#include<assert.h>

//��������StringBuffer��ʵ��
//���캯��,���������ֵ����������
StringBuffer::StringBuffer(int s)
:curOffset(0)
,size(s)
{
	buffer=new char[size];
}

//��������
StringBuffer::~StringBuffer()
{
	delete[] buffer;
}

//���ַ�����ӽ�������
void StringBuffer::Add(const char *str)
{
	//���ַ������ƽ�������
	strcpy(&buffer[curOffset],str);
	//�����ַ�����ƫ����
	curOffset+=std::strlen(str)+1;
}

//�жϸ����ַ�����ָ���Ļ������ַ����Ƿ���ͬ
//ʹ��offsetStringָ���������е��ַ���
bool StringBuffer::IsEqual(int offsetString,const char* str) const
{
	return std::strcmp(str,&buffer[offsetString])==0;
}

//ʵ�ַ��ű���
//���캯��
SymbolTable::SymbolTable(int size)
:curId(0)
,maxId(size)
,hashTable(size+1)
,stringBuffer(size*10)
{
	offsetString=new int[size+1];	
}

//��������
SymbolTable::~SymbolTable()
{
	delete[] offsetString;
}

//�ַ�����ӽ��ַ��������������ӳ�䣬���ص�ǰ���ַ���id
int SymbolTable::ForceAdd(const char *str, int len)
{
	if(curId==maxId || !stringBuffer.IsFit(len))
		return IDNOTFOUND;
	//ָ���ַ�������ĵط�
	offsetString[curId]=stringBuffer.GetCurrentOffset();
	stringBuffer.Add(str);
	//����ϣ�����ӳ��
	hashTable.Add(str,curId);
	curId++;
	return curId-1;

}

//���ַ���Ѱ��id
int SymbolTable::Find(const char *str) const
{
	//�ӹ�ϣ�����ַ���id���ڵĶ��б�
	const List& list=hashTable.Find(str);
	//�ڴ��б���Ѱ��id
	for(const Link* pLink=list.GetHead();
		pLink;
		pLink=pLink->Next())
	{
		int id=pLink->Id();
		int offStr=offsetString[id];
		//����ͬ������
		if(stringBuffer.IsEqual(offStr,str))
			return id;
	}
	return IDNOTFOUND;
}

//ͨ��idѰ�һ������е��ַ���
const char* SymbolTable::GetString(int id) const
{
	assert(id>=0);
	assert(id<curId);
	int offStr=offsetString[id];
	return stringBuffer.GetString(offStr);
}