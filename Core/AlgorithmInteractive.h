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

	public:
		AlgorithmInteractive();
		~AlgorithmInteractive();

		//Add data to <me>.
		//<paramKey> is key of parameter.
		void AddParam(const string paramKey, const string param);
		//Execute the command <cmd>.
		//Currently, only "Optimization" is supported.
		map<string, string> Execute(const string cmd);

	private:

		AlgorithmInteractive(const AlgorithmInteractive& val);
	};
}


