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
    std::cout << "블록블록블록\n블록블록블록\n블록블록블록" << std::endl;
    std::cout << "\x1b[" << ForeColor::Default << "m";
}
int main()
{
    /*
    * 흰색 블록을 그리는 키코드 : 1 (1)
    * 빨강색 블록을 그리는 키코드 : 2 (10)
    * 녹색 블록을 그리는 키코드 : 4 (100)
    * 노란색 블록을 그리는 키코드 : 8 (1000)
    * 청록색 블록을 그리는 키코드 : 16 (10000)
    * 마젠타색 블록을 그리는 키코드 : 32 (100000)
    * 프로그램 종료 : 64 (1000000)
    *
    * 프로그램을 시작하면 아래와 같이 쓰시오
    *
    *
    * 화면에 그림을 그리는 프로그램입니다.
    * 학번 : 349218347(본인학번)
    * 이름 : 본인이름
    *
    * 화면에 그릴 물체코드를 입력하세요 :
    * (반복)
    */

    const int White_Mask = 0b1;
    const int Red_Mask = 0b10;
    const int Green_Mask = 0b100;
    const int Yellow_Mask = 0b1000;
    const int Cyan_Mask = 0b10000;
    const int Magenta_Mask = 0b100000;
    const int Exit_CMD = 0b1000000;

    std::cout << "화면에 그림을 그리는 프로그램입니다." << std::endl;
    std::cout << "학번 : 202327021" << std::endl;
    std::cout << "이름 : 송영진" << std::endl;
    
    int InputNum = 0;

    while (true)
    {
        std::cout << "화면에 그릴 물체코드를 입력해주세요 : ";
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
            std::cout << "프로그램 종료." << std::endl;
            break;
        }
        if (InputNum > 64 || InputNum < 0)
        {
            std::cout << "잘못된 값입니다. 다시 입력해주세요." << std::endl;
            continue;
        }
    }
        return 0;
}