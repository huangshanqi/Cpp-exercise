//ɨ���������ļ�
#ifndef SCANNER_H_
#define SCANNER_H_
#include <assert.h>
//ʹ��ö�ٶ���Ǻ��б�
enum Token
{
	End,		//����
	Error,		//����
	Number,		//����
	Plus,		//�Ӻ�+
	Minus,		//����-
	Mult,		//�˺�*
	Divide,		//����/
	LParen,		//������
	RParen,		//������
	Assign,		//��ֵ�����=
	Ident		//��ʶ��

};

//�����ʶ������󳤶�
const int MAXSYMBOLLEN=8;

//����ɨ������
//ɨ����
class Scanner
{
public:
	//��������������
	Scanner(char *buf);
	~Scanner(){}
	//��õ�ǰ�ļǺ�
	Token GetToken(){return token;}
	//ʶ���ַ����е��ַ�
	void Accept();
	//���ʶ�𵽵�����
	double GetNumber()
	{
		//�Ǻ�Ϊ����ʱ�ŷ��أ��������쳣
		assert(token==Number);
		return number;
	}
	//��ý����õ��ı�ʶ�����䳤�ȣ�ͨ�������ָ������÷���
	void GetSymbolName(char* strOut, int& len);
private:
	//��Ҫ�����Ļ������ַ���
	char* buffer;
	//������뻺�����еĿո�
	void EatWhite();
	//��������
	int look;
	//�Ǻ�
	Token token;
	//�����õ�������ֵ
	double number;
	//��ʶ������
	int symbolLength;
	//��ʶ���ڻ������е�λ��
	int symbolIndex;
};

#endif