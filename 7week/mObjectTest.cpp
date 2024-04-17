#include "mObjectTest.h"
#include <iostream>
using namespace std;

mObjectTest::mObjectTest()
{
	cout << "생성" << endl;
}

mObjectTest::~mObjectTest()
{
	cout << "소멸" << endl;
}

void mObjectTest::print()
{
	cout << "화난다" << endl;
}