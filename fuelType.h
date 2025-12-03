// Enum class para fuel type
#pragma once
#include <string>
#include <stdexcept>

enum class FuelType
{
    Petrol,
    Hybrid,
    Diesel,
    Other
};

// Convertir de string a fuel type
inline FuelType stringToFuelType(const std::string& str)
{
    if (str == "Petrol") return FuelType::Petrol;
    if (str == "Hybrid") return FuelType::Hybrid;
    if (str == "Diesel") return FuelType::Diesel;
    if (str == "Other") return FuelType::Other;

    throw std::invalid_argument("Invalid fuel type: " + str);
}

// Convertir de fuel type a string
inline std::string fuelTypeToString(FuelType f)
{
    switch (f)
    {
        case FuelType::Petrol: return "Petrol";
        case FuelType::Hybrid: return "Hybrid";
        case FuelType::Diesel: return "Diesel";
        case FuelType::Other:  return "Other";
    }
    return "Unknown";
}