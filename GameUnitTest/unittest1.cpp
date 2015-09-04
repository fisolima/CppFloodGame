#include "stdafx.h"
#include "CppUnitTest.h"
#include "SimpleCell.h"
#include "IntegerCell.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace GameUnitTest
{		
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(Cell_value_assign)
		{
			Pippo::SimpleCell<int> cell(0);

			cell.setValue(10);

			Assert::AreEqual(10, cell.getValue());
		}

		TEST_METHOD(Cell_value_assign_counter_different_value)
		{
			Pippo::SimpleCell<int> cell(0);

			int count = cell.setValue(10);

			Assert::AreEqual(1, count);
		}

		TEST_METHOD(Cell_value_assign_same_value)
		{
			Pippo::SimpleCell<int> cell(10);

			int count = cell.setValue(10);

			Assert::AreEqual(0, count);
		}

		TEST_METHOD(Cell_chain_value_assign)
		{
			Pippo::SimpleCell<int> cells[5] { 0, 0, 0, 0, 0 };

			cells[0].setRightCell(&cells[1]);
			cells[0].setLeftCell(&cells[2]);
			cells[0].setBottomCell(&cells[3]);
			cells[0].setTopCell(&cells[4]);

			int count = cells[0].setValue(10);

			Assert::AreEqual(10, cells[0].getValue());
			Assert::AreEqual(10, cells[1].getValue());
			Assert::AreEqual(10, cells[2].getValue());
			Assert::AreEqual(10, cells[3].getValue());
			Assert::AreEqual(10, cells[4].getValue());

			Assert::AreEqual(5, count);
		}

		TEST_METHOD(Cell_chain_with_different_values_assign)
		{
			Pippo::SimpleCell<int> cells[5] { 0, 1, 2, 3, 4 };

			cells[0].setRightCell(&cells[1]);
			cells[0].setLeftCell(&cells[2]);
			cells[0].setBottomCell(&cells[3]);
			cells[0].setTopCell(&cells[4]);

			int count = cells[0].setValue(10);

			Assert::AreEqual(10, cells[0].getValue());
			Assert::AreEqual(1, cells[1].getValue());
			Assert::AreEqual(2, cells[2].getValue());
			Assert::AreEqual(3, cells[3].getValue());
			Assert::AreEqual(4, cells[4].getValue());

			Assert::AreEqual(1, count);
		}

		TEST_METHOD(Neighbour_cell_after_assign)
		{
			Pippo::SimpleCell<int> cells[5] { 0, 1, 2, 3, 4 };

			cells[0].setRightCell(&cells[1]);
			cells[0].setLeftCell(&cells[2]);
			cells[0].setBottomCell(&cells[3]);
			cells[0].setTopCell(&cells[4]);

			Assert::AreEqual((void*)&cells[0], (void*)cells[1].LeftCell());
			Assert::AreEqual((void*)&cells[0], (void*)cells[2].RightCell());
			Assert::AreEqual((void*)&cells[0], (void*)cells[3].TopCell());
			Assert::AreEqual((void*)&cells[0], (void*)cells[4].BottomCell() );
			Assert::AreNotEqual((void*)&cells[4], (void*)cells[3].BottomCell());
		}

		TEST_METHOD(IntegerCell_base_setValue_call)
		{
			IntegerCell cell(0);

			cell.setValue(10);

			Assert::AreEqual(10, cell.getValue());
			
			Assert::AreEqual("setValue", cell.log.c_str());
		}
	};
}