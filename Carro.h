#pragma once
#include <string>
#include <iostream>

#include "Model.h"
#include "Transmission.h"
#include "fuelType.h"

struct Carro {
    // cada columna de el toyota.csv
    Model model;
    int year;
    int price;
    Transmission transmission;
    int mileage;
    FuelType fuelType;
    int tax;
    double mpg;
    double engineSize;


    // operator<< para imprimir todos los datos de los carros
    friend std::ostream& operator<<(std::ostream& os, const Carro& c) {
        os << "Model = " << modelToString(c.model)
        << " | Year = " << c.year
        << " | Price = " << c.price
        << " | Transmission = " << transmissionToString(c.transmission)
        << " | Mileage = " << c.mileage
        << " | Fuel Type = " << fuelTypeToString(c.fuelType)
        << " | Tax = " << c.tax
        << " | MPG = " << c.mpg
        << " | Engine Size = " << c.engineSize;
        return os;
    }

};