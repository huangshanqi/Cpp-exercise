//Node�༰�������ʵ���ļ�
#include "Tree.h"
#ifndef STROE_H_
#include "Store.h"
#endif
#ifndef _IOSTREAM_
#include <iostream>
#endif
#include <assert.h>

//ʵ��BinNode��
BinNode::~BinNode()
{
	delete left;
	delete right;
}

//ʵ��VarNode��
//�õ���ʶ����ֵ
double VarNode::Calc() const
{
	double x=0;
	if(store.IsInit(id))
		x=store.GetValue(id);
	else
		std::cout<<"Use uninitialized variable"<<std::endl;
	return x;

}

//���
void VarNode::Assign(double value)
{
	store.SetValue(id,value);
}

//��ʶ��Ϊ��ֵ
bool VarNode::IsLeftValue() const
{
	return true;
}

//ʵ��AddNode�������
double AddNode::Calc() const
{
	return left->Calc()+right->Calc();
}

//ʵ��SubNode�������
double SubNode::Calc() const
{
	return left->Calc()-right->Calc();
}

//ʵ��MultNode�������
double MultNode::Calc() const
{
	return left->Calc()*right->Calc();
}

//ʵ��DivideNode�������
double DivideNode::Calc() const
{
	return left->Calc()/right->Calc();
}

//ʵ��AssignNode�ำֵ����
double AssignNode::Calc() const
{
	double x=right->Calc();
	left->Assign(x);
	return x;
}

//ʵ��FunNode�ຯ������
double FunNode::Calc() const
{
	//ȷ������ָ��ǿ�
	assert(pFun!=0);
	return (*pFun)(pNode->Calc());
}

//ʵ��UMinusNode���ȡ��ֵ����
double UMinusNode::Calc() const
{
	return -pNode->Calc();
}