#pragma once
#include <string>
#include <vector>
class BuilderFileFIG
{
	public:
		BuilderFileFIG(const std::string&, 
						const std::string&, 
						const std::string&, 
						const std::string&, 
						const int&, 
						const std::string&,
						std::vector<int>&&);
	std::string getLogarithmicScale(const int&);
	void BuilderFileFIG::getAdditionalFunction(std::vector<int>&&,
												std::string&,
												std::string&);
	std::string getMatlabFunction(const std::string&&,
									const std::string&&,
									const std::string&&,
									const std::string&&,
									const std::string&&,
									const std::string&&);
	~BuilderFileFIG();
	private:
		std::string bodyFile;
		std::string name;
};

