#pragma once

#include "BasicCell.h"

namespace Pippo
{

class PippoTestClass : public BasicCell<int>
{
public:
	PippoTestClass();
	virtual ~PippoTestClass();

	virtual int Square(int value);

	virtual int setValue(int _value);
	virtual int getValue();
};

}