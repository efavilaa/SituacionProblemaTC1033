#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <filesystem>
#include "Carro.h"
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
        cout << "\n─ ⊹ ⊱꒰ MENU ꒱⊰ ⊹ ─\n"
             << endl;
        cout << "  ______\n"
             << " /|_||_ |.__\n"
             << "(   _    _ _|\n"
             << "=`-(_)--(_)- \n";
        cout << "1 ⋆ Show all cars\n";
        cout << "2 ⋆ Filter cars by dates\n";
        cout << "3 ⋆ Show cars with low mileage\n";
        cout << "4 ⋆ Ideal car quiz\n";
        cout << "0 ⋆ Exit\n";
        cout << "Option: ";

        cin >> opcion;

        if (opcion == 1)
        {
            cout << "All cars\n" << "· · ─ ·ʚɞ· ─ · ·" << endl;
        }
        else if (opcion == 2)
        {
            cout << "Cars by dates\n" << "· · ─ ·ʚɞ· ─ · ·" << endl;
        }
        else if (opcion == 3)
        {
            cout << "Cars with low mileage\n" << "· · ─ ·ʚɞ· ─ · ·" << endl;
        }
        else if (opcion == 4)
        {
            cout << "Ideal car quiz\n" << "· · ─ ·ʚɞ· ─ · ·" << endl;
        }
    } while (opcion != 0);
    cout << "Bye bye! ⊹ ₊ ⟡ ⋆ .\n" << endl;
    return 0;
}