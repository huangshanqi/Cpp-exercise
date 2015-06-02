//ʵ��ɨ����Parser��
#include "Parser.h"
#include "Scanner.h"
#include "SymbolTable.h"
#include "Store.h"
#include "Tree.h"
#include "FunctionTable.h"

//���캯��
Parser::Parser(Scanner &_scanner,
			   Store &_store,
			   FunctionTable &_funTab,
			   SymbolTable &_symTab)
		:scanner(_scanner),
		tree(0),
		status(stOk),
		functionTable(_funTab),
		store(_store),
		symbolTable(_symTab)
{

}

//��������
Parser::~Parser()
{
	//�ݹ�ɾ��
	delete tree;
}

//�������벢����
Status Parser::Eval()
{
	//��������
	Parse();
	//�����ɹ���ִ�У������˳�
	if(status==stOk)
		Execute();
	else
		status=stQuit;
	return status;

}

//ִ�м���
void Parser::Execute()
{
	if(tree)
		double result=tree->Calc();
	
}

//���г�ʼ����
void Parser::Parse()
{
	tree=Expr();
}

//�������ʽ������Ӽ��븳ֵ
Node* Parser::Expr()
{
	Node* pNode=Term();
	Token token=scanner.GetToken();
	if(token==Plus)
	{
		scanner.Accept();
		Node* pRight=Expr();
		pNode=new AddNode(pNode,pRight);
	}
	else if(token==Minus)
	{
		scanner.Accept();
		Node* pRight=Expr();
		pNode=new SubNode(pNode,pRight);
	}
	else if(token==Assign)
	{
		scanner.Accept();
		Node* pRight=Expr();
		if(pNode->IsLeftValue())
		{
			pNode=new AssignNode(pNode,pRight);
		}
		else
		{
			status=stError;
			delete pNode;
			pNode=Expr();
		}
	}
	return pNode;
}

//��������
Node* Parser::Term()
{
	Node* pNode=Factor();
	if(scanner.GetToken()==Mult)
	{
		scanner.Accept();
		Node* pRight=Term();
		pNode=new MultNode(pNode,pRight);
	}
	else if(scanner.GetToken()==Divide)
	{
		scanner.Accept();
		Node* pRight=Term();
		pNode=new DivideNode(pNode,pRight);
	}
	return pNode;
}

//��������
Node* Parser::Factor()
{
	Node* pNode;
	Token token=scanner.GetToken();

	if(token==LParen)
	{
		//����������
		scanner.Accept();
		pNode=Expr();
		if(scanner.GetToken()!=RParen)
			status=stError;
		else
			scanner.Accept();
	}
	else if(token==Number)
	{
		pNode=new NumNode(scanner.GetNumber());
		scanner.Accept();
	}
	else if(token==Ident)
	{
		char strSymbol[MAXSYMBOLLEN];
		int lenSym=MAXSYMBOLLEN;
		//�ѷ��Ÿ��Ƶ�strSymbol��
		scanner.GetSymbolName(strSymbol,lenSym);
		int id=symbolTable.Find(strSymbol);
		scanner.Accept();
		if(scanner.GetToken()==LParen)
		{
			scanner.Accept();//����������
			pNode=Expr();
			if(scanner.GetToken()==RParen)
				scanner.Accept();	//����������
			else
				status=stError;
			if(id!=IDNOTFOUND && id<functionTable.GetSize())
			{
				pNode=new FunNode(functionTable.GetFunction(id),pNode);
			}
			else
			{
				std::cout<<"Unknown function\"";
				std::cout<<strSymbol<<"\"\n";
			}
		}
		else
		{
			if(id==IDNOTFOUND)
				id=symbolTable.ForceAdd(strSymbol,lenSym);
			pNode=new VarNode(id,store);

		}
	}
	else if(token==Minus)
	{
		scanner.Accept();	//���ܼ�
		pNode=new UMinusNode(Factor());
	}
	else
	{
		scanner.Accept();
		status=stError;
		pNode=0;
	}
	return pNode;
}