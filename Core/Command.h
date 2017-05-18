#pragma once
#include "PublicHeader.h"

namespace Core
{
<<<<<<< HEAD
	_declspec(dllexport) double TestOptimize(const std::vector<double>& lowerBound, std::vector<double>& var);
	_declspec(dllexport) void test();
=======
	class DataWrapper;

	class Command
	{
	public:
		Command();
		~Command();

		virtual void Execute(const DataWrapper* data) = 0;
		//Get output data.
		//Use <Execute> first!
		virtual map<string, string> GetOutData() const = 0;

	private:

		Command(const Command& val);
	};

	//Base of command creator for creating different command.
	class CommandCreator
	{
	public:
		CommandCreator() {};
		~CommandCreator() {};

		virtual Command* Create() const = 0;
	};

	template<class T>
	class ConcreteCommandCreator : public CommandCreator
	{
	public:
		ConcreteCommandCreator() {};
		~ConcreteCommandCreator() {};

		virtual Command* Create() const
		{
			return new T();
		}
	};
>>>>>>> 6642de20967f6defeb691c953c77675de27b5fd9
}

