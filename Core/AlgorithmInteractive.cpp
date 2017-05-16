#include "AlgorithmInteractive.h"
#include "DataWrapper.h"

#include "Command.h"
#include "OptimizationCommand.h"

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

	map<string, string> AlgorithmInteractive::Execute(const string cmd)
	{
		auto command = _commandCreators[cmd]->Create();

		command->Execute(_dataWrapper);

		auto outdata= command->GetOutData();

		delete command;

		return outdata;
	}
}
