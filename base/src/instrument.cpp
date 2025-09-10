#include "instrument.h"
#include <sstream>

Instrument::Instrument(int instrumentToken,
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
                       const std::string& exchange)
    : instrumentToken(instrumentToken),
      exchangeToken(exchangeToken),
      tradingSymbol(tradingSymbol),
      name(name),
      lastPrice(lastPrice),
      expiry(expiry),
      strike(strike),
      tickSize(tickSize),
      lotSize(lotSize),
      instrumentType(instrumentType),
      segment(segment),
      exchange(exchange) {}

// Getters
int Instrument::getInstrumentToken() const { return instrumentToken; }
int Instrument::getExchangeToken() const { return exchangeToken; }
std::string Instrument::getTradingSymbol() const { return tradingSymbol; }
std::string Instrument::getName() const { return name; }
double Instrument::getLastPrice() const { return lastPrice; }
std::string Instrument::getExpiry() const { return expiry; }
double Instrument::getStrike() const { return strike; }
double Instrument::getTickSize() const { return tickSize; }
int Instrument::getLotSize() const { return lotSize; }
std::string Instrument::getInstrumentType() const { return instrumentType; }
std::string Instrument::getSegment() const { return segment; }
std::string Instrument::getExchange() const { return exchange; }

// Update
void Instrument::setLastPrice(double price) {
    lastPrice = price;
}

// Debug
std::string Instrument::toString() const {
    std::ostringstream oss;
    oss << "Instrument("
        << "Token=" << instrumentToken
        << ", ExchangeToken=" << exchangeToken
        << ", Symbol=" << tradingSymbol
        << ", Name=" << name
        << ", LastPrice=" << lastPrice
        << ", Expiry=" << expiry
        << ", Strike=" << strike
        << ", TickSize=" << tickSize
        << ", LotSize=" << lotSize
        << ", Type=" << instrumentType
        << ", Segment=" << segment
        << ", Exchange=" << exchange
        << ")";
    return oss.str();
}
