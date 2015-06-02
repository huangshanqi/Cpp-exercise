//�洢��ʶ������ֵ�ķ��ű���Store.h
#ifndef STORE_H_
#define STORE_H_
#include <assert.h>
//�洢��ʶ��������ű���Store.h�Ķ���
class SymbolTable;	//ǰ������
//���嵥Ԫ������״̬
enum {
	NotInit,	//��ʶ��δ����ʼ��
	Init};		//��ʶ���ѱ���ʼ��
class Store
{
public:
	//��������������
	Store(int size, SymbolTable& symbolTable);
	~Store();
	//�ж�id�Ƿ񱻳�ʼ��
	bool IsInit(int id) const{return (id<size&&status[id]==Init);}
	//���ĳid��ֵ
	double GetValue(int id) const{assert(IsInit(id));return cell[id];}
	//����id��Ӧ��ֵ
	void SetValue(int id, double val)
	{
		if(id<size)
		{
			cell[id]=val;
			status[id]=Init;
		}
	}
private:
	//��ʶ��ֵ�����洢����
	int size;
	//�洢��ʶ��ֵ������ָ��
	double* cell;
	//��ʶ���Ƿ��ʼ����״̬
	unsigned char* status;

};
#endif