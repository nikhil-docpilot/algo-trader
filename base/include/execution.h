#pragma once
#include "common.h"
#include "order_manager.h"
#include "portfolio_manager.h"

class ExecutionEngine {
public:
    ExecutionEngine(OrderManager& om, PortfolioManager& pm);
    void executeBuy(const std::string& symbol, int qty, double price);
    void executeSell(const std::string& symbol, int qty, double price);

private:
    OrderManager& orderManager;
    PortfolioManager& portfolioManager;
};
