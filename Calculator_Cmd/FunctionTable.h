//����ָ���FunctionTable��Ķ���
#ifndef FUNCTIONTABLE_H_
#define FUNCTIONTABLE_H_
#include <cmath>
//���ȶ��庯��ָ��ı���
typedef double (*PtrFun)(double);
//���庯��ָ���뺯������ϵ����
class FunctionEntry
{
public:
	//����ָ��
	PtrFun pFun;
	//������
	char* strFun;
};

//������д洢���������
const int MAXIDFUN=16;


//���庯����FunctionTable��

//ǰ������
class SymbolTable;
class FunctionTable
{
public:
	//��������������
	FunctionTable(SymbolTable& symTab, FunctionEntry funArr[]);
	~FunctionTable(){}
	//��ñ��к����ĸ���
	int GetSize() const {return size;}
	//ͨ��id��ú���ָ��
	PtrFun GetFunction(int id) const{return function[id];}
private:
	//����������
	int size;
	//����ָ���
	PtrFun function[MAXIDFUN];

};
#endif