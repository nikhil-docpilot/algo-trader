#pragma once
#include <string>
#include "portfolio_manager.h"

struct RiskLimits {
    int max_position_per_symbol;
    int max_total_exposure;
    double stop_loss_pct;
};

class RiskManager {
public:
    RiskManager(const RiskLimits& limits, PortfolioManager& pm);
    bool checkOrder(const std::string& symbol, int qty, double price);
    bool checkStopLoss(double currentPnL);

private:
    RiskLimits limits;
    PortfolioManager& portfolio;
};
