//C++ʵ��֮·1.4��
//Ladder�����
/*Ч�����£�������Frame�Լ�һ��VerBar��ɵģ�
��ˮƽ��ȣ�-����������Ϊ-����ֱ�߶ȣ�|����������Ϊ(5,2)ʱ����ʾ���£�
+-----+
  |

  |
+-----+
  |

  |
+-----+
  |

  |
+-----+
*/

#include<iostream>

//����ˮƽ��HorBar�� 
class HorBar
{
private:
	//ˮƽ���
	int horizonWidth;
public:
	//���캯��
	HorBar(){}
	HorBar(int hWid)
	{
		//����������С���㣬��ʾ
		if(hWid<0)
		{
			std::cout<<"�����ˮƽ����С���㣡"<<std::endl;
			return;
		}
		//����Ҫ��ģ���ֵ����ʾ
		else
		{
			horizonWidth=hWid;
		
		}
	}
	//HorBar��������
	~HorBar(){}
	//��ʾˮƽ��
	void displayHorizon()
	{
		if(horizonWidth<0)
			std::cout<<"�����ˮƽ��С���㣬�޷���ʾ"<<std::endl;
		else
		{
			std::cout<<"+";
			for(int i=0;i<horizonWidth;i++)
				std::cout<<"-";
			std::cout<<"+"<<std::endl;
		}
	}
};

//���崹ֱ��VerBar��
class VerBar
{
private:
	//��ֱ���
	int verticalWidth;
public:
	//��ֱ���Ĺ��캯��
	VerBar(){}

	VerBar(int vWid)
	{
		//��������ֵС���㣬��ʾ
		if(vWid<0)
		{
			std::cout<<"����Ĵ�ֱ���С���㣡"<<std::endl;
			return;
		}
		else
		//���������ģ���ֵ����ʾ
		{
			verticalWidth=vWid;
		}

	}
	//VerBar��������
	~VerBar(){}
	//��ʾ��ֱ��
	void displayVertical()
	{
		if(verticalWidth<0)
			std::cout<<"����Ĵ�ֱ��С���㣬�޷���ʾ"<<std::endl;
		else
		{
			for(int i=0;i<verticalWidth;i++)
				std::cout<<"|"<<std::endl;
		}
	}

};

//��������
//�����������ˮƽ���͵��е�һ����ֱ�����
class Frame:public HorBar,public VerBar
{
private:
	//����ϲ�ˮƽ��
	HorBar upperHorBar;
	//����д�ֱ��
	VerBar middleVerBar;
	//�����ˮƽ��
	HorBar lowerHorBar;

public:
	//�������๹�캯��
	Frame(){}
	Frame(int hWid,int vWid):
	  upperHorBar(hWid),
	  middleVerBar(vWid),
	  lowerHorBar(hWid){}
	
	//����������������
	~Frame(){}
	//��ʾ���
	void displayFrame()
	{
		upperHorBar.displayHorizon();
		middleVerBar.displayVertical();
		lowerHorBar.displayHorizon();
	}
};

//���������
class Ladder:public Frame
{
private:
	//�����ϲ����
	Frame upperFrame;
	//�����в��Ĵ�ֱ��
	VerBar middleVerBar;
	//�����²��Ŀ��
	Frame lowerFrame;

public:
	//��������๹�캯��
	Ladder(){}
	Ladder(int hWid,int vWid):
	  upperFrame(hWid,vWid),
	  middleVerBar(vWid),
	  lowerFrame(hWid,vWid){}
  //�����������������
	  ~Ladder(){}
	  //��ʾ����
	  void displayLadder()
	  {
		  upperFrame.displayFrame();
		  middleVerBar.displayVertical();
		  lowerFrame.displayFrame();
	  }

};

//main��������
int main(int argc,char* argv)
{
	//�������ݶ���
	Ladder ladder(-5,-2);
	//��ʾ����
	ladder.displayLadder();
	return 0;
}
