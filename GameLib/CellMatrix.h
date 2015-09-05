#pragma once

#include <exception>
#include "BasicCell.h"
#include "ICellMatrixBuilder.h"

namespace Pippo
{
	template <typename BasicCellType>
	class CellMatrix
	{
	private:		
		ICell *matrix;
		int width;
		int height;

	public:
		CellMatrix(ICellMatrixBuilder &_builder)
		{
			width = _builder.getWidth();
			height = _builder.getHeight();
			matrix = _builder.getInstance();
		}

		virtual ~CellMatrix()
		{
			try
			{
				if (matrix != nullptr) delete[](BasicCellType*) matrix;

				matrix = nullptr;
			} catch (...)
			{
			}
		}

		BasicCellType *Cell(int _column, int _row)
		{
			if (_column < 0 || _row < 0)
				throw std::exception("Coordinates out of range");

			if (_column >= this->width || _row >= this->height)
				throw std::exception("Coordinates out of range");

			return (BasicCellType*)&matrix[_row * this->width + _column];
		}
	};

}