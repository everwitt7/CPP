/**
 * @file Main.cpp
 * @author your name (you@domain.com)
 * @brief lesson on classes
 * @version 0.1
 * @date 2021-11-08
 * 
 * @copyright Copyright (c) 2021
 * 
 * This is a basic example of a logger class, however, this is not the correct way to implement things, it is just a good
 * way to understand classes. There are warning when running this code:
 * warning: default member initializer for non-static data member is a C++11 extension
 */
#include <iostream>

class Log
{
public:
    const int LogLevelError = 0;
    const int LogLevelWarn = 1;
    const int LogLevelInfo = 2;

private:
    int m_LogLevel = LogLevelInfo; // using m_var to denote the attribute is a private class member variable

public:
    void SetLevel(int level)
    {
        m_LogLevel = level; // makes it easy to see which var is inheret to the class and which is input
    }
    void Error(const char *message)
    {
        if (m_LogLevel >= LogLevelError)
            std::cout << "[Error] " << message << std::endl;
    }
    void Warn(const char *message)
    {
        if (m_LogLevel >= LogLevelWarn)
            std::cout << "[WARNING] " << message << std::endl;
    }
    void Info(const char *message)
    {
        if (m_LogLevel >= LogLevelInfo)
            std::cout << "[Info] " << message << std::endl;
    }
};

int main()
{
    Log log;
    log.SetLevel(log.LogLevelWarn); // can change the level to see what prints to the standard output
    log.Warn("warn");
    log.Error("error");
    log.Info("info");
}