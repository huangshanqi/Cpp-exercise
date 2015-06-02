//������ű�SymbolTable��
#ifndef SYMBOLTABLE_H_
#define SYMBOLTABLE_H_
#include "HashTable.h"

//�����ַ�����������ʵ����һ���ַ�������
class StringBuffer
{
public:
	//���幹�캯������ʼ��ƫ����Ϊ0
	StringBuffer(int s);
	//��������
	~StringBuffer();
	//�жϽ�Ҫ������ַ�����û���㹻�Ŀռ����
	bool IsFit(int len) const
	{
		return (curOffset+len+1)<size;
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
	//���建�����Ŀռ�
	int size;
	//�����ַ���������ָ��
	char *buffer;
	//����ƫ����
	int curOffset;

};

//������ű���
//�����ʾδ�ҵ�id�ĳ���ֵ
const int IDNOTFOUND=-1;
class SymbolTable
{
public:
	//��������������
	explicit SymbolTable(int size);
	~SymbolTable();
	//����Ԫ�ز�����ӳ��
	int ForceAdd(const char* str, int len);
	//Ѱ�Ҹ����ַ����ڻ������е�λ��
	int	Find(const char* str) const;
	//�ַ����ڻ������е�λ�ã������ַ���
	const char* GetString(int id) const;
private:
	//�����ϣ��
	HashTable hashTable;
	//�������д洢���ַ����������ֵ
	int maxId;
	//�洢�ַ���ƫ��ֵ������
	int *offsetString;
	//��ǰ�ַ���id
	int curId;
	//�ַ���������
	StringBuffer stringBuffer;
};
#endif