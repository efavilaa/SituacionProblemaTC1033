#include <string_view>
#include <vector>
using namespace std;    


vector<string_view> splitCommas(string_view linea) {
    vector<string_view> cols;
    size_t i = 0;

    while (i < linea.size()) {
        while (i < linea.size() && linea[i] == ',')
            i++;

        if (i >= linea.size()) break;

        size_t fin = linea.find(',', i);
        if (fin == string_view::npos) {
            cols.push_back(linea.substr(i));
            break;
        }

        cols.push_back(linea.substr(i, fin - i));
        i = fin + 1;
    }
    return cols;
}