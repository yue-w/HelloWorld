#include "AlgorithmInteractive.h"
#include "DataWrapper.h"

#include "Command.h"
#include "OptimizationCommand.h"
#include "Log.h"

#include <windows.h>

namespace Core
{
	AlgorithmInteractive::AlgorithmInteractive():_dataWrapper(new DataWrapper())
	{
		_commandCreators["Optimization"] = new ConcreteCommandCreator<OptimizationCommand>();
	}


	AlgorithmInteractive::~AlgorithmInteractive()
	{
		delete _dataWrapper;
		for (auto creator : _commandCreators)
		{
			delete creator.second;
		}
	}

	void AlgorithmInteractive::AddParam(const string paramKey, const string param)
	{
		_dataWrapper->Add(paramKey, param);
	}

	bool AlgorithmInteractive::Execute(const string cmd)
	{
		try
		{
			wchar_t buffer[MAX_PATH];
			GetModuleFileName(NULL, buffer, MAX_PATH);
			wcout <<"Working directory: " <<wstring(buffer)<<endl;

			auto command = _commandCreators[cmd]->Create();

			command->Execute(_dataWrapper);

			_outdata = command->GetOutData();

			delete command;

			return true;
		}
		catch (const std::exception& ex)
		{
			_outdata["error"] = ex.what();
			return false;
		}
	}
}
