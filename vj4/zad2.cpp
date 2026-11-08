
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct Song {
    string title;
    string artist;
    int year;
    int plays;
};

void print_song(const Song& s) {
    cout << "Naslov: " << s.title << endl;
    cout << "Izvodac: " << s.artist << endl;
    cout << "Godina: " << s.year << endl;
    cout << "Broj slusanja: " << s.plays << endl;
    cout << endl;
}

int main() {

    vector<Song> pjesme = {
        {"Bohemian Rhapsody", "Queen", 1975, 500000},
        {"Billie Jean", "Michael Jackson", 1982, 800000},
        {"Imagine", "John Lennon", 1971, 600000},
        {"Another One Bites the Dust", "Queen", 1980, 400000},
        {"Thriller", "Michael Jackson", 1982, 900000},
        {"Hey Jude", "The Beatles", 1968, 700000}
    };

    sort(pjesme.begin(), pjesme.end(),
        [](const Song& a, const Song& b) {
            if (a.year == b.year)
            return a.title < b.title;

    return a.year < b.year;
        });

    cout << "Sortirane pjesme:" << endl;

    for (int i = 0; i < pjesme.size(); i++) {
        print_song(pjesme[i]);
    }

    string ime;
    cout << "Unesite ime izvodaca: ";
    getline(cin, ime);

    int broj = 0;
    int najstarija = -1;

    for (int i = 0; i < pjesme.size(); i++) {

        if (pjesme[i].artist == ime) {

            broj++;

            if (najstarija == -1 ||
                pjesme[i].year < pjesme[najstarija].year) {

                najstarija = i;
            }
        }
    }

    if (broj > 0) {
        cout << "\nBroj pjesama izvodaca " << ime
            << ": " << broj << endl;

        cout << "\nNajstarija pjesma:" << endl;
        print_song(pjesme[najstarija]);
    }
    else {
        cout << "Nema pjesama tog izvodaca na popisu." << endl;
    }

    int najslusanija = 0;

    for (int i = 1; i < pjesme.size(); i++) {

        if (pjesme[i].plays > pjesme[najslusanija].plays) {
            najslusanija = i;
        }
    }

    cout << "\nNajs lusanija pjesma:" << endl;
    print_song(pjesme[najslusanija]);

    return 0;
}
