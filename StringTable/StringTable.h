//�����ַ������������ַ�����
#ifndef STRINGTABLE_H_
#define STRINGTABLE_H_
#include "HashTable.h"  

//�����ַ�����������ʵ����һ���ַ�������
//���������������յ��ַ���
const int MAXBUFSIZE=500;
class StringBuffer
{
public:
	//���캯������ʼ��ƫ����Ϊ0
	StringBuffer():curOffset(0){}
	//��������
	~StringBuffer(){}
	//�жϽ�Ҫ������ַ�����û���㹻�Ŀռ����
	bool IsFit(int len) const
	{
		return (curOffset+len+1)<MAXBUFSIZE;
	}
	//�򻺳����м����ַ���
	void Add(const char* str);
	//��õ�ǰ��ƫ����
	int GetCurrentOffset() const {return curOffset;}
	//�жϸ������ַ����뻺������ָ���ַ����Ƿ���ͬ
	//ʹ��offsetStringָ���������е��ַ���
	bool IsEqual(int offseString, const char* str) const;
	//��û�������ָ��λ�õ��ַ���
	const char*  GetString(int offsetString) const
	{return &buffer[offsetString];}
private:
	//�����ַ���������
	char buffer[MAXBUFSIZE];
	//����ƫ����
	int curOffset;

};

//�����ַ�����StringTable��
//�ַ�������๦���ǽ����ַ���������֮����໥ӳ���ϵ
//����δ�ҵ���ֵ
const int NOTFOUND=-1;
//�����ַ����������
const int MAXSTRINGS=100;

class StringTable
{
public:
	//���캯������������
	StringTable():curId(0){}
	~StringTable(){}
	//���ַ���������������ַ���������ӳ��
	int ForceAdd(const char* str);
	//Ѱ���������ַ����ڻ������е�λ��
	int Find(const char* str) const;
	//ͨ��λ��id��û������е��ַ���
	const char* GetString(int id) const;
private:
	//�ַ���->������ʵ����
	HashTable hashTable;
	//ÿ���ַ�����ƫ��������
	int offsetString[MAXSTRINGS];
	//��ǰ���ַ���idֵ
	int curId;
	//�ַ���������
	StringBuffer stringBuffer;

};

#endif