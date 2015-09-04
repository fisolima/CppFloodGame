// GameConsole.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "TestClass.h"
#include "SimpleCell.h"

int _tmain(int argc, _TCHAR* argv[])
{
	Pippo::SimpleCell<int> cell(0);

	cell.setValue(10);

	Pippo::PippoTestClass myClass;

	myClass.Square(25);

	return 0;
}

