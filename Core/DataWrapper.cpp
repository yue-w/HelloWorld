#include "DataWrapper.h"


namespace Core
{
	DataWrapper::DataWrapper()
	{
	}


	DataWrapper::~DataWrapper()
	{
	}

	void DataWrapper::Add(const string paramKey, const string param)
	{
		_data[paramKey] = param;
	}

	std::string DataWrapper::GetData(const string key) const
	{
		if (_data.find(key) != _data.end())
		{
			return _data.at(key);
		}
		return "";
	}

}

