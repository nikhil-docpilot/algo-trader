#pragma once
#include <string>

class Instrument {
public:
    Instrument(int instrumentToken,
               int exchangeToken,
               const std::string& tradingSymbol,
               const std::string& name,
               double lastPrice,
               const std::string& expiry,
               double strike,
               double tickSize,
               int lotSize,
               const std::string& instrumentType,
               const std::string& segment,
               const std::string& exchange);

    // Getters
    int getInstrumentToken() const;
    int getExchangeToken() const;
    std::string getTradingSymbol() const;
    std::string getName() const;
    double getLastPrice() const;
    std::string getExpiry() const;
    double getStrike() const;
    double getTickSize() const;
    int getLotSize() const;
    std::string getInstrumentType() const;
    std::string getSegment() const;
    std::string getExchange() const;

    // Updates
    void setLastPrice(double price);

    // Debug helper
    std::string toString() const;

private:
    int instrumentToken;
    int exchangeToken;
    std::string tradingSymbol;
    std::string name;
    double lastPrice;
    std::string expiry;
    double strike;
    double tickSize;
    int lotSize;
    std::string instrumentType;
    std::string segment;
    std::string exchange;
};
