#pragma once

#include <vector>
#include <fstream>
#include <string>
#include <filesystem>
#include <chrono>
#include <iostream>
using namespace std;
using namespace std::chrono;
#include "splitCommas.h"
#include <sstream>

#include "Carro.h"

class Analyzer
{
private:
    vector<Carro> carros{};

public:
    Analyzer() = default;

    // cargar datos
    void loadData(const filesystem::path &base = filesystem::current_path());
    // imprimir todos
    void printAll();
    // filtrar por fechas
    void filterDates();
    // filtrar por modelo
    void filterModel();
    // top carros con bajos kilometrajes
    void lowestMileage();
    // quiz carro ideal
    void idealCarQuiz(const std::string &outputFilename = "reporte_coches_ideales.txt");
};

// cargar datos
void Analyzer::loadData(const filesystem::path &base)
{
    filesystem::path file = base / "toyota.csv";

    if (!filesystem::exists(file))
        throw runtime_error("toyota.csv not found");

    ifstream in(file);
    if (!in)
        throw runtime_error("Cannot open toyota.csv");

    string line;
    bool first = true;

    while (getline(in, line))
    {
        if (first)
        { // saltar header
            first = false;
            continue;
        }

        vector<string> f;
        string temp;
        for (char c : line)
        {
            if (c == ',')
            {
                f.push_back(temp);
                temp.clear();
            }
            else
                temp += c;
        }
        f.push_back(temp);

        if (f.size() != 9)
            throw runtime_error("Invalid CSV format");

        Carro c;
        c.model = stringToModel(f[0]);
        c.year = stoi(f[1]);
        c.price = stoi(f[2]);
        c.transmission = stringToTransmission(f[3]);
        c.mileage = stoi(f[4]);
        c.fuelType = stringToFuelType(f[5]);
        c.tax = stoi(f[6]);
        c.mpg = stod(f[7]);
        c.engineSize = stod(f[8]);

        carros.push_back(c);
    }
}

// mostrar todos
void Analyzer::printAll()
{
    for (const auto &tx : carros)
    {
        cout << tx << endl;
    }
}

// filtrar por fechas
void Analyzer::filterDates()
{
    int a, b;
    cout << "Start year: ";
    cin >> a;
    cout << "End year: ";
    cin >> b;

    for (const auto &c : carros)
    {
        if (c.year >= a && c.year <= b)
            cout << c << endl;
    }
}

void Analyzer::filterModel()
{
    cout << "\nChoose a model:\n";
    cout << "----------------\n";
    cout << " 1) GT86\n";
    cout << " 2) Corolla\n";
    cout << " 3) RAV4\n";
    cout << " 4) Yaris\n";
    cout << " 5) Auris\n";
    cout << " 6) Aygo\n";
    cout << " 7) C-HR\n";
    cout << " 8) Prius\n";
    cout << " 9) Avensis\n";
    cout << "10) Verso\n";
    cout << "11) Hilux\n";
    cout << "12) PROACE VERSO\n";
    cout << "13) Land Cruiser\n";
    cout << "14) Supra\n";
    cout << "15) Camry\n";
    cout << "16) Verso-S\n";
    cout << "17) IQ\n";
    cout << "18) Urban Cruiser\n";

    int opcion;
    cout << "\nOption: ";
    cin >> opcion;

    if (opcion < 1 || opcion > 18)
    {
        cout << "Invalid option.\n";
        return;
    }

    // convertir num a enum
    Model chosen = static_cast<Model>(opcion - 1);

    cout << "\nCars of model: " << modelToString(chosen) << "\n";
    cout << "--------------------------------------\n";

    bool found = false;
    for (const auto& c : carros)
    {
        if (c.model == chosen)
        {
            cout << c << endl;
            found = true;
        }
    }

    if (!found)
        cout << "No cars found with that model.\n";
}


// top carros con bajos kilometrajes (FALTA)
void Analyzer::lowestMileage()
{
    sort(carros.begin(), carros.end(),
         [](const Carro &x, const Carro &y)
         {
             return x.mileage < y.mileage;
         });

    cout << "Top 5 lowest mileage cars:\n";
    for (int i = 0; i < 5 && i < carros.size(); i++)
    {
        cout << carros[i] << endl;
    }
}

// quiz carro ideal
void Analyzer::idealCarQuiz(const std::string &outputFilename)
{

    cout << "\n==============================\n";
    cout << "        IDEAL CAR QUIZ\n";
    cout << "==============================\n\n";

    // MODEL
    cout << "\nChoose MODEL (or 0 for N/A):\n";
    cout << "  1) GT86\n";
    cout << "  2) Corolla\n";
    cout << "  3) RAV4\n";
    cout << "  4) Yaris\n";
    cout << "  5) Auris\n";
    cout << "  6) Aygo\n";
    cout << "  7) C-HR\n";
    cout << "  8) Prius\n";
    cout << "  9) Avensis\n";
    cout << " 10) Verso\n";
    cout << " 11) Hilux\n";
    cout << " 12) PROACE VERSO\n";
    cout << " 13) Land Cruiser\n";
    cout << " 14) Supra\n";
    cout << " 15) Camry\n";
    cout << " 16) Verso-S\n";
    cout << " 17) IQ\n";
    cout << " 18) Urban Cruiser\n";

    int modelChoice;
    cin >> modelChoice;

    bool filterModelQuiz = (modelChoice != 0);
    Model modelQ;
    if (filterModelQuiz)
        modelQ = static_cast<Model>(modelChoice - 1);

    // YEAR
    string yearIn;
    cout << "Minimum year (or N/A): ";
    cin >> yearIn;

    int minYear = -1;
    if (yearIn != "N/A" && yearIn != "n/a" && yearIn != "NA")
        minYear = stoi(yearIn);

    // PRICE

    string priceIn;
    cout << "Price range [min-max] (o N/A): ";
    cin >> priceIn;

    int minimo = -1;
    int maximo = -1;

    if (priceIn != "N/A" && priceIn != "NA" && priceIn != "n/a" && priceIn != "na")
    {

        size_t pos = priceIn.find('-');

        if (pos == std::string::npos || pos == 0 || pos == priceIn.length() - 1)
        {
            std::cout << "Error: Invalid format (must be min-max).\n";
        }

        try
        {

            minimo = stoi(priceIn.substr(0, pos));
            maximo = stoi(priceIn.substr(pos + 1));
        }
        catch (const std::invalid_argument &e)
        {
            cout << "Error: Range values must be numeric.\n";
        }
        catch (const std::out_of_range &e)
        {
            cout << "Error: Range is out of integer limits.\n";
        }
    }

    // TRANSMISSION
    cout << "\nChoose TRANSMISSION (or 0 for N/A):\n";
    cout << "  1 | Automatic\n";
    cout << "  2 | Manual\n";
    cout << "  3 | Semi-Auto\n";
    int tChoice;
    cin >> tChoice;

    bool filterTrans = (tChoice != 0);
    Transmission t;
    if (tChoice == 1)
        t = Transmission::Automatic;
    else if (tChoice == 2)
        t = Transmission::Manual;
    else if (tChoice == 3)
        t = Transmission::Semi_Auto;

    // MILEAGE
    string milesIn;
    cout << "\nMaximum mileage (or N/A): ";
    cin >> milesIn;

    int maxMileage = -1;
    if (milesIn != "N/A" && milesIn != "n/a" && milesIn != "NA" && milesIn != "na")
        maxMileage = stoi(milesIn);

    // FUEL TYPE
    cout << "\nChoose FUEL TYPE (or 0 for N/A):\n";
    cout << "  1 | Petrol\n";
    cout << "  2 | Hybrid\n";
    cout << "  3 | Diesel\n";
    int fChoice;
    cin >> fChoice;

    bool filterFuel = (fChoice != 0);
    FuelType ft;
    if (fChoice == 1)
        ft = FuelType::Petrol;
    else if (fChoice == 2)
        ft = FuelType::Hybrid;
    else if (fChoice == 3)
        ft = FuelType::Diesel;

    // MPG
    string mpgIn;
    cout << "\nMinimum MPG (or N/A): ";
    cin >> mpgIn;

    double minMPG = -1;
    if (mpgIn != "N/A" && mpgIn != "n/a" && mpgIn != "NA" && mpgIn != "na")
        minMPG = stod(mpgIn);

    std::stringstream reportStream;
    reportStream << "\n=========== RESULTS ===========\n\n";

    bool found = false;

    for (const auto &c : carros)
    {
        if ((minYear == -1 || c.year >= minYear) &&
            (maximo == -1 || c.price <= maximo) &&
            (minimo == -1 || c.price >= minimo) &&
            (!filterTrans || c.transmission == t) &&
            (!filterModelQuiz || c.model == modelQ) &&  
            (maxMileage == -1 || c.mileage <= maxMileage) &&
            (!filterFuel || c.fuelType == ft) &&
            (minMPG == -1 || c.mpg >= minMPG))
        {
            reportStream << c << "\n";
            found = true;
        }
    }

    if (!found)
        reportStream << "No cars match your preferences. (っ◞‸◟ c)\n";

    reportStream << "=================================\n";
    cout << "=================================\n";

    std::cout << reportStream.str();

    // ask if they want to export
    string choice;
    cout << "\nDo you wish to save the report? (Y/N): ";
    cin >> choice;

    std::transform(choice.begin(), choice.end(), choice.begin(), ::toupper);

    if (choice == "Y" || choice == "yes" || choice == "YES" || choice == "y")
    {
        std::string filename;
        std::cout << "Enter the filename (e.g., report.txt): ";
        std::cin >> filename;

        std::ofstream outFile(filename);

        if (!outFile)
        {
            std::cerr << "Error: Could not open file for writing: " << filename << "\n";
            return;
        }

        outFile << reportStream.str();

        std::cout << "Report saved  to '" << filename << "'\n";
    }
}