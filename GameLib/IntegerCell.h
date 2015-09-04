#pragma once
#include "SimpleCell.h"
#include <string>
using namespace Pippo;

class IntegerCell :	public SimpleCell<int>
{
private:
	

public:
	IntegerCell(int _value);
	~IntegerCell();

	int setValue(int _value);

	std::string log;
};

