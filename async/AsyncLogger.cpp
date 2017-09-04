#include "AsyncLogger.h"

namespace {
const char* STOP_LOGGING_MSG = "{34EA1AB3-E76E-4C41-9F07-5803EEC9D567}";
}

namespace async
{

IOutputDevice::~IOutputDevice() = default;

AsyncLogger &AsyncLogger::Instance()
{
    static AsyncLogger asyncLogger;
    return asyncLogger;
}

AsyncLogger::~AsyncLogger()
{
    log(STOP_LOGGING_MSG);
    _writingThread.join();
}

void AsyncLogger::log(std::string msg)
{
    {
        std::unique_lock<std::mutex> lock{_mutex};
        _msgQueue.push(std::move(msg));
    }

    _condition.notify_one();
}

void AsyncLogger::setOutputDevice(std::shared_ptr<IOutputDevice> outputDevice)
{
    _outputDevice = std::move(outputDevice);
}

void AsyncLogger::writeLog()
{
    std::string nextMsg;
    for (;;) {
        {
            std::unique_lock<std::mutex> lock{_mutex};
            _condition.wait(lock, [this]()
            { return !_msgQueue.empty(); });
            nextMsg = _msgQueue.front();
            _msgQueue.pop();
        }

        if (nextMsg == STOP_LOGGING_MSG)
            break;

        _outputDevice->write(nextMsg);
    }
}

}//namespace async