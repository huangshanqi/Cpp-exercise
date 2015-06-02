//�ڵ���Node�Լ��Ӵ��Ķ���
#ifndef TREE_H_
#define TREE_H_
#include <assert.h>
#ifndef FUNCTIONTABLE_H_
#include "FunctionTable.h"
#endif

//����node������
class Node
{
public:
	virtual ~Node(){}
	//�жϽڵ��Ƿ�Ϊ��ֵ
	virtual bool  IsLeftValue() const {return false;}
	//ʵ�ּӷ���
	virtual void Assign(double value){}
	virtual double Calc() const=0;
};

//Node���������NumNode����ʾһ����
class NumNode:public Node
{
public:
	NumNode(double n):num(n){}
	double Calc() const{return num;}
private:
	const double num;
};

//Node��������BinNode����ʾһ����Ԫ�����
class BinNode:public Node
{
public:
	BinNode(Node* pleft, Node* pright)
		:left(pleft),right(pright){}
	~BinNode();
protected:
	//������������������Ҳ�����
	Node* left;
	Node* right;

};

//Node���������UniNode�࣬��ʾ��Ŀ���ߺ�������
class UniNode:public Node
{
public:
	UniNode(Node* n):node(n){}
	~UniNode(){delete node;}
protected:
	Node* node;
};

//Node��������VarNode���������������
//ǰ������
class Store;
class VarNode: public Node
{
public:
	//���캯��
	VarNode(int ID, Store& _store):id(ID),store(_store){}
	//��д���㺯��
	double Calc() const;
	//�жϱ����ǹ�Ϊ��ֵ
	bool IsLeftValue() const;
	//��д������
	void Assign(double value);
private:
	//��ʶ���ڷ��ű��е�id
	const int id;
	//�洢�ķ��ű�
	Store& store;

};

//BinNode������AddNode,��ʾ�������������
class AddNode:public BinNode
{
public:
	AddNode(Node* pLeft,Node* pRight):BinNode(pLeft,pRight){}
	double Calc() const;
};

//BinNode������SubNode����ʾ�����������
class SubNode:public BinNode
{
public:
	SubNode(Node* pLeft,Node* pRight):BinNode(pLeft,pRight){}
	double Calc() const;
};

//BinNode������MultNode�࣬��ʾ�����������
class MultNode:public BinNode
{
public:
	MultNode(Node* pLeft,Node* pRight):BinNode(pLeft,pRight){}
	double Calc() const;
};

//BinNode������DivideNode�࣬��ʾ�����������
class DivideNode:public BinNode
{
public:
	DivideNode(Node* pLeft,Node* pRight):BinNode(pLeft,pRight){}
	double Calc() const;
};

//BinNode������AssignNode�࣬��ʾ��ֵ����
class AssignNode:public BinNode
{
public:
	AssignNode(Node* pLeft,Node* pRight):BinNode(pLeft,pRight)
	{assert(left->IsLeftValue());}	//ȷ����ֵ��������Ϊ��ֵ
	double Calc() const;
};

//UniNode��������FunNode����ʾ��������
class FunNode:public UniNode
{
public:
	FunNode(PtrFun _pFun, Node* _pNode)
		:UniNode(_pNode),pFun(_pFun),pNode(_pNode){}
	double Calc() const;
private:
	//����ָ��
	PtrFun pFun;
	Node* pNode;

};

//UniNode������UMinusNode,��ʾȡ��ֵ
class UMinusNode:public UniNode
{
public:
	UMinusNode(Node* _pNode):UniNode(_pNode),pNode(_pNode){}
	double Calc() const;
private:
	Node* pNode;
};
#endif