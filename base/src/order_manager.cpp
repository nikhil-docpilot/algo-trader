#include "order_manager.h"

void OrderManager::buy(const std::string& symbol, int qty, double price) {
    std::cout << "[ORDER] BUY " << qty << " " << symbol << " @ " << price << "\n";
}

void OrderManager::sell(const std::string& symbol, int qty, double price) {
    std::cout << "[ORDER] SELL " << qty << " " << symbol << " @ " << price << "\n";
}
