#include "IntegerCell.h"

using namespace Pippo;

IntegerCell::IntegerCell(int _value) : SimpleCell(_value)
{
}


IntegerCell::~IntegerCell()
{
}


int IntegerCell::setValue(int _value)
{
	return SimpleCell<int>::setValue(_value);
}