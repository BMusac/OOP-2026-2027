
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool starts_with(const string& s, const string& prefix) {
    if (prefix.size() > s.size())
        return false;

    return equal(prefix.begin(), prefix.end(), s.begin());
}

bool ends_with(const string& s, const string& suffix) {
    if (suffix.size() > s.size())
        return false;

    return equal(suffix.rbegin(), suffix.rend(), s.rbegin());
}

int main() {

    vector<string> datoteke = {
        "vjezba04.cpp",
        "slajdovi.pdf",
        "main.cpp",
        "README.md",
        "vjezba04.h",
        "notes.txt",
        "vjezba03.cpp"
    };

    int broj = 0;

    for (int i = 0; i < datoteke.size(); i++) {
        if (ends_with(datoteke[i], ".cpp")) {
            broj++;
        }
    }

    cout << ".cpp datoteka: " << broj << endl;

    datoteke.erase(
        remove_if(datoteke.begin(), datoteke.end(),
            [](const string& s) {
                return starts_with(s, "vjezba");
            }),
        datoteke.end()
                );

    for (int i = 0; i < datoteke.size(); i++) {
        cout << datoteke[i] << " ";
    }

    cout << endl;

    return 0;
}
