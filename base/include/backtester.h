#pragma once
#include <string>
#include "strategy.h"
#include "execution.h"
#include "portfolio_manager.h"
#include "logger.h"
#include "risk_manager.h"

class Backtester {
public:
    Backtester(const std::string& dataFile,
               IStrategy& strategy,
               ExecutionEngine& exec,
               PortfolioManager& pm,
               Logger& logger,
               RiskManager& risk);
    void runCandles();

private:
    std::string dataFile;
    IStrategy& strategy;
    ExecutionEngine& exec;
    PortfolioManager& portfolio;
    Logger& logger;
    RiskManager& risk;
};
