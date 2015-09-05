#pragma once

#include "BasicCell.h"

namespace Pippo
{
	class ICellMatrixBuilder
	{
	protected:
		int width;
		int height;
		ICell *matrix;
		virtual void BuildMatrix() = 0;

	public:
		ICellMatrixBuilder( int _width, int _height )
		{
			this->width = _width;
			this->height = _height;
			this->matrix = nullptr;
		}
		virtual ~ICellMatrixBuilder() {}

		virtual ICell *getInstance() = 0;

		int getWidth()
		{
			return this->width;
		}

		int getHeight()
		{
			return this->height;
		}
	};

}