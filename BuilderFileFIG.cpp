#include "stdafx.h"
#include "BuilderFileFIG.h"
#include <fstream>
#include <iostream>
BuilderFileFIG::BuilderFileFIG(const std::string& name, 
								const std::string& data, 
								const std::string& xLabelDiscription,
								const std::string& yLabelDiscription,
								const int& logarithmic,
								const std::string& title,
								std::vector<int>&& listFunctions) :name(name), bodyFile(data)
{
	std::ofstream fileFIG{ name + "Matlab" + ".txt" };
	std::string logarithmicScale = getLogarithmicScale(logarithmic);
	std::string fontSize{ "12" };
	getAdditionalFunction(std::move(listFunctions), logarithmicScale, fontSize);
	std::string matlabFunction = getMatlabFunction(std::move(data),
													std::move(logarithmicScale),
													std::move(xLabelDiscription),
													std::move(yLabelDiscription),
													std::move(title),
													std::move(fontSize));
	fileFIG << matlabFunction;
}

std::string BuilderFileFIG::getMatlabFunction(const std::string&& data,
	const std::string&& logarithmicScale,
	const std::string&& xLabelDiscription,
	const std::string&& yLabelDiscription,
	const std::string&& title,
	const std::string&& fontSize)
{
	std::string matlabFunction{ "close all; clear all;\n"
		"%dane = [ur ir]\n"
		"	dane = [\n"
		+ data +
		"	];\n"
		"ir = dane(:,2); ur = dane(:,1);\n"
		"figure(1);\n"
		+ logarithmicScale +
		"set(gca,'xMinorGrid','on','yMinorGrid','on');\n"
		"xlabel(" + "'" + xLabelDiscription + "', 'FontSize' ," + fontSize + ");\n"
		"ylabel(" + "'" + yLabelDiscription + "', 'FontSize'," + fontSize + ");\n"

		"title('" + title + "','FontSize'," + fontSize + ")\n" };
	return matlabFunction;
}
void BuilderFileFIG::getAdditionalFunction(std::vector<int>&& listFunctions,
											std::string& logarithmicScale,
											std::string& fontSize)
{
	for (int i = 0; i < listFunctions.size(); ++i)
	{
		std::string str{ " uu, ii" };
		switch (listFunctions.at(i))
		{
		case 0:
			break;
		case 1:
			logarithmicScale.insert(logarithmicScale.begin() +
									logarithmicScale.find_first_of(")"),
									str.begin(), str.end());
			break;
		case 2:
			str = "--";
			logarithmicScale.insert(logarithmicScale.begin() +
									logarithmicScale.find_first_of(")"),
									str.begin(), str.end());
			break;
		case 3:
			std::cout << "Give font size" << std::endl;
			std::cin >> fontSize;
			break;
		case 4:
			str = ":";
			logarithmicScale.insert(logarithmicScale.begin() + logarithmicScale.find_first_of(")") - 1, str.begin(), str.end());
			break;
		}
	}
}

std::string BuilderFileFIG::getLogarithmicScale(const int& logarithmic)
{
	std::string logarithmicScale;
	switch (logarithmic)
	{
	case 0:
		break;
	case 1:
		logarithmicScale = "semilogx(ur,ir);\n";
		break;
	case 2:
		logarithmicScale = "semilogy(ur, ir); \n";
		break;
	case 3:
		logarithmicScale = "loglog(ur, ir); \n";
	}
	return logarithmicScale;
}

BuilderFileFIG::~BuilderFileFIG() = default;
