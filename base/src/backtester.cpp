#include "backtester.h"
#include "common.h"
#include <fstream>
#include <sstream>
#include <iostream>

Backtester::Backtester(const std::string& file,
                       IStrategy& s,
                       ExecutionEngine& e,
                       PortfolioManager& pm,
                       Logger& l,
                       RiskManager& r)
    : dataFile(file), strategy(s), exec(e), portfolio(pm), logger(l), risk(r) {}

void Backtester::runCandles() {
    std::ifstream f(dataFile);
    std::string line;
    bool header = true;

    while (std::getline(f, line)) {
        if (header) { header = false; continue; }
        std::stringstream ss(line);
        std::string ts, sym, o, h, l, c, v;
        std::getline(ss, ts, ','); std::getline(ss, sym, ','); std::getline(ss, o, ','); 
        std::getline(ss, h, ','); std::getline(ss, l, ','); std::getline(ss, c, ','); std::getline(ss, v, ',');
        Candle candle{sym, std::stol(ts), std::stod(o), std::stod(h), std::stod(l), std::stod(c), std::stol(v)};
        logger.logMessage("Candle: " + sym + " O=" + o + " C=" + c);
        portfolio.markToMarket(sym, candle.close);
        if (risk.checkOrder(sym, 100, candle.close)) {
            strategy.onCandle(candle, exec);
        }
    }

    std::cout << "Backtest complete.\n";
    std::cout << "Realized PnL: " << portfolio.getRealizedPnL() << "\n";
    std::cout << "Unrealized PnL: " << portfolio.getUnrealizedPnL() << "\n";
    std::cout << "Total PnL: " << portfolio.getRealizedPnL() + portfolio.getUnrealizedPnL() << "\n";
}
