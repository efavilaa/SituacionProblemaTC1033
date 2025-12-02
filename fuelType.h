// Enum class para fuel type
#pragma once

enum class FuelType
{
    PETROL,
    HYBRID,
    DIESEL
};

// Convertir de string a fuel type
void stringToFuelType(const std::string &str, FuelType &fuelType)
{
    if (str == "Petrol")
    {
        fuelType = FuelType::PETROL;
    }
    else if (str == "Hybrid")
    {
        fuelType = FuelType::HYBRID;
    }
    else if (str == "Diesel")
    {
        fuelType = FuelType::DIESEL;
    }
    else
    {
        throw std::invalid_argument("Invalid fuel type string");
    }
}

// Convertir de fuel type a string
void fuelTypeToString(const FuelType &fuelType, std::string &str)
{
    switch (fuelType)
    {
    case FuelType::PETROL:
        str = "Petrol";
        break;
    case FuelType::HYBRID:
        str = "Hybrid";
        break;
    case FuelType::DIESEL:
        str = "Diesel";
        break;
    default:
        throw std::invalid_argument("Invalid fuel type enum");
    }
}