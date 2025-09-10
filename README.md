# Algo Trader (C++ Backtester Framework)

This project is a modular **algorithmic trading framework** written in C++.  
It includes components for **universe & instruments, market data handling, portfolio tracking, risk management, execution, logging, and backtesting**.

---

## 📂 Project Structure

```
algo-trader/
├── CMakeLists.txt
├── main.cpp
├── common.h
├── instrument.h / instrument.cpp
├── universe.h / universe.cpp
├── order_manager.h / order_manager.cpp
├── portfolio_manager.h / portfolio_manager.cpp
├── execution.h / execution.cpp
├── risk_manager.h / risk_manager.cpp
├── logger.h / logger.cpp
├── strategy.h / strategy.cpp
├── backtester.h / backtester.cpp
├── config.json
└── data.csv
```

---

## ⚙️ Requirements

- C++17 or later
- CMake >= 3.10
- [nlohmann/json](https://github.com/nlohmann/json) (install via package manager)
  ```bash
  sudo apt-get install nlohmann-json3-dev
  ```

---

## 🔨 Build Instructions

```bash
mkdir build && cd build
cmake ..
make
```

---

## ▶️ Run Backtest

```bash
./algo_trader
```

This will run the backtester using `data.csv` and log events to `backtest.log`.

---

## 📊 Config (`config.json`)

```json
{
  "kite_api_key": "your_api_key",
  "kite_access_token": "your_access_token",
  "instruments": ["RELIANCE"],
  "risk_limits": {
    "max_position_per_symbol": 500,
    "max_total_exposure": 2000,
    "stop_loss_pct": 0.02
  },
  "strategy": "libstrategy.so"
}
```

---

## 📈 Example Data (`data.csv`)

```csv
timestamp,symbol,open,high,low,close,volume
1735703100,RELIANCE,2500,2510,2495,2505,100000
1735703400,RELIANCE,2505,2515,2500,2510,120000
1735703700,RELIANCE,2510,2520,2505,2515,90000
```

---

## 🧩 Strategy Development

Strategies implement the `IStrategy` interface. Example:

```cpp
class SampleStrategy : public IStrategy {
public:
    void onCandle(const Candle& candle, ExecutionEngine& exec) override {
        if (candle.close > candle.open) {
            exec.executeBuy(candle.symbol, 100, candle.close);
        }
    }
};
```

You can extend with custom strategies and even load them as `.so` plugins later.

---

## ✅ Next Steps

- Extend backtester for **multi-symbol support**
- Add **PnL analytics (Sharpe, Drawdown, etc.)**
- Add **plugin loader** for user strategies (`.so` / `.dll`)
- Integrate **Kite API Connector** for live trading

---

Happy Trading 🚀
