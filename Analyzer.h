#if !defined(Analyzer_h)
#define Analyzer_h

#include <vector>
#include <fstream>
#include <string>
#include <filesystem>
#include <sstream>
#include <iomanip>
#include <vector>
#include <iostream>
#include "splitcommas.h"
#include "CategoryFood.h"
#include "CategoryGender.h"
#include "CategoryTestPreparationCourse.h"
#include "StructStudentsPerformance.h"
#include <unordered_map>
#include <functional>
#include <algorithm>
#include <stdexcept>
#include <climits>
using namespace std;

class Analyzer
{
private:
public:
    vector<StudentPerformance> students{};
    // constructor
    Analyzer() = default;
    // funcion para cargar datos
    void loadData(const filesystem::path &base = filesystem::current_path());
    /*Parte 3. Clase Analizador

    Crea una clase que contenga lo siguiente:*/

    // Búsqueda - buscar por nombre, ID o ano
    void busqueda(const string &campo, const string &valor);
    // Filtrado - por categoría, rango, condición numérica
    void filtro(const string &campo, const string &valor);
    // Estadística - promedio, mínimo, máximo, conteo
    void estadistica();
    // Reporte - top N registros por alguna métrica
    void reporte(size_t N);
    // Validación - líneas inválidas, registros incompletos
    void validacion();
};
/*
Parte 2. Procesamiento del CSV



*/
void Analyzer::loadData(const filesystem::path &base)
{
    // Deberás : 1. Leer el archivo usando std::filesystem::path

    if (!filesystem::exists(base) || !filesystem::is_regular_file(base))
    { // 2. Verificar si existe el archivo
        throw runtime_error("File no encontrado");
    }

    // 3. Abrirlo usando ifstream
    ifstream in(base);
    if (!in)
        throw runtime_error("No se puede abrir File");

    string line;
    size_t lineNumber = 0;

    while (getline(in, line))
    {
        lineNumber++;
        if (lineNumber > 1) // Reglas:
        // Debe ignorar la línea de encabezado.
        { // procesamos las lineas
            auto fields = splitCommas(line);

            // • Si alguna línea es inválida → ignorarla o registrar un error.
            if (fields.size() != 8)
            {
                std::cerr << "Línea inválida (tamaño incorrecto) en la línea "
                          << lineNumber << ": " << line << "\n";
                continue; // ← ignorar línea y seguir
            }
            // de "45" a int 45
            // Reglas: Debe manejar comillas en el CSV si existen(puede ser un reto opcional)
            int mathScore, readingScore, writingScore;
            try
            {
                mathScore = stoi(string(fields[5]));
                readingScore = stoi(string(fields[6]));
                writingScore = stoi(string(fields[7]));
            }
            catch (const exception &e)
            {
                cerr << "Línea inválida (puntajes no numéricos) en la línea "
                     << lineNumber << ": " << line << "\n";
                continue;
            }

            // 5. Convertir los tokens a los tipos del struct
            StudentPerformance student{
                stringToCategoryGender(std::string(fields[0])),
                std::string(fields[1]),
                std::string(fields[2]),
                stringToCategoryFood(std::string(fields[3])),
                stringToCategoryTestPreparationCourse(std::string(fields[4])),
                mathScore,
                readingScore,
                writingScore};
            // 6. Almacenar todos los objetos en un vector<T> interno
            students.push_back(student);
        }
    }
}

// Búsqueda - buscar por "gender","race/ethnicity","parental level of education","lunch","test preparation course","math score","reading score","writing score"
void Analyzer::busqueda(const string &campo, const string &valor)
{
    vector<StudentPerformance> output;

    // Crear los getters
    static unordered_map<string, function<string(const StudentPerformance &)>> getters = {
        {"gender", [](const StudentPerformance &s)
         { return toStringCategoryGender(s.gender); }},
        {"race/ethnicity", [](const StudentPerformance &s)
         { return s.race_ethnicity; }},
        {"parental level of education", [](const StudentPerformance &s)
         { return s.parental_education; }},
        {"lunch", [](const StudentPerformance &s)
         { return toStringCategoryFood(s.lunch); }},
        {"test preparation course", [](const StudentPerformance &s)
         { return toStringCategoryTestPreparationCourse(s.test_prep); }},
        {"math score", [](const StudentPerformance &s)
         { return to_string(s.math); }},
        {"reading score", [](const StudentPerformance &s)
         { return to_string(s.reading); }},
        {"writing score", [](const StudentPerformance &s)
         { return to_string(s.writing); }},
    };

    if (getters.find(campo) == getters.end())
    {
        throw runtime_error("Campo inválido: " + campo);
    }

    auto getter = getters[campo];

    // Buscar coincidencias
    for (const auto &s : students)
    {
        if (getter(s) == valor)
            output.push_back(s);
    }

    cout << "Coincidencias encontradas: " << output.size() << endl;

    // Imprimir resultados
    for (const auto &s : output)
        cout << s << endl;
}

// Filtrado - por categoría, rango, condición numérica
void Analyzer::filtro(const string &campo, const string &valor)
{
    static unordered_map<string, function<string(const StudentPerformance &)>> getters = {
        {"gender", [](const StudentPerformance &s)
         { return toStringCategoryGender(s.gender); }},
        {"race/ethnicity", [](const StudentPerformance &s)
         { return s.race_ethnicity; }},
        {"parental level of education", [](const StudentPerformance &s)
         { return s.parental_education; }},
        {"lunch", [](const StudentPerformance &s)
         { return toStringCategoryFood(s.lunch); }},
        {"test preparation course", [](const StudentPerformance &s)
         { return toStringCategoryTestPreparationCourse(s.test_prep); }},
        {"math score", [](const StudentPerformance &s)
         { return to_string(s.math); }},
        {"reading score", [](const StudentPerformance &s)
         { return to_string(s.reading); }},
        {"writing score", [](const StudentPerformance &s)
         { return to_string(s.writing); }},
    };

    // manejo errores
    if (!getters.count(campo))
        throw runtime_error("Categoría desconocida: " + campo);

    auto getter = getters[campo];
    vector<StudentPerformance> result;

    for (const auto &s : students)
    {
        if (getter(s) == valor)
            result.push_back(s);
    }

    // Imprimir resultados
    cout << "Registros filtrados: " << result.size() << endl;
    for (const auto &s : result)
        cout << s << endl;
}

// Estadística - promedio, mínimo, máximo, conteo
inline void Analyzer::estadistica()
{
    // error
    if (students.empty())
    {
        cout << "No hay datos cargados.\n";
        return;
    }
    // double porque al dividir puede dar decimales
    double sumMath = 0, sumReading = 0, sumWriting = 0;
    int minMath = INT_MAX, minReading = INT_MAX, minWriting = INT_MAX;
    int maxMath = INT_MIN, maxReading = INT_MIN, maxWriting = INT_MIN;

    for (const auto &s : students)
    {
        // Promedio
        sumMath += s.math;
        sumReading += s.reading;
        sumWriting += s.writing;

        // Mínimo
        minMath = min(minMath, s.math);
        minReading = min(minReading, s.reading);
        minWriting = min(minWriting, s.writing);

        // Máximo
        maxMath = max(maxMath, s.math);
        maxReading = max(maxReading, s.reading);
        maxWriting = max(maxWriting, s.writing);
    }

    size_t n = students.size();

    cout << "ESTADISTICAS\n";
    cout << "Math score: Promedio: " << (sumMath / n)
         << ", Mínimo: " << minMath << ", Máximo: " << maxMath << endl;

    cout << "Reading score: Promedio: " << (sumReading / n)
         << ", Mínimo: " << minReading << ", Máximo: " << maxReading << endl;

    cout << "Writing score: Promedio: " << (sumWriting / n)
         << ", Mínimo: " << minWriting << ", Máximo: " << maxWriting << endl;
}

// Reporte - top N registros por alguna métrica (promedios dada la base de datos)
void Analyzer::reporte(size_t N)
{
    // error
    if (students.empty())
    {
        cout << "No hay datos cargados.\n";
        return;
    }

    // ordenar por promedio de scores
    vector<StudentPerformance> sortedStudents = students;
    sort(sortedStudents.begin(), sortedStudents.end(),
         [](const StudentPerformance &a, const StudentPerformance &b)
         {
             double avgA = (a.math + a.reading + a.writing) / 3.0;
             double avgB = (b.math + b.reading + b.writing) / 3.0;
             return avgA > avgB; // orden descendente
         });

    cout << "TOP " << N << " estudiantes por promedio de scores:\n";
    for (size_t i = 0; i < min(N, sortedStudents.size()); ++i)
    {
        const auto &s = sortedStudents[i];
        double avg = (s.math + s.reading + s.writing) / 3.0;
        cout << fixed << setprecision(2);
        cout << s << ", Promedio: " << avg << endl;
    }
}
// Validación - líneas inválidas, registros incompletos
void Analyzer::validacion()
{
    cout << "Total de registros cargados: " << students.size() << endl;
    size_t index = 0;
    size_t errores = 0;

    for (const auto &s : students)
    {
        bool invalido = false;

        // CategoryGender
        if (!isValidCategoryGender(s.gender))
        {
            cout << "Registro #" << index << ": Género inválido.\n";
            invalido = true;
        }

        if (s.race_ethnicity.empty())
        {
            cout << "Registro #" << index << ": raza/etnia vacía.\n";
            invalido = true;
        }

        if (s.parental_education.empty())
        {
            cout << "Registro #" << index << ": educación parental vacía.\n";
            invalido = true;
        }

        if (!isValidCategoryFood(s.lunch))
        {
            cout << "Registro #" << index << ": lunch inválido.\n";
            invalido = true;
        }

        if (!isValidCategoryTestPreparationCourse(s.test_prep))
        {
            cout << "Registro #" << index << ": test prep inválido.\n";
            invalido = true;
        }

        // Validar scores
        if (s.math < 0 || s.math > 100 ||
            s.reading < 0 || s.reading > 100 ||
            s.writing < 0 || s.writing > 100)
        {
            cout << "Registro #" << index << ": score fuera de rango.\n";
            invalido = true;
        }

        if (invalido)
            errores++;

        index++;
    }

    if (errores == 0)
        cout << "Todos los registros son válidos.\n";
    else
        cout << "Registros inválidos encontrados: " << errores << "\n";
}

#endif // Analyzer_h
