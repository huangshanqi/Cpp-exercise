//��ʶ����������ϰ
#include<iostream>

//����World��
class World
{
private:
	const int _identifier;
public:
	//���캯��
	World(int id):_identifier(id)
	{
		std::cout<<"Hello from "<<_identifier<<std::endl;
	}

	void display()
	{
		std::cout<<"����"<<std::endl;
	}

	//��������
	~World()
	{
		std::cout<<"Goodbye from "<<_identifier<<std::endl;
	}
};

int main()
{
	World smallWorld(2);

	for (int i = 3; i<6; i++)
	{
		World aWorld(i);
	}

	World oneMoreWorld(6);

	

	return 0;
}

//����ȫ�ֶ���
World TheWorld(1);
