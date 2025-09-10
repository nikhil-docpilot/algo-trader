#pragma once
#include "common.h"
#include "execution.h"

class IStrategy {
public:
    virtual void onTick(const Tick& tick, ExecutionEngine& exec) {}
    virtual void onCandle(const Candle& candle, ExecutionEngine& exec) {}
    virtual ~IStrategy() = default;
};

class SampleStrategy : public IStrategy {
public:
    void onCandle(const Candle& candle, ExecutionEngine& exec) override;
};
