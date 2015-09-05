#pragma once

#include "BasicCell.h"
#include "ICellMatrixBuilder.h"

namespace Pippo
{
	template <class  CellType>
	class BasicCellMatrixBuilder : public ICellMatrixBuilder
	{
	private:
		bool isMatrixBuilded;

		void BuildMatrix()
		{
			isMatrixBuilded = true;
		}

	public:
		BasicCellMatrixBuilder<CellType>(int _width, int _height) : ICellMatrixBuilder(_width, _height)
		{
			matrix = new CellType[this->width * this->height];
			isMatrixBuilded = false;
		}
		~BasicCellMatrixBuilder()
		{
		}

		ICell* getInstance()
		{
			if (!isMatrixBuilded) BuildMatrix();

			return this->matrix;
		}
	};
}