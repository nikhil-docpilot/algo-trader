#pragma once
#include <string>
#include <unordered_map>
#include <vector>

struct Tick {
    std::string symbol;
    double ltp;
    double bid;
    double ask;
    long timestamp;
};

struct Candle {
    std::string symbol;
    long timestamp;
    double open;
    double high;
    double low;
    double close;
    long volume;
};

struct Position {
    std::string symbol;
    int qty = 0;
    double avg_price = 0.0;
};
