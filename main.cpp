#include <iostream>
#include <fstream>
#include <nlohmann/json.hpp>
#include "universe.h"
#include "strategy.h"
#include "order_manager.h"
#include "portfolio_manager.h"
#include "execution.h"
#include "logger.h"
#include "risk_manager.h"
#include "backtester.h"

using json = nlohmann::json;

int main() {
    std::ifstream f("config.json");
    json cfg; f >> cfg;

    PortfolioManager pm;
    OrderManager om;
    ExecutionEngine exec(om, pm);
    SampleStrategy strategy;
    Logger logger("backtest.log");


   
    Universe universe;

    // Load all instruments from Zerodha dump
    universe.loadFromCSV("../data/universe.csv");

    // Select only instruments defined in config.json
    universe.selectActive(cfg["universe"]);

    // Print active ones
    for (auto& sym : universe.listActiveInstruments()) {
        Instrument* inst = universe.getInstrument(sym);
        std::cout << "Trading " << inst->getTradingSymbol()
                  << " (segment " << inst->getSegment() << ")"
                  << " lot=" << inst->getLotSize()
                  << " tick=" << inst->getTickSize()
                  << std::endl;
    }

    RiskLimits limits{
        cfg["risk_limits"]["max_position_per_symbol"],
        cfg["risk_limits"]["max_total_exposure"],
        cfg["risk_limits"]["stop_loss_pct"]
    };
    RiskManager risk(limits, pm);

    Backtester bt("data/historicalData.csv", strategy, exec, pm, logger, risk);
    bt.runCandles();
    return 0;
}
