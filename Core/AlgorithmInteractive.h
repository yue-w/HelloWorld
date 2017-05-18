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
		DataWrapper* _dataWrapper;
		map<string, CommandCreator*> _commandCreators;

		map<string, string> _outdata;
	public:
		AlgorithmInteractive();
		~AlgorithmInteractive();

		//Add data to <me>.
		//<paramKey> is key of parameter.
		void AddParam(const string paramKey, const string param);
		//Execute the command <cmd>.
		//Currently, only "Optimization" is supported.
		bool Execute(const string cmd);

		map<string, string> GetOutput() const { return _outdata; }

	private:

		AlgorithmInteractive(const AlgorithmInteractive& val);
	};
}


