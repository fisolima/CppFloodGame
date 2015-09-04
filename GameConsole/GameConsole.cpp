// GameConsole.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "TestClass.h"
#include "IntegerCell.h"

int _tmain(int argc, _TCHAR* argv[])
{
	IntegerCell cell(0);

	cell.setValue(10);

	int value = cell.getValue();

	Pippo::PippoTestClass myClass;

	myClass.setValue(30);
	myClass.getValue();
	myClass.Square(25);

	return 0;
}

