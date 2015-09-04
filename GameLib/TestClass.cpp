#include "TestClass.h"

using namespace Pippo;

PippoTestClass::PippoTestClass() : BasicCell(0)
{
}

PippoTestClass::~PippoTestClass()
{
}

int PippoTestClass::Square(int value)
{
	return value * value;
}

int PippoTestClass::setValue(int _value)
{
	return 0;
}

int PippoTestClass::getValue()
{
	return 0;
}