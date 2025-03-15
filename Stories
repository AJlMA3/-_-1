#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <fstream>

using namespace std;

int getRandomIndex(int size) {
    return rand() % size;
}

string generateStory(const vector<string>& heroes, const vector<string>& places,
    const vector<string>& actions, const vector<string>& details) {
    int heroIndex = getRandomIndex(heroes.size());
    int placeIndex = getRandomIndex(places.size());
    int actionIndex = getRandomIndex(actions.size());
    int detailIndex = getRandomIndex(details.size());

    return heroes[heroIndex] + " " + places[placeIndex] + ", " + actions[actionIndex] + " " + details[detailIndex] + ".";
}

// Функция для сохранения истории в файл
void saveStory(const string& story) {
    setlocale(LC_ALL, "Russian");
    ofstream outFile("stories.txt", ios::app);
    if (outFile.is_open()) {
        outFile << story << "\n";
        outFile.close();
        cout << "История сохранена в файл stories.txt" << endl;
    }
    else {
        cout << "Ошибка открытия файла для записи!" << endl;
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    srand(static_cast<unsigned int>(time(nullptr))); // Инициализация генератора случайных чисел

    vector<string> heroes = { "смелый рыцарь", "хитрый вор", "волшебник", "отважный пират", "дерзкий исследователь" };
    vector<string> places = { "в далёком королевстве", "на заброшенной фабрике", "в густом лесу", "на просторах космоса", "у подножия гор" };
    vector<string> actions = { "победил дракона", "обнаружил сокровища", "выиграл битву", "устроил бал", "раскрыл древнюю тайну" };
    vector<string> details = { "с волшебным мечом", "на летающем ковре", "под звуки волшебной музыки", "с удивительной силой", "в сопровождении магического существа" };

    char playAgain;
    do {
        string story = generateStory(heroes, places, actions, details);
        cout << "\nСгенерированная история:\n" << story << endl;

        char saveChoice;
        cout << "\nСохранить историю в файл (Y/N)? ";
        cin >> saveChoice;
        if (saveChoice == 'Y' || saveChoice == 'y') {
            saveStory(story);
        }

        cout << "\nСгенерировать новую историю? (Y/N): ";
        cin >> playAgain;
    } while (playAgain == 'Y' || playAgain == 'y');

    cout << "\nСпасибо за игру!" << endl;
    return 0;
}
