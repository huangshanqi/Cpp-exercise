//�洢��ʶ��ֵ����Store.h��ʵ��
#include "SymbolTable.h"
#include "Store.h"
#include <cmath>

//���캯���Ķ���
Store::Store(int s, SymbolTable &symbolTable):size(s)
{
	//�����洢�ռ䲢��ʼ��
	cell=new double[size];
	status=new unsigned char[size];
	for (int i=0; i<size; i++)
		status[i]=NotInit;
	//���Ԥ�������
	//�����Ȼ����e
	int id=symbolTable.ForceAdd("e",1);
	SetValue(id,std::exp(1.0));
	//���Բ����pi
	id=symbolTable.ForceAdd("pi",2);
	SetValue(id,2*std::acos(0.0));

}

//��������
Store::~Store()
{
	delete[] cell;
	delete[] status;
}
