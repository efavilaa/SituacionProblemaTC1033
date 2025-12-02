// Enum class para model
#pragma once
#include <string>
#include <stdexcept>

enum class Model
{
    COROLLA,
    CAMRY,
    RAV4,
    YARIS
};

void stringToModel(const s::string &str, Model &model)
{
    if (str == "Corolla")
    {
        model = Model::COROLLA;
    }
    else if (str == "Camry")
    {
        model = Model::CAMRY;
    }
    else if (str == "RAV4")
    {
        model = Model::RAV4;
    }
    else if (str == "Yaris")
    {
        model = Model::YARIS;
    }
    else
    {
        throw std::invalid_argument("Invalid model string");
    }
}

// Convertir de model a string
void modelToString(const Model &model, std::string &str)
{
    switch (model)
    {
    case Model::COROLLA:
        str = "Corolla";
        break;
    case Model::CAMRY:
        str = "Camry";
        break;
    case Model::RAV4:
        str = "RAV4";
        break;
    case Model::YARIS:
        str = "Yaris";
        break;
    default:
        throw std::invalid_argument("Invalid model enum");
    }
}
