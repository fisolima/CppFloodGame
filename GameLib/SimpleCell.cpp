#include "SimpleCell.h"

using namespace Pippo;

//template <typename T>
//SimpleCell<T>::SimpleCell(T _t) : BasicCell(_t)
//{
//}
//
//template <typename T>
//SimpleCell<T>::~SimpleCell()
//{
//}

template <typename T>
void SimpleCell<T>::setValue(T _t)
{
	this->t = _t;
}

template<typename T>
T SimpleCell<T>::getValue()
{
	return this->t;
}
