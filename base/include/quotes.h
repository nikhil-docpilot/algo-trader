#pragma once
#include <string>

class Quotes {
public:
    Quotes(const std::string& sym);
    void update(double ltp, double bid, double ask, long ts);
    std::string getSymbol() const;
    double getLtp() const;
    double getBid() const;
    double getAsk() const;
    long getTimestamp() const;

private:
    std::string symbol;
    double lastTradedPrice = 0.0;
    double bestBid[5] = {0.0};
    double bestAsk[5] = {0.0};
    long timestamp = 0;
};
