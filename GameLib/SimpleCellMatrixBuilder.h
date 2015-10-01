#pragma once

#include "BasicCellMatrixBuilder.h"

namespace Pippo
{
	template<typename T>
	class SimpleCellMatrixBuilder : public BasicCellMatrixBuilder<SimpleCell<T>>
	{
	private:
	public:
		SimpleCellMatrixBuilder<T>(int _width, int _height, T _defaultValue) : BasicCellMatrixBuilder<SimpleCell<T>>(_width, _height)
		{
			for (int i = this->width*this->height - 1; i >= 0; --i)
			{
				((SimpleCell<T>*)(this->matrix) + i)->setValue(_defaultValue);
			}
		}

		~SimpleCellMatrixBuilder()
		{

		}
	};
}