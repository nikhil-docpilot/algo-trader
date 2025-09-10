#pragma once
#include <string>
#include <iostream>

class OrderManager {
public:
    void buy(const std::string& symbol, int qty, double price);
    void sell(const std::string& symbol, int qty, double price);
};
