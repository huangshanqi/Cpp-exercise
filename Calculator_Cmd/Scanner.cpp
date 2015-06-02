//ɨ����Scanner���ʵ���ļ�
#include "Scanner.h"
#ifndef _IOSTREAM_
#include <iostream>
#include <ctype.h>
#endif
#include<assert.h>

//Scanner���캯��
Scanner::Scanner(char* buf):buffer(buf),look(0)
{
	Accept();
}
//������뻺�����еĿո�
void Scanner::EatWhite()
{
	for (int i=0;i<std::strlen(buffer);i++)
		if(isspace(buffer[i]))
			for(int j=i;j<strlen(buffer);j++)
				buffer[j]=buffer[j+1];
}

//ʶ���ַ����е��ַ�
void Scanner::Accept()
{
	//����������ַ����еĿո�
	EatWhite();
	//ʶ���ַ�������
	switch(buffer[look])
	{
	//ʶ����Ӻ�
	case '+':
		token=Plus;
		look++;
		break;
	//ʶ�������
	case '-':
		token=Minus;
		look++;
		break;
	//ʶ����˺�
	case '*':
		token=Mult;
		look++;
		break;
	//ʶ�������
	case '/':
		token=Divide;
		look++;
		break;
	//ʶ�������
	case '0':case '1':case '2':case '3':case '4':
	case '5':case '6':case '7':case '8':case '9':
	case '.':
	{
		token=Number;
		char *p;
		//����ַ����еĸ����������ĵ�һ��δʶ���ַ�����ָ��
		//ָ��p������strtod��ʼ��
		number=std::strtod(&buffer[look],&p);
		//���¸�������
		look=p-buffer;
		break;
	}
	//ʶ�����ʶ�����ߴ���
	default:
	//ʶ���Ƿ�Ϊ��ʶ������ʶ��������C++�涨�����ַ�����Ϊ��ĸ���»���
	//��ʶ��ֻ������ĸ�����»������,��󳤶�ΪMAXSYMBOLLEN
	//���ַ�����Ҫ��
	if(isalpha(buffer[look]) || buffer[look]=='_')
	{
		token=Ident;
		//��¼λ������
		symbolIndex=look;
		//��ȡ����ʶ��
		int slook;
		do 
		{
			look++;
			//��¼��ʶ���е��ַ��������ж��Ƿ����
			slook=buffer[look];
		}while(isalnum(slook) || slook=='_');
		//�����ʶ���ĳ���
		symbolLength=look-symbolIndex;
		if(symbolLength>=MAXSYMBOLLEN)
			symbolLength=MAXSYMBOLLEN-1;

	}
	//������Ǳ�ʶ������ô���Ǵ��������
	else
		token=Error;
	break;
	}
}
//��ý����õ��ı�ʶ�����䳤�ȣ�ͨ�������ָ������÷���
void Scanner::GetSymbolName(char* strOut, int& len)
{
	//ȷ��������len���ڱ�ʶ�����ȣ���֤�ռ��㹻
	assert(len>=MAXSYMBOLLEN);
	assert(symbolLength<=MAXSYMBOLLEN);
	//��ʶ���ĸ�ֵ
	std::strncpy(strOut,&buffer[symbolIndex],symbolLength);
	strOut[symbolLength]='\0';
	len=symbolLength;
}