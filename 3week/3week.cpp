#include <iostream>



int main()
{
	int num;
	std::cout << "전 제가 좋습니다";
	std::cin >> num;
	std::cout << "근데 송재원은" << num << "번 죽여도 분이 안 풀릴 것 같다";

	int num = 0;
	std::string name;
	while (num != 9999)
	{
		std::cout << "게임 실행" << std::endl;
		std::cout << "내가 싫어하는 숫자를 써봐 : ";
		std::cin >> num >> name;
		std::cout << "재원아 왜 그러니..?" << std::endl;
	}
	std::cout << "그럼 " << num << "대 맞자" << std::endl;

	return 0;
}