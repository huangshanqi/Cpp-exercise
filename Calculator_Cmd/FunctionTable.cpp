//����ָ���FunctionTable���ʵ��
#ifndef SYMBOLTABLE_H_
#include "SymbolTable.h"
#endif
#include "FunctionTable.h"
#include <assert.h>

//���캯��
FunctionTable::FunctionTable(SymbolTable &symTab,
							 FunctionEntry funArr[])
							 :size(0)
{
	for(int i=0; i<MAXIDFUN; i++)
	{
		int len=std::strlen(funArr[i].strFun);
		//���û�к����ˣ����˳�
		if(len)
			break;
		function[i]=funArr[i].pFun;
		//ȷ�����ű�������������������
		int j=symTab.ForceAdd(funArr[i].strFun,len);
		assert(i==j);
		size++;
	}

}