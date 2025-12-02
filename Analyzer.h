#if !defined(Analyzer_h)
#define Analyzer_h

#include <vector>
#include <fstream>
#include <string>
#include <filesystem>
#include <chrono>
#include <iostream>
using namespace std;
using namespace std::chrono;
#include "splitCommas.h"

#include "Carro.h"

class Analyzer
{
private:
    vector<Carro> carros{};

public:
    Analyzer() = default;

    vector<Carro> filtrarRangoFechas(const year_month_day &inicio, const year_month_day &fin);

    // cargar datos
    void loadData(const filesystem::path &base = filesystem::current_path());
    // imprimir todos
    void printAll();
    // filtrar por fechas
    void filterDates();
    // top carros con bajos kilometrajes
    void lowestMileage();
    // quiz carro ideal
    void idealCarQuiz();
};

// cargar datos (REVISAR!!!!!!!!!! NO ESTA LISTO, TIENE MUCHAS COSAS QUE NI AL CASO)
void Analyzer::loadData(const filesystem::path &base)
{
    filesystem::path file = base / "toyota.csv";
    if (!filesystem::exists(file) || !filesystem::is_regular_file(file))
    {
        throw runtime_error("toyota.csv not found");
    }
    ifstream in(file);
    if (!in)
        throw runtime_error("Cannot open toyota.csv");
    string line;
    size_t lineNumber = 0; // almacena el número de línea
    while (getline(in, line))
    {
        lineNumber++;
        if (lineNumber > 1)
        {
            auto fields = splitCommas(line);
            if (fields.size() != 5)
            {
                throw runtime_error("Invalid format: " + line);
            }
            Carro tx;
            tx.txid = string(fields[0]);
            tx.date = parseDate(string(fields[1]));
            try
            {
                tx.category = stringToCategory(string(fields[2]));
            }
            catch (const invalid_argument &e)
            {
                throw runtime_error("Invalid category in line " + to_string(lineNumber) + ": " + e.what());
            }
            tx.amount = stod(string(fields[3]));
            tx.store = string(fields[4]);
            carros.push_back(tx);
        }
    }
}

// filtrar por fechas
vector<Carro> Analyzer::filtrarRangoFechas(const year_month_day &inicio, const year_month_day &fin)
{
    vector<Carro> resultado;

    for (const auto &tx : carros)
    {
        if (tx.year >= inicio && tx.year <= fin)
        {
            resultado.push_back(tx);
        }
    }

    return resultado;
}

// mostrar todos
void Analyzer::printAll()
{
    for (const auto &tx : carros)
    {
        cout << tx << endl;
    }
}

// top carros con bajos kilometrajes (FALTA)
void Analyzer::lowestMileage()
{
}

// quiz carro ideal (FALTA)
void Analyzer::idealCarQuiz()
{
}

#endif // Analyzer_h