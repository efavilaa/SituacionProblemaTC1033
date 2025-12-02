#pragma once
#include <string>
#include <stdexcept>

// enum para los tipos de transmision: automaticos, manuales o semi automaticos
enum class Transmission {
    Automatic,
    Manual,
    Semi_Auto
};

// inline para convertir cada string que diga el tipo de transmision a la clase Transmission
void stringToTransmission(const std::string& str, Transmission &Transmission) {
    if (str == "Automatic") return Transmission::Automatic;
    if (str == "Manual") return Transmission::Manual;
    if (str == "Semi-Auto") return Transmission::Semi_Auto;
    throw std::invalid_argument("Unknown transmission: " + str);
}

// inline para convertir cada Transmission a un string
void transmissionToString(const Transmission &transmission, std::string &str) {
    switch (transmission) {
        case Transmission::Automatic:    return "Automatic";
        case Transmission::Manual:     return "Manual";
        case Transmission::Semi_Auto:           return "Semi-Auto";
    }
    return "Unknown";
}
