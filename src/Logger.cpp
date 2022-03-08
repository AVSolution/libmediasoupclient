#define MSC_CLASS "Logger"

#include "Logger.hpp"
#include <iostream>

namespace mediasoupclient
{
	/* Class variables. */

	Logger::LogHandlerInterface* Logger::handler{ nullptr };
	char Logger::buffer[Logger::bufferSize];
	Logger::LogLevel Logger::logLevel = Logger::LogLevel::LOG_NONE;
	std::ofstream Logger::logFilter;

	/* Class methods. */

	void Logger::SetLogLevel(Logger::LogLevel level)
	{
		Logger::logLevel = level;
	}

	void Logger::SetHandler(LogHandlerInterface* handler)
	{
		Logger::handler = handler;
	}

	void Logger::SetDefaultHandler()
	{
		Logger::handler = new Logger::DefaultLogHandler();
	}

	void Logger::setLogFilter(const std::string& filepath)
	{
		if (!logFilter.is_open()) {
			logFilter.open(filepath);
		}
	}

	/* DefaultLogHandler */

	void Logger::DefaultLogHandler::OnLog(LogLevel /*level*/, char* payload, size_t /*len*/)
	{
		std::cout << payload << std::endl;
		logFilter << payload<<std::endl;
	}
} // namespace mediasoupclient
