#pragma once
#include <string>
class File
{
public:
	File(const std::string& name, const std::string& data = "") :name(name), data(data) {}
	void toMatchDataToMatlabStandard();
	std::string getName() const { return name; }
	std::string getData() const { return data; }
	void setData(const std::string& newData) { data += newData + "\n"; };
	void setTypeOfFile(std::string typeOfFile) { name += typeOfFile; }
	~File();
private:
	std::string name;
	std::string data;
};

