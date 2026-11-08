
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Song {
public:
    string title;
    string artist;
    int seconds;
};

class Album {
private:
    string title;
    int year;
    vector<Song> songs;

public:

    Album(string t, int y, Song first)
        : title(t), year(y) {
        songs.push_back(first);
    }

    bool add(Song s) {

        for (int i = 0; i < songs.size(); i++) {

            if (songs[i].title == s.title) {
                return false;
            }
        }

        songs.push_back(s);
        return true;
    }

    int duration() const {

        int ukupno = 0;

        for (int i = 0; i < songs.size(); i++) {
            ukupno += songs[i].seconds;
        }

        return ukupno;
    }

    void print() const {

        cout << title << " (" << year << ")" << endl;

        for (int i = 0; i < songs.size(); i++) {

            cout << i + 1 << ". "
                << songs[i].title << " - "
                << songs[i].artist << " ("
                << songs[i].seconds << " s)" << endl;
        }

        cout << "Ukupno trajanje: " << duration() << " s" << endl;
    }
};

int main() {

    Song s1 = { "Bohemian Rhapsody", "Queen", 354 };
    Song s2 = { "Don't Stop Me Now", "Queen", 210 };
    Song s3 = { "We Will Rock You", "Queen", 122 };
    Song s4 = { "Bohemian Rhapsody", "Queen", 354 };

    Album a("A Night at the Opera", 1975, s1);

    a.add(s2);
    a.add(s3);

    if (!a.add(s4)) {
        cout << "Pjesma vec postoji!" << endl;
    }

    cout << endl;
    a.print();

    return 0;
}
