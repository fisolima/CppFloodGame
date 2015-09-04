#pragma once
#include "BasicCell.h"

namespace Pippo
{

	template <typename T>
	class SimpleCell : public BasicCell<T>
	{
	public:
		SimpleCell(T _t) : BasicCell(_t)
		{}
		virtual ~SimpleCell()
		{}

		virtual int setValue(T _t)
		{
			if (this->t == _t) return 0;

			T currValue = this->t;

			this->t = _t;

			int count = 1;

			count += copyNeighbourValue(rightCell, currValue);
			count += copyNeighbourValue(bottomCell, currValue);
			count += copyNeighbourValue(leftCell, currValue);
			count += copyNeighbourValue(topCell, currValue);

			return count;
		}

		virtual T getValue()
		{
			return this->t;
		}
	};

}