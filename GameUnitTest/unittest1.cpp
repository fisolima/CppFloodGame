#include "stdafx.h"
#include <exception>
#include "CppUnitTest.h"
#include "SimpleCell.h"
#include "IntegerCell.h"
#include "CellMatrix.h"
#include "SimpleCellMatrixBuilder.h"

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

		TEST_METHOD(Cycling_cell_assign_value)
		{
			Pippo::SimpleCell<int> cells[8] {0, 0, 0, 0, 0, 0, 0, 0};

			cells[0].setRightCell(&cells[1]);
			cells[1].setRightCell(&cells[2]);
			cells[2].setBottomCell(&cells[3]);
			cells[3].setBottomCell(&cells[4]);
			cells[4].setLeftCell(&cells[5]);
			cells[5].setLeftCell(&cells[6]);
			cells[6].setTopCell(&cells[7]);
			cells[7].setTopCell(&cells[0]);

			int count = cells[0].setValue(10);

			Assert::AreEqual(8, count);
			Assert::AreEqual(10, cells[0].getValue());
			Assert::AreEqual(10, cells[7].getValue());
		}

		TEST_METHOD(Uform_cell_assign_value)
		{
			Pippo::SimpleCell<int> cells[8] {0, 0, 0, 0, 0, 0, 0, 0};

			//cells[0].setRightCell(&cells[1]);
			//cells[1].setRightCell(&cells[2]);
			cells[2].setBottomCell(&cells[3]);
			cells[3].setBottomCell(&cells[4]);
			cells[4].setLeftCell(&cells[5]);
			cells[5].setLeftCell(&cells[6]);
			cells[6].setTopCell(&cells[7]);
			cells[7].setTopCell(&cells[0]);

			int count = cells[0].setValue(10);

			Assert::AreEqual(7, count);
			Assert::AreEqual(10, cells[0].getValue());
			Assert::AreEqual(10, cells[2].getValue());
		}

		TEST_METHOD(Create_a_cellmatrix)
		{
			CellMatrix<SimpleCell<int>> matrix(SimpleCellMatrixBuilder<int>(3, 3, 0));

			Assert::IsNotNull(matrix.Cell(0, 0));
			Assert::IsNotNull(matrix.Cell(2, 2));

			Assert::ExpectException<std::exception>([&] { return matrix.Cell(-1, -1); });
			Assert::ExpectException<std::exception>([&] { return matrix.Cell(2, 3); } );
		}

		TEST_METHOD(Check_cell_matrix_neighbour)
		{
			CellMatrix<SimpleCell<int>> matrix(SimpleCellMatrixBuilder<int>(3, 3, 0));

			Assert::AreEqual((void*)matrix.Cell(0,0), (void*)matrix.Cell(1,0)->LeftCell());
		}
	};
}