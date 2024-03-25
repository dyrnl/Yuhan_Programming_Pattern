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

void drawBlock()
{
    std::cout << "��Ϻ�Ϻ��\n��Ϻ�Ϻ��\n��Ϻ�Ϻ��" << std::endl;
    std::cout << "\x1b[" << ForeColor::Default << "m";
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

    const int White_Mask = 0b1;
    const int Red_Mask = 0b10;
    const int Green_Mask = 0b100;
    const int Yellow_Mask = 0b1000;
    const int Cyan_Mask = 0b10000;
    const int Magenta_Mask = 0b100000;
    const int Exit_CMD = 0b1000000;

    std::cout << "ȭ�鿡 �׸��� �׸��� ���α׷��Դϴ�." << std::endl;
    std::cout << "�й� : 202327021" << std::endl;
    std::cout << "�̸� : �ۿ���" << std::endl;
    
    int InputNum = 0;

    while (true)
    {
        std::cout << "ȭ�鿡 �׸� ��ü�ڵ带 �Է����ּ��� : ";
        std::cin >> InputNum;

        if (InputNum & White_Mask)
        {
            std::cout << "\x1b[" << ForeColor::White << "m";
            drawBlock();
        }
        if (InputNum & Red_Mask)
        {
            std::cout << "\x1b[" << ForeColor::Red << "m";
            drawBlock();
        }
        if (InputNum & Green_Mask)
        {
            std::cout << "\x1b[" << ForeColor::Green << "m";
            drawBlock();
        }
        if (InputNum & Yellow_Mask)
        {
            std::cout << "\x1b[" << ForeColor::Yellow << "m";
            drawBlock();
        }
        if (InputNum & Cyan_Mask)
        {
            std::cout << "\x1b[" << ForeColor::Cyan << "m";
            drawBlock();
        }
        if (InputNum & Magenta_Mask)
        {
            std::cout << "\x1b[" << ForeColor::Magenta << "m";
            drawBlock();
        }
        if (InputNum == Exit_CMD)
        {
            std::cout << "���α׷� ����." << std::endl;
            break;
        }
        if (InputNum > 64 || InputNum < 0)
        {
            std::cout << "�߸��� ���Դϴ�. �ٽ� �Է����ּ���." << std::endl;
            continue;
        }
    }
        return 0;
}