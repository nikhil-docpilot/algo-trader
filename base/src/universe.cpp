#include "universe.h"
#include <fstream>
#include <sstream>
#include <iostream>

void Universe::loadFromCSV(const std::string& csvFile) {
    std::ifstream csv(csvFile);
    if (!csv.is_open()) {
        std::cerr << "Error: Could not open " << csvFile << std::endl;
        return;
    }

    auto safe_stoi = [](const std::string& s, int def = 0) {
        try { return s.empty() ? def : std::stoi(s); }
        catch (...) { return def; }
    };

    auto safe_stod = [](const std::string& s, double def = 0.0) {
        try { return s.empty() ? def : std::stod(s); }
        catch (...) { return def; }
    };

    std::string line;
    bool header = true;

    while (std::getline(csv, line)) {
        if (header) { header = false; continue; }
        if (line.empty()) continue;

        std::stringstream ss(line);
        std::string instrumentToken, exchangeToken, tradingSymbol, name, lastPrice,
                    expiry, strike, tickSize, lotSize, instrumentType, segment, exchange;

        std::getline(ss, instrumentToken, ',');
        std::getline(ss, exchangeToken, ',');
        std::getline(ss, tradingSymbol, ',');
        std::getline(ss, name, ',');
        std::getline(ss, lastPrice, ',');
        std::getline(ss, expiry, ',');
        std::getline(ss, strike, ',');
        std::getline(ss, tickSize, ',');
        std::getline(ss, lotSize, ',');
        std::getline(ss, instrumentType, ',');
        std::getline(ss, segment, ',');
        std::getline(ss, exchange, ',');

        // Build instrument safely
        Instrument inst(
            safe_stoi(instrumentToken),
            safe_stoi(exchangeToken),
            tradingSymbol,
            name,
            safe_stod(lastPrice),
            expiry,
            safe_stod(strike),
            safe_stod(tickSize, 0.05), // sensible default tick size
            safe_stoi(lotSize, 1),     // sensible default lot size
            instrumentType,
            segment,
            exchange
        );

        std::string key = tradingSymbol + "_" + segment;
        masterUniverse.emplace(key, inst);
    }

    std::cout << "Loaded " << masterUniverse.size()
              << " instruments from " << csvFile << std::endl;
}


void Universe::selectActive(const json& universeBlock) {
    for (auto& seg : universeBlock) {
        std::string segment = seg["segment"];
        for (auto& sym : seg["instruments"]) {
            std::string key = sym.get<std::string>() + "_" + segment;
            if (masterUniverse.count(key)) {
                auto it = masterUniverse.find(key);
                if (it != masterUniverse.end()) {
                    activeUniverse[key] = &it->second;
                } else {
                    std::cerr << "Warning: Instrument not found in masterUniverse: " << key << std::endl;
                }
                std::cout << "Activated: " << sym.get<std::string>() 
                          << " in " << segment << std::endl;
            } else {
                std::cerr << "Warning: " << sym.get<std::string>() 
                          << " not found in universe.csv for " << segment << std::endl;
            }
        }
    }
}

Instrument* Universe::getInstrument(const std::string& key) {
    if (activeUniverse.count(key)) {
        return activeUniverse[key];
    }
    return nullptr;
}

std::vector<std::string> Universe::listActiveInstruments() const {
    std::vector<std::string> syms;
    for (const auto& kv : activeUniverse) {
        syms.push_back(kv.first);
    }
    return syms;
}
