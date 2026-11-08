
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> input_vector() {

    vector<int> v;
    int broj;

    cout << "Unesite brojeve (0 za kraj): ";

    while (cin >> broj && broj != 0) {
        v.push_back(broj);
    }

    return v;
}

int main() {

    vector<int> v = input_vector();

    int k;

    cout << "k: ";
    cin >> k;

    if (v.empty()) {
        cout << "Vektor je prazan." << endl;
        return 0;
    }

    int negativnih = count_if(v.begin(), v.end(),
        [](int x) {
            return x < 0;
        });

    cout << "Negativnih: " << negativnih << endl;

    auto prvi = find_if(v.begin(), v.end(),
        [k](int x) {
            return x % k == 0;
        });

    if (prvi != v.end()) {
        int pozicija = prvi - v.begin();

        cout << "Prvi visekratnik od " << k << ": "
            << *prvi << " (pozicija " << pozicija << ")" << endl;
    }
    else {
        cout << "Nema visekratnika broja " << k << endl;
    }

    auto min = min_element(v.begin(), v.end());
    auto max = max_element(v.begin(), v.end());

    cout << "Min " << *min << " (pozicija "
        << min - v.begin() << "), ";

    cout << "max " << *max << " (pozicija "
        << max - v.begin() << ")" << endl;

    v.erase(
        remove_if(v.begin(), v.end(),
            [k](int x) {
                return x % k == 0;
            }),
        v.end()
                );

    cout << "Bez visekratnika: ";

    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }

    cout << endl;

    return 0;
}
