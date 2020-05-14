/*** https://mindcoding.ro/pb/registrationplates ***/

#include <iostream>
#include <string>

using namespace std;

bool isCountyValid(string county) {
    int countyLength = county.length();

    if (countyLength > 2) return false;

    if (countyLength == 1 && county != "B") {
        return false;
    }

    for (char const& c : county) {
        if (!isalpha(c) || islower(c)) return false;
    }

    return true;
}

bool isNumbersValid(string numbers, string county) {
    bool isBucharest = county == "B";
    int numbersLength = numbers.length();

    if (!(numbersLength == 2 || (isBucharest && numbersLength == 3))) return false;

    for (char const& c : numbers) {
        if (!isdigit(c)) return false;
    }

    return true;
}

bool isLettersValid(string letters) {
    int lettersLength = letters.length();

    if (lettersLength != 3) return false;

    for (char const& c : letters) {
        if (!isalpha(c) || islower(c)) return false;
    }

    return true;
}

int main()
{
    int N = 0;
    cin >> N;
    cin.ignore();

    string* rows = new string[N];
    string** plates = new string * [N];
    for (int i = 0; i < N; i++) {
        plates[i] = new string[3];
    }

    bool* valid = new bool[N];
    for (int i = 0; i < N; i++) {
        getline(cin, rows[i]);
        valid[i] = true;
    }

    for (int i = 0; i < N; i++) {
        string currentWord;
        int wordIndex = 0;

        for (auto c : rows[i]) {
            if (c == ' ') {
                if (wordIndex <= 2)
                    plates[i][wordIndex] = currentWord;
                else if (currentWord != "") valid[i] = false;

                wordIndex++;
                currentWord.erase();
            }
            else {
                currentWord += c;
            }
        }

        if (wordIndex <= 2)
            plates[i][wordIndex] = currentWord;
        else if (currentWord != "") valid[i] = false;
    }

    for (int i = 0; i < N; i++) {
        if (!valid[i]) continue;

        string county = plates[i][0];
        string numbers = plates[i][1];
        string letters = plates[i][2];

        if (!isCountyValid(county)) {
            valid[i] = false;
            continue;
        }

        if (!isNumbersValid(numbers, county)) {
            valid[i] = false;
            continue;
        }

        if (!isLettersValid(letters)) {
            valid[i] = false;
            continue;
        }
    }

    for (int i = 0; i < N; i++) {
        string message = valid[i] ? "Correct!" : "Incorrect!";
        cout << message;
        if (i < N - 1) cout << endl;
    }

    return 0;
}