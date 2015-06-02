//�����������ַ��������ʵ���ļ�
#include "StringTable.h"
#ifndef _IOSTREAM_
#include<iostream>
#endif
#include<assert.h>

//��������StringBuffer��ʵ��
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

//�ַ�������StringTable��ʵ��
//���ַ���������������ַ���������ӳ��
int StringTable::ForceAdd(const char* str)
{
	//�жϻ������ռ��ǹ��㹻�����ַ���
	int len=std::strlen(str);
	if(curId==MAXSTRINGS || !stringBuffer.IsFit(len))
	{
		return NOTFOUND;
	}

	//�ռ��㹻���ȱ���ƫ�������ٱ����ַ���
	offsetString[curId]=stringBuffer.GetCurrentOffset();
	stringBuffer.Add(str);
	//���ӳ��
	hashTable.Add(str,curId);
	curId++;
	return curId-1;
}

//�ڻ�������Ѱ���ַ���
int StringTable::Find(const char *str) const
{
	//��ù�ϣ���и��ַ����Ķ��б�
	const List& list=hashTable.Find(str);
	//���������ڴ��������ҵ��ַ����������ڻ������е�id
	for(const Link* pLink=list.GetHead();
		pLink;
		pLink=pLink->Next())
	{
		//��û������е�id
		int id=pLink->Id();
		//��ö�Ӧ��ƫ����
		int offStr=offsetString[id];
		//ʹ�û������еıȽϺ������бȽϣ����ҵ�������id
		if(stringBuffer.IsEqual(offStr,str))
			return id;
		
	}
	//�б�Ϊ�գ����Ҳ���������δ�ҵ�
	return NOTFOUND;
}

const char* StringTable::GetString(int id) const
{
	//���id���ڷ�Χ�ڣ����쳣
	assert(id>=0);
	assert(id<curId);
	//���ƫ����
	int offStr=offsetString[id];
	return stringBuffer.GetString(offStr);
}