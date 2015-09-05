#pragma once

#include "BasicCell.h"
#include "ICellMatrixBuilder.h"
#include <typeinfo.h>
#include "SimpleCell.h"

namespace Pippo
{
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
				//if (matrix != nullptr) delete[] ()(matrix);
			} catch (...)
			{
			}
		}

		template <typename BasicCellType>
		BasicCellType *Cell(int _column, int _row)
		{
			return nullptr;
		}
	};

}