#include <iostream>
#include <string>
using namespace std;

bool split_email(const string& email, string& user, string& domain) {
    int pozicija = email.find('@');

    if (pozicija == string::npos) {
        return false;
    }

    if (email.find('@') != email.rfind('@')) {
        return false;
    }

    if (pozicija == 0 || pozicija == email.size() - 1) {
        return false;
    }

    user = email.substr(0, pozicija);
    domain = email.substr(pozicija + 1);

    if (domain.find('.') == string::npos) {
        return false;
    }

    return true;
}

int main() {
    string email, user, domain;

    cout << "Unesi email adresu: ";
    getline(cin, email);

    if (split_email(email, user, domain)) {
        cout << "Korisnik: " << user << endl;
        cout << "Domena: " << domain << endl;
    }
    else {
        cout << "Neispravna adresa" << endl;
    }

    return 0;
}