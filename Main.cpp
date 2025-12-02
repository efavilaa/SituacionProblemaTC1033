#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <filesystem>
#include "Transaction.h"
#include "Category.h"
#include "Analyzer.h"

using namespace std;
int main()
{
    Analyzer analyzer;

    try
    {
        analyzer.loadData();
    }
    catch (const exception &e)
    {
        cerr << "Error: " << e.what() << endl;
        return 1;
    }

    int opcion;

    do
    {
        cout << "\n--- MENU ---\n"
             << endl;
        cout << "  ______\n"
             << " /|_||_ |.__\n"
             << "(   _    _ _|\n"
             << "=`-(_)--(_)- \n";
        cout << "1. Mostrar todos los carros\n";
        cout << "2. Filtrar carros por fechas\n";
        cout << "3. Carros con bajos kilometrajes\n";
        cout << "4. Quiz de carro ideal\n";
        cout << "0. Salir\n";
        cout << "Opcion: ";
        cin >> opcion;

        if (opcion == 1)
        {
            analyzer.printTransactions();
        }
        else if (opcion == 2)
        {
            string ini, fin;
            cout << "Start date (YYYY): ";
            cin >> ini;
            cout << "End date (YYYY): ";
            cin >> fin;
            try
            {
                auto y1 = analyzer.parseDate(ini);
                auto y2 = analyzer.parseDate(fin);

                auto filtradas = analyzer.filtrarRangoFechas(y1, y2);

                for (auto &tx : filtradas)
                {
                    cout << tx << endl;
                }
            }
            catch (const exception &e)
            {
                cerr << "Error al filtrar: " << e.what() << endl;
            }
        }
        else if (opcion == 3)
        {
            analyzer.getTopDay();
            analyzer.getTopStore();
            analyzer.getTopCategory();
        }
        else if (opcion == 4)
        {
            // aqui va el metodo para el quiz
        }
    } while (opcion != 0);

    return 0;
}