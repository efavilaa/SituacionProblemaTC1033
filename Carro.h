#pragma once
#include <string>
#include <chrono>
using namespace std;
using namespace std::chrono;
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
    friend ostream& operator<<(ostream& os, const Carro& tx) {

        os << "Model = " << tx.txid
           << " | Year = " << y << "-" << m << "-" << d
           << " | Price = " << static_cast<int>(tx.category)
           << " | Transmission = " << tx.amount
           << " | Mileage = " << tx.store
           << " | Fuel Type = " << tx.store
           << " | Tax = " << tx.store
           << " | MPG = " << tx.store
           << " | Engine Size = " << tx.store;

        return os;
    }
};