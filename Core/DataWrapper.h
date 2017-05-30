#pragma once
#include "PublicHeader.h"

namespace Core
{
	class DataWrapper
	{
		unordered_map<string, string> _data;

		//contains all the keys of variable name.
		vector<std::string> _vecVariableNameKeys;

	public:
		DataWrapper();
		~DataWrapper();

		//Add data to <me>.
		//<paramKey> is key of parameter.
		void Add(const string paramKey, const string param);

		string GetData(const string key) const;

		unordered_map<string, string> GetAllData() const { return _data; }

		void setVecVariableNameKeys(const vector<std::string> nameKeys);
		vector<std::string>getVecVariableNameKeys()const;
		//void PushBackVecVariableNameKey(const std::string nameKey);
	};
}


