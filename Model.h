#pragma once
#include <string>
#include <stdexcept>

// Enum class para model
enum class Model
{
    GT86,
    Corolla,
    RAV4,
    Yaris,
    Auris,
    Aygo,
    C_HR,
    Prius,
    Avensis,
    Verso,
    Hilux,
    PROACE_VERSO,
    Land_Cruiser,
    Supra,
    Camry,
    Verso_S,
    IQ,
    Urban_Cruiser
};

inline Model stringToModel(const std::string& str)
{
    if (str == " GT86") return Model::GT86;
    if (str == " Corolla") return Model::Corolla;
    if (str == " RAV4") return Model::RAV4;
    if (str == " Yaris") return Model::Yaris;
    if (str == " Auris") return Model::Auris;
    if (str == " Aygo") return Model::Aygo;
    if (str == " C-HR") return Model::C_HR;
    if (str == " Prius") return Model::Prius;
    if (str == " Avensis") return Model::Avensis;
    if (str == " Verso") return Model::Verso;
    if (str == " Hilux") return Model::Hilux;
    if (str == " PROACE VERSO") return Model::PROACE_VERSO;
    if (str == " Land Cruiser") return Model::Land_Cruiser;
    if (str == " Supra") return Model::Supra;
    if (str == " Camry") return Model::Camry;
    if (str == " Verso-S") return Model::Verso_S;
    if (str == " IQ") return Model::IQ;
    if (str == " Urban Cruiser") return Model::Urban_Cruiser;

    throw std::invalid_argument("Invalid model: " + str);
}

// Convertir de model a string
inline std::string modelToString(Model m)
{
    switch (m)
    {
        case Model::GT86: return "GT86";
        case Model::Corolla: return "Corolla";
        case Model::RAV4: return "RAV4";
        case Model::Yaris: return "Yaris";
        case Model::Auris: return "Auris";
        case Model::Aygo: return "Aygo";
        case Model::C_HR: return "C-HR";
        case Model::Prius: return "Prius";
        case Model::Avensis: return "Avensis";
        case Model::Verso: return "Verso";
        case Model::Hilux: return "Hilux";
        case Model::PROACE_VERSO: return "PROACE VERSO";
        case Model::Land_Cruiser: return "Land Cruiser";
        case Model::Supra: return "Supra";
        case Model::Camry: return "Camry";
        case Model::Verso_S: return "Verso-S";
        case Model::IQ: return "IQ";
        case Model::Urban_Cruiser: return "Urban Cruiser";
    }
    return "Unknown";
}
