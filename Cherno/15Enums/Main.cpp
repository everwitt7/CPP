/**
 * @file Main.cpp
 * @author your name (you@domain.com)
 * @brief lesson on classes
 * @version 0.1
 * @date 2021-11-08
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>

/**
 * @brief Enums and Functions NEED different names. Common practice is to prefix the enum variable name with the name of
 * the actual enum
 * 
 * Behind the scenes enums are just integers, that is it. It just makes it nice to group like objects that you will use
 * for comparisong down the road and setting state value. It is nice because you can do logical comparisons on the enums

 */
class Log
{
public:
    enum Level
    {
        LevelError = 0,
        LevelWarning,
        LevelInfo
    };

private:
    Level m_LogLevel = LevelInfo; // no warning because I specify -std=c++11 in g++ flag

public:
    // Log(Level level) // moved the logic of initializing a private member variable to the constructor
    // {
    //     m_LogLevel = LevelInfo;
    // }
    void SetLevel(Level level)
    {
        m_LogLevel = level;
    }
    void Error(const char *message)
    {
        if (m_LogLevel >= LevelError)
            std::cout << "[Error] " << message << std::endl;
    }
    void Warn(const char *message)
    {
        if (m_LogLevel >= LevelWarning)
            std::cout << "[WARNING] " << message << std::endl;
    }
    void Info(const char *message)
    {
        if (m_LogLevel >= LevelInfo)
            std::cout << "[Info] " << message << std::endl;
    }
};

int main()
{
    Log log;
    log.SetLevel(Log::LevelInfo);
    log.Warn("Hello Warning!");
    log.Error("Hello Error!");
    log.Info("Hello Info!");
}