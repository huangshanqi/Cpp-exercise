//��������Parse.h�Ķ���
#ifndef PARSER_H_
#define PARSER_H_
//ǰ������
class Node;
class Scanner;
class Store;
class FunctionTable;
class SymbolTable;
//���������״̬��
enum Status
{
	stOk,	//��ȷ
	stQuit,	//�˳�
	stError	//����
};

class Parser
{
public:
	//��������������
	Parser(Scanner& _scanner,
			Store& _store,
			FunctionTable& _funTab,
			SymbolTable& _symTab);
	~Parser();
	//����
	Status Eval();
private:
	void Parse();
	Node* Expr();
	Node* Term();
	Node* Factor();
	void Execute();

	Scanner& scanner;
	Node* tree;
	Status status;
	Store& store;
	FunctionTable& functionTable;
	SymbolTable& symbolTable;
};
#endif