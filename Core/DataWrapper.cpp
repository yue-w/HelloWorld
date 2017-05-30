#include "DataWrapper.h"


namespace Core
{
	DataWrapper::DataWrapper()
	{
	}


	DataWrapper::DataWrapper(const DataWrapper& data)
	{
		_data = data._data;
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

	bool DataWrapper::HasData(const string key) const
	{
		return _data.find(key) != _data.end();
	}

	void DataWrapper::setVecVariableNameKeys(const vector<std::string> nameKeys)
	{
		_vecVariableNameKeys = nameKeys;
	}

	vector<std::string> DataWrapper::getVecVariableNameKeys() const
	{
		return _vecVariableNameKeys;
	}




}

