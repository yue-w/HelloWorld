#pragma once
#include "PublicHeader.h"

namespace Core
{
	class DataWrapper;
	class Command;
	class CommandCreator;

	//Interface between UI and Background computation.
	class _EXPORT_CORE_DLL AlgorithmInteractive
	{
		//The input data from UI.
		DataWrapper* _dataWrapper;
		unordered_map<string, CommandCreator*> _commandCreators;

		unordered_map<string, string> _outdata;
	public:
		AlgorithmInteractive();
		~AlgorithmInteractive();

		//Add data to <me>.
		//<paramKey> is key of parameter.
		void AddParam(const string paramKey, const string param);

		
		void setVarNameKey(const vector<string> vecNameKeys);
		vector<string> getVarNameKey()const;

		//Execute the command <cmd>.
		//Currently, only "Optimization" is supported.
		bool Execute(const string cmd);

		unordered_map<string, string> GetOutput() const { return _outdata; }

	private:

		AlgorithmInteractive(const AlgorithmInteractive& val);
	};
}


