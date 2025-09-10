#include "logger.h"
#include <iostream>

Logger::Logger(const std::string& filename) { file.open(filename, std::ios::app); }
Logger::~Logger() { if (file.is_open()) file.close(); }

void Logger::logTick(const Tick& t) {
    file << "TICK," << t.symbol << "," << t.ltp << "," << t.bid << "," << t.ask << "," << t.timestamp << "\n";
}

void Logger::logOrder(const std::string& side, const std::string& symbol, int qty, double price) {
    file << "ORDER," << side << "," << symbol << "," << qty << "," << price << "\n";
}

void Logger::logMessage(const std::string& msg) { file << "MSG," << msg << "\n"; }
