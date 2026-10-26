#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> split_words(const string& text) {
    vector<string> rijeci;
    int pocetak = 0;

    while (pocetak < text.size()) {
        while (pocetak < text.size() && text[pocetak] == ' ') {
            pocetak++;
        }

        if (pocetak == text.size()) {
            break;
        }

        int kraj = text.find(' ', pocetak);

        if (kraj == string::npos) {
            kraj = text.size();
        }

        rijeci.push_back(text.substr(pocetak, kraj - pocetak));
        pocetak = kraj;
    }

    return rijeci;
}

int main() {
    string text;

    cout << "Unesi recenicu: ";
    getline(cin, text);

    vector<string> rijeci = split_words(text);

    cout << "Broj rijeci: " << rijeci.size() << endl;

    if (rijeci.size() > 0) {
        string najdulja = rijeci[0];
        string prva = rijeci[0];

        for (int i = 1; i < rijeci.size(); i++) {
            if (rijeci[i].size() > najdulja.size()) {
                najdulja = rijeci[i];
            }

            if (rijeci[i] < prva) {
                prva = rijeci[i];
            }
        }

        cout << "Najdulja: " << najdulja << endl;

        string obrnuto = "";

        for (int i = rijeci.size() - 1; i >= 0; i--) {
            obrnuto += rijeci[i];

            if (i > 0) {
                obrnuto += "-";
            }
        }

        cout << obrnuto << endl;
        cout << "Prva po abecedi: " << prva << endl;
    }

    return 0;
}