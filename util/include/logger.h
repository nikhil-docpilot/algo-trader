#pragma once
#include "common.h"
#include <fstream>
#include <string>

class Logger {
public:
    Logger(const std::string& filename);
    ~Logger();
    void logTick(const Tick& t);
    void logOrder(const std::string& side, const std::string& symbol, int qty, double price);
    void logMessage(const std::string& msg);

private:
    std::ofstream file;
};
