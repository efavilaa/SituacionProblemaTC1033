#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <filesystem>

#include "Transaction.h"
#include "Category.h"
#include "Analyzer.h"

using namespace std;

int main() {
    Analyzer analyzer;

    try {
        analyzer.loadData();  
    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
        return 1;
    }

    int opcion;

    do {
        cout << "\n--- MENU ---\n";
        cout << "1. Show all cars\n";
        cout << "2. Filter cars by dates\n";
        cout << "3. Cars with low mileage\n";
        cout << "4. Ideal car quiz\n";
        cout << "0. Exit\n";
        cout << "Option: ";
        cin >> opcion;

        if (opcion == 1) {
            analyzer.printTransactions();
        }
        else if (opcion == 2) {
            string ini, fin;
            cout << "Start date (YYYY-MM-DD): ";
            cin >> ini;
            cout << "End date (YYYY-MM-DD): ";
            cin >> fin;
            try {
                auto y1 = analyzer.parseDate(ini);
                auto y2 = analyzer.parseDate(fin);

                auto filtradas = analyzer.filtrarRangoFechas(y1, y2);

                for (auto& tx : filtradas) {
                    cout << tx << endl;
                }
            }
            catch (const exception& e) {
                cerr << "Error: " << e.what() << endl;
            }
        }
        else if (opcion == 3) {
            analyzer.getTopDay();
            analyzer.getTopStore();
            analyzer.getTopCategory();
        }
        else if (opcion == 4) {
            // aqui va el metodo para el quiz
        }
    } while (opcion != 0);

    return 0;
}