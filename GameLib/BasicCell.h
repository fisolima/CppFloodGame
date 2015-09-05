#pragma once

namespace Pippo
{
	class ICell
	{
	public:
		ICell() {}
		~ICell() {}
	};

	template <typename T>
	class BasicCell : public ICell
	{
	protected:
		T t;

		BasicCell *rightCell;
		BasicCell *bottomCell;
		BasicCell *leftCell;
		BasicCell *topCell;

		int copyNeighbourValue(BasicCell* _cell, T _fromValue)
		{
			if (_cell == nullptr) return 0;

			if (_cell->t != _fromValue) return 0;

			return _cell->setValue(this->t);
		}

	public:
		BasicCell()
		{
			this->rightCell = nullptr;
			this->bottomCell = nullptr;
			this->leftCell = nullptr;
			this->topCell = nullptr;
		}
		BasicCell(T _t) : BasicCell()
		{
			this->t = _t;
		}
		~BasicCell()
		{

		}

		virtual int setValue(T _value) = 0;
		virtual T getValue() = 0;
		
		void setRightCell(BasicCell* _cell)
		{
			this->rightCell = _cell;
			_cell->leftCell = this;
		}

		BasicCell* RightCell()
		{
			return this->rightCell;
		}

		void setBottomCell(BasicCell* _cell)
		{
			this->bottomCell = _cell;
			_cell->topCell = this;
		}

		BasicCell* BottomCell()
		{
			return this->bottomCell;
		}

		void setLeftCell(BasicCell* _cell)
		{
			this->leftCell = _cell;
			_cell->rightCell = this;
		}

		BasicCell* LeftCell()
		{
			return this->leftCell;
		}

		void setTopCell(BasicCell* _cell)
		{
			this->topCell = _cell;
			_cell->bottomCell = this;
		}

		BasicCell* TopCell()
		{
			return this->topCell;
		}
	};

}
