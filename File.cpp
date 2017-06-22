#include "stdafx.h"
#include "File.h"
#include <algorithm>
void File::toMatchDataToMatlabStandard()
{
	data.erase(std::remove(data.begin(), data.end(), '.'),
		data.end());
	std::replace(data.begin(), data.end(), ',', '.');
}


File::~File() = default;
