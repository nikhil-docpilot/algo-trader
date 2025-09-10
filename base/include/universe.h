#pragma once
#include <string>
#include <unordered_map>
#include <memory>
#include <vector>
#include "instrument.h"
#include <nlohmann/json.hpp>

using json = nlohmann::json;

class Universe {
public:
    // Load full master universe from Zerodha dump
    void loadFromCSV(const std::string& csvFile);

    // Select active instruments from parsed config
    void selectActive(const json& universeBlock);

    // Access
    Instrument* getInstrument(const std::string& key);
    std::vector<std::string> listActiveInstruments() const;

private:
    std::unordered_map<std::string, Instrument> masterUniverse;
    std::unordered_map<std::string, Instrument*> activeUniverse;
};
