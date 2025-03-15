#include <iostream>
#include <random>

using namespace std;

void playGame() {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distrib(1, 100);
    int secretNumber = distrib(gen);
    int attempts = 0;
    int guess;
    
    cout << "Добро пожаловать в игру 'Угадай число'!" << endl;
    cout << "Я загадал число от 1 до 100. Попробуйте угадать!" << endl;
    
    while (true) {
        cout << "Введите ваше предположение: ";
        cin >> guess;
        
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Некорректный ввод. Введите число от 1 до 100." << endl;
            continue;
        }
        
        attempts++;
        
        if (guess < secretNumber) {
            cout << "Загаданное число больше." << endl;
        } else if (guess > secretNumber) {
            cout << "Загаданное число меньше." << endl;
        } else {
            cout << "Поздравляем! Вы угадали число " << secretNumber << " за " << attempts << " попыток!" << endl;
            break;
        }
    }
}

int main() {
    char playAgain;
    do {
        playGame();
        cout << "Хотите сыграть еще раз? (y/n): ";
        cin >> playAgain;
    } while (playAgain == 'y' || playAgain == 'Y');
    
    cout << "Спасибо за игру!" << endl;
    return 0;
}
