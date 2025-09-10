#include "strategy.h"
#include <iostream>

void SampleStrategy::onCandle(const Candle& candle, ExecutionEngine& exec) {
    if (candle.close > candle.open) {
        exec.executeBuy(candle.symbol, 100, candle.close);
        std::cout << "[Strategy] Bullish candle -> BUY " << candle.symbol << "\n";
    }
}
