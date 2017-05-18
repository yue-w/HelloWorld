#pragma once
#include "PublicHeader.h"

namespace Core
{
	class DataWrapper
	{
		map<string, string> _data;
	public:
		DataWrapper();
		~DataWrapper();

		//Add data to <me>.
		//<paramKey> is key of parameter.
		void Add(const string paramKey, const string param);

		string GetData(const string key) const;

		map<string, string> GetAllData() const { return _data; }
	};
}

