#include "../AsyncLogger.h"
#include <gtest/gtest.h>

namespace async
{

class OutputDevice: public IOutputDevice
{
public:
    void write(const std::string &msg) override
    {
        _msgs.push_back(msg);
    }

    const std::vector<std::string> &getMsgs() const
    {
        return _msgs;
    }

private:
    std::vector<std::string> _msgs;
};

TEST(AsyncLogger, test)
{
    auto outputDevice = std::make_shared<OutputDevice>();
    AsyncLogger::Instance().setOutputDevice(outputDevice);

    for (auto i = 0; i < 10000; ++i) {
        AsyncLogger::Instance().log(std::to_string(i));
    }

    for (auto i = 0; i < 10000; ++i) {
        ASSERT_EQ(std::to_string(i), outputDevice->getMsgs()[i]);
    }
}

}//namespace async
