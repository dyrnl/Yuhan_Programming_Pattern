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
    std::cout << "블록블록블록\n블록블록블록\n블록블록블록" << std::endl;
    std::cout << "\x1b[" << ForeColor::White << "m";
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

    std::cout << "화면에 그림을 그리는 프로그램입니다." << std::endl;
    std::cout << "학번 : 202327021" << std::endl;
    std::cout << "이름 : 송영진" << std::endl;
    
    int InputNum = 0;

    while (true)
    {
        std::cout << "화면에 그릴 물체코드를 입력해주세요 : ";
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
            std::cout << "프로그램 종료." << std::endl;
            break;
        }
        else
        {
            std::cout << "잘못된 값입니다. 다시 입력해주세요." << std::endl;
        }
    }
        return 0;
}