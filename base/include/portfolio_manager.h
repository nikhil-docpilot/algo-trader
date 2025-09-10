#pragma once
#include "common.h"
#include <unordered_map>

class PortfolioManager {
public:
    void updatePosition(const std::string& symbol, int qty, double price);
    int getPositionQty(const std::string& symbol);
    double getAvgPrice(const std::string& symbol);
    void markToMarket(const std::string& symbol, double mktPrice);
    double getRealizedPnL() const;
    double getUnrealizedPnL() const;

private:
    std::unordered_map<std::string, Position> positions;
    std::unordered_map<std::string, double> lastPrice;
    double realizedPnL = 0.0;
    double unrealizedPnL = 0.0;
};
