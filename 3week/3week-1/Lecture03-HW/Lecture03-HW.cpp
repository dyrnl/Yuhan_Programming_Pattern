#include <iostream>

enum ForeColor 
{
    Default = 0,
    Black = 30,
    Red = 31,
    Green = 32,
    Yellow = 33,
    Blue = 34,
    Magenta = 35,
    Cyan = 36,
    White = 37,
};

void drawBlock(int colorCode)
{
    std::cout << "\x1b[" << colorCode << "m";
    std::cout << "��Ϻ�Ϻ��\n��Ϻ�Ϻ��\n��Ϻ�Ϻ��" << std::endl;
    std::cout << "\x1b[" << ForeColor::White << "m";
}
int main()
{
    /*
    * ��� ����� �׸��� Ű�ڵ� : 1 (1)
    * ������ ����� �׸��� Ű�ڵ� : 2 (10)
    * ��� ����� �׸��� Ű�ڵ� : 4 (100)
    * ����� ����� �׸��� Ű�ڵ� : 8 (1000)
    * û�ϻ� ����� �׸��� Ű�ڵ� : 16 (10000)
    * ����Ÿ�� ����� �׸��� Ű�ڵ� : 32 (100000)
    * ���α׷� ���� : 64 (1000000)
    *
    * ���α׷��� �����ϸ� �Ʒ��� ���� ���ÿ�
    *
    *
    * ȭ�鿡 �׸��� �׸��� ���α׷��Դϴ�.
    * �й� : 349218347(�����й�)
    * �̸� : �����̸�
    *
    * ȭ�鿡 �׸� ��ü�ڵ带 �Է��ϼ��� :
    * (�ݺ�)
    */

    std::cout << "ȭ�鿡 �׸��� �׸��� ���α׷��Դϴ�." << std::endl;
    std::cout << "�й� : 202327021" << std::endl;
    std::cout << "�̸� : �ۿ���" << std::endl;
    
    int InputNum = 0;

    while (true)
    {
        std::cout << "ȭ�鿡 �׸� ��ü�ڵ带 �Է����ּ��� : ";
        std::cin >> InputNum;

        if (InputNum == 1)
        {
            drawBlock(ForeColor::White);
        }
        else if (InputNum == 2)
        {
            drawBlock(ForeColor::Red);
        }
        else if (InputNum == 4)
        {
            drawBlock(ForeColor::Green);
        }
        else if (InputNum == 8)
        {
            drawBlock(ForeColor::Yellow);
        }
        else if (InputNum == 16)
        {
            drawBlock(ForeColor::Cyan);
        }
        else if (InputNum == 32)
        {
            drawBlock(ForeColor::Magenta);
        }
        else if (InputNum == 64)
        {
            std::cout << "���α׷� ����." << std::endl;
            break;
        }
        else
        {
            std::cout << "�߸��� ���Դϴ�. �ٽ� �Է����ּ���." << std::endl;
        }
    }
        return 0;
}