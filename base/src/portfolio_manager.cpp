#include "portfolio_manager.h"
#include <iostream>

void PortfolioManager::updatePosition(const std::string& symbol, int qty, double price) {
    auto& pos = positions[symbol];
    pos.symbol = symbol;

    if ((pos.qty > 0 && qty < 0) || (pos.qty < 0 && qty > 0)) {
        int closingQty = std::min(std::abs(pos.qty), std::abs(qty));
        double pnlPerShare = (price - pos.avg_price) * (pos.qty > 0 ? closingQty : -closingQty);
        realizedPnL += pnlPerShare;
    }

    int newQty = pos.qty + qty;
    if (newQty != 0) {
        pos.avg_price = ((pos.avg_price * pos.qty) + (price * qty)) / newQty;
    } else {
        pos.avg_price = 0.0;
    }
    pos.qty = newQty;
}

int PortfolioManager::getPositionQty(const std::string& symbol) { return positions[symbol].qty; }
double PortfolioManager::getAvgPrice(const std::string& symbol) { return positions[symbol].avg_price; }

void PortfolioManager::markToMarket(const std::string& symbol, double mktPrice) {
    lastPrice[symbol] = mktPrice;
    unrealizedPnL = 0.0;
    for (auto& kv : positions) {
        const auto& p = kv.second;
        if (p.qty != 0 && lastPrice.count(p.symbol)) {
            unrealizedPnL += (lastPrice[p.symbol] - p.avg_price) * p.qty;
        }
    }
}

double PortfolioManager::getRealizedPnL() const { return realizedPnL; }
double PortfolioManager::getUnrealizedPnL() const { return unrealizedPnL; }
