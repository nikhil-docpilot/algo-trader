#include "quotes.h"

Quotes::Quotes(const std::string& sym) : symbol(sym) {}

void Quotes::update(double ltp, double bid, double ask, long ts) {
    lastTradedPrice = ltp;
    bestBid[0] = bid;
    bestAsk[0] = ask;
    timestamp = ts;
}

std::string Quotes::getSymbol() const { return symbol; }
double Quotes::getLtp() const { return lastTradedPrice; }
double Quotes::getBid() const { return bestBid[0]; }
double Quotes::getAsk() const { return bestAsk[0]; }
long Quotes::getTimestamp() const { return timestamp; }
