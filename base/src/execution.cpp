#include "execution.h"

ExecutionEngine::ExecutionEngine(OrderManager& om, PortfolioManager& pm)
    : orderManager(om), portfolioManager(pm) {}

void ExecutionEngine::executeBuy(const std::string& symbol, int qty, double price) {
    orderManager.buy(symbol, qty, price);
    portfolioManager.updatePosition(symbol, qty, price);
}

void ExecutionEngine::executeSell(const std::string& symbol, int qty, double price) {
    orderManager.sell(symbol, qty, price);
    portfolioManager.updatePosition(symbol, -qty, price);
}
