// WtykaDoMatlaba.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include "File.h"
#include "BuilderFileFIG.h"
int logarithmicScale()
{
	int number = 0;
	std::cout << "Do you want logarithmic scale? Write number" << std::endl;
	std::cout << "Without logarithmic scale (0)" << std::endl;
	std::cout << "Only X-axis (1)" << std::endl;
	std::cout << "Only Y-axis (2)" << std::endl;
	std::cout << "X-axis ans Y-axis (3)" << std::endl;
	std::cin >> number;
	return number; 
}
std::string setXLabelDescription()
{
	std::string xLabelDescription;
	std::cout << "Give x description" << std::endl;
	std::cin >> xLabelDescription;
	return xLabelDescription;
}
std::string setYLabelDescription()
{
	std::string yLabelDescription;
	std::cout << "Give y description" << std::endl;
	std::cin >> yLabelDescription;
	return yLabelDescription;
}
std::string generateTitle()
{
	std::string title;
	std::cout << "Give the title chart" << std::endl;
	std::cin >> title;
	return title;
}
int generateExtraFunctions()
{
	int number = 0;
	std::cout << " What do you want?" << std::endl;
	std::cout << "Curves line? (1)" << std::endl;
	std::cout << "Stipple chart? (2)" << std::endl;
	std::cout << "Change font size? (3)" << std::endl;
	std::cout << "Chart with dat? (4)" << std::endl;
	std::cout << "You want nothing more? (0)" << std::endl;
	std::cin >> number;
	return number;
}
void getInputData()
{
	std::string lineText;
	std::string data;
	std::string name;
	std::cout << "Give name file with data to chart (plik .txt)" << std::endl;
	std::cin >> name;
	std::string nameCopy(name);
	File file{ name };
	if (".txt" != file.getName().substr(name.size() - 5, file.getName().size()))
		file.setTypeOfFile(".txt");
	std::ifstream fileInput(file.getName());
	if (fileInput.is_open())
	{
		while (std::getline(fileInput, lineText))
		{
			file.setData(lineText);
		}
		fileInput.close();
	}
	file.toMatchDataToMatlabStandard();
	std::string xlabel{ setXLabelDescription() };
	std::string ylabel{ setYLabelDescription() };
	int number = logarithmicScale();
	std::string title = generateTitle();
	std::vector<int> listExtraFunctions;
	for (;;)
	{
		int numberFunction = generateExtraFunctions();
		if (numberFunction == 0)
			break;
		listExtraFunctions.emplace_back(std::move(numberFunction));
	}
	BuilderFileFIG(name, file.getData(), xlabel, ylabel, number, title, std::move(listExtraFunctions));
}
int main()
{
	getInputData();
	system("pause");
    return 0;
}

