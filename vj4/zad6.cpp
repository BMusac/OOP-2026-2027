
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cctype>
using namespace std;

vector<string> split_words(const string& text) {

    vector<string> rijeci;

    int pocetak = 0;

    while (pocetak < text.size()) {

        while (pocetak < text.size() && text[pocetak] == ' ')
            pocetak++;

        int kraj = text.find(' ', pocetak);

        if (kraj == string::npos)
            kraj = text.size();

        if (pocetak < text.size()) {
            rijeci.push_back(text.substr(pocetak, kraj - pocetak));
        }

        pocetak = kraj + 1;
    }

    return rijeci;
}

int main() {

    vector<string> rjecnik = {
        "programski", "jezik", "c++", "je", "brz", "i",
        "mocan", "ali", "nije", "jednostavan", "za", "pocetnike"
    };

    sort(rjecnik.begin(), rjecnik.end());

    string recenica;

    cout << "Unesite recenicu: ";
    getline(cin, recenica);

    vector<string> rijeci = split_words(recenica);

    vector<string> nepoznate;

    for (int i = 0; i < rijeci.size(); i++) {

        rijeci[i].erase(
            remove_if(rijeci[i].begin(), rijeci[i].end(),
                [](char c) {
                    return c == ',' || c == '.';
                }),
            rijeci[i].end()
                    );

        for (int j = 0; j < rijeci[i].size(); j++) {
            rijeci[i][j] = tolower((unsigned char)rijeci[i][j]);
        }

        if (!binary_search(rjecnik.begin(), rjecnik.end(), rijeci[i])) {
            nepoznate.push_back(rijeci[i]);
        }
    }

    cout << "Nepoznatih rijeci: " << nepoznate.size() << endl;

    for (int i = 0; i < nepoznate.size(); i++) {
        cout << nepoznate[i] << " ";
    }

    cout << endl;

    return 0;
}
