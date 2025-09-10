#include "risk_manager.h"

RiskManager::RiskManager(const RiskLimits& l, PortfolioManager& pm) : limits(l), portfolio(pm) {}

bool RiskManager::checkOrder(const std::string& symbol, int qty, double price) {
    int existing = portfolio.getPositionQty(symbol);
    if (existing + qty > limits.max_position_per_symbol) {
        return false;
    }
    return true;
}

bool RiskManager::checkStopLoss(double currentPnL) {
    if (currentPnL < -limits.stop_loss_pct) {
        return false;
    }
    return true;
}
