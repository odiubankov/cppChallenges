#ifndef ASYNC_LOGGER_H
#define ASYNC_LOGGER_H

#include <string>
#include <thread>
#include <queue>
#include <mutex>
#include <memory>

namespace async
{

class IOutputDevice
{
public:
    virtual ~IOutputDevice() = 0;
    virtual void write(const std::string &msg) = 0;
};

class AsyncLogger
{
public:
    static AsyncLogger &Instance();
    void log(std::string msg);

    void setOutputDevice(std::shared_ptr<IOutputDevice> outputDevice);

private:
    void writeLog();

    AsyncLogger();
    ~AsyncLogger();
    AsyncLogger(const AsyncLogger &) = delete;
    AsyncLogger &operator=(const AsyncLogger &) = delete;

    std::queue<std::string> _msgQueue;
    std::mutex _mutex;
    std::condition_variable _condition;
    std::thread _writingThread;
    std::shared_ptr<IOutputDevice> _outputDevice;
};

}//namespace async

#endif //ASYNC_LOGGER_H