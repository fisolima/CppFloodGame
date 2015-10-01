// GameConsole.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "TestClass.h"
#include "IntegerCell.h"

#include <string>
#include <iostream>
#include <map>

#include <algorithm>
#include <vector>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	/*IntegerCell cell(0);

	cell.setValue(10);

	int value = cell.getValue();

	Pippo::PippoTestClass myClass;

	myClass.setValue(30);
	myClass.getValue();
	myClass.Square(25);*/

	/*char buffer[2] = { 0, 0 };

	for (int i = 40; i <= 126; i++)
	{
		std::stringstream result;
		
		buffer[0] = (char)i;

		result << std::hex << i << "-" << std::oct << i << "-" << buffer << std::endl;

		cout << result.str();
	}*/

	/*std::map<int, string> inputMap;
	std::string line;

	while (getline( cin, line))
	{
		if (line.empty()) break;

		int pos = line.find(" ");

		if (pos < 0) return 0;

		int index = atoi(line.substr(0, pos).c_str());

		inputMap.insert(std::pair<int, string>(index, line.substr(pos+1)));
	}

	std::map<int, string>::iterator it;

	for (it = inputMap.begin(); it != inputMap.end(); ++it)
		cout << it->second << " ";

	cout << std::endl;*/

	/*std::vector<std::string> palindromeList;
	std::string line;

	while (getline(cin, line))
	{
		if (line.empty()) break;

		std::string reverse = line;

		for (int j = 0, i = line.length() - 1; j < line.length(); j++, i--)
			reverse[j] = line[i];

		if (reverse == line)
			palindromeList.push_back(line.);
	}

	std::vector<std::string>::iterator it;

	for (it = palindromeList.begin(); it != palindromeList.end(); ++it)
		cout << *it << std::endl;*/

	//int count;
	//std::string line;

	//getline(cin, line);	

	//count = atoi(line.c_str());

	//std::vector<int> results;

	//for (int i = 0; i < count; i++)
	//{
	//	getline(cin, line);

	//	int aPosition = -1;
	//	int isPosition = -1;

	//	// a
	//	int curraPosition = -1;

	//	while ((curraPosition = line.find("a", curraPosition+1)) >= 0)
	//	{
	//		if (aPosition == -1) aPosition = 0;

	//		aPosition += curraPosition;
	//	}

	//	// is
	//	int currisPosition = -1;

	//	while ((currisPosition = line.find("is", currisPosition+1)) >= 0)
	//	{
	//		if (isPosition == -1) isPosition = 0;

	//		isPosition += currisPosition;
	//	}

	//	results.push_back(aPosition + isPosition);
	//}

	//std::vector<int>::iterator it;

	//for (it = results.begin(); it != results.end(); ++it)
	//	cout << *it << std::endl;

	return 0;
}

