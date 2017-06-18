#pragma once
#include "PublicHeader.h"

namespace Core
{
	class _EXPORT_DLL_UNIT_TEST DataWrapper
	{
		unordered_map<string, string> _data;

		//contains all the keys of variable name.
		vector<std::string> _vecVariableNameKeys;////to be delete

	public:
		DataWrapper();
		~DataWrapper();
		DataWrapper(const DataWrapper& data);

		//Add data to <me>.
		//<paramKey> is key of parameter.
		void Add(const string paramKey, const string param);

		string GetData(const string key) const;

		bool HasData(const string key) const;

		unordered_map<string, string> GetAllData() const { return _data; }

		void setVecVariableNameKeys(const vector<std::string> nameKeys);
		vector<std::string>getVecVariableNameKeys()const;
		//void PushBackVecVariableNameKey(const std::string nameKey);
	};
}


