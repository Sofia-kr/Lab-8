#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    setlocale(LC_ALL, "Ukrainian");

    vector<int> arr = { 2, -3, 1, 4, -5, 0, 1, -2, 3, 6 };

    int sum = 0;
    for (size_t i = 1; i < arr.size(); i += 2) {
        sum += arr[i];
    }
    cout << "Сума елементів з непарними номерами: " << sum << endl;

    // Сума елементів між першим і останнім від’ємними елементами
    auto first_negative = find_if(arr.begin(), arr.end(), [](int x) { return x < 0; });
    auto last_negative = find_if(arr.rbegin(), arr.rend(), [](int x) { return x < 0; }).base();

    int sum_between = 0;
    if (first_negative != arr.end() && last_negative != arr.begin() && first_negative < last_negative) {
        for (auto it = first_negative + 1; it < last_negative - 1; ++it) {
            sum_between += *it;
        }
    }
    cout << "Сума елементів між першим і останнім від’ємними елементами: " << sum_between << endl;

    // Стиснення масиву: видалення елементів, модуль яких не перевищує 1
    arr.erase(remove_if(arr.begin(), arr.end(), [](int x) { return abs(x) <= 1; }), arr.end());

    // Заповнення решти місць нулями
    size_t new_size = arr.size();
    arr.resize(10, 0); // Масив збільшується до початкового розміру (10)

    cout << "Стиснутий масив: ";
    for (size_t i = 0; i < arr.size(); ++i) {
        if (i < new_size)
            cout << arr[i] << " ";
        else
            cout << 0 << " ";
    }
    cout << endl;

    return 0;
}
