#include <iostream>
#include<cstdlib>

using namespace std;

void castigado();
bool Guess(int secretNumber, int guessNumber, int attempts);
void GuessMyNumberMenu();
bool GuessMyNumberGame(int minR, int maxR);

int main()
{
    int op = 0;
    char confirm = ' ';
    string lectureTime = " ";
    srand(static_cast<unsigned int>(time(0)));

    while (op != 2)
    {
        system("cls");
        cout << " MENU " << endl;
        cout << "1) Jugar" << endl;
        cout << "2) Salir" << endl;
        cin >> op;
        switch (op)
        {
        case 1:
            GuessMyNumberMenu();
            break;
        case 2:
            confirm = ' ';
            while (confirm == ' ')
            {
                system("cls");
                cout << "Esta seguro de querer salir?" << endl;
                cout << "(s/n)" << endl;
                cin >> confirm;
                if (confirm == 's')
                {
                    cout << "Adios" << endl;
                }
                else if (confirm == 'n')
                {
                    op = 0;
                }
                else
                {
                    confirm = ' ';
                    system("cls");
                    cout << "Porfavor, ponga una opcion valida (s o n)" << endl;
                    castigado();
                }
            }
            break;
        default:
            system("cls");
            cout << "Porfavor, ponga una opcion valida (1 o 2)" << endl;
            castigado();
            break;
        }
    }
    

}

void castigado()
{
    string lectureTime = " ";
    cout << "(Escriba cualquier cosa para continuar)" << endl;
    cin >> lectureTime;
}

bool Guess(int secretNumber, int guessNumber, int attempts)
{
    int diff = 0;
    int win = false;
    system("cls");
    if (guessNumber == secretNumber)
    {
        if (attempts == 1)
        {
            cout << "Wow!, has adivinado el numero en tu primer intento!, espero que no hayas hecho trampa" << endl;
        }
        else if (attempts <= 5)
        {
            cout << "Felicidades!, adivinaste el numero bastante rapido, (solo " << attempts << " intentos)" << endl;
        }
        else if (attempts <= 10)
        {
            cout << "Le atinaste!, y lo hiciste en " << attempts << " intentos" << endl;
        }
        else
        {
            cout << "Al fin!, tardaste " << attempts << " intentos en atinarle" << endl;
        }
        win = true;
    }
    else
    {
        diff = secretNumber - guessNumber;
        if (diff <= 5 && diff >= -5)
        {
            cout << "Su numero esta cerca, pero aun esta ";
        }
        if (guessNumber > secretNumber) {
            cout << "muy alto" << endl;
        }
        else if (guessNumber < secretNumber) {
            cout << "muy bajo" << endl;
        }
    }

    return win;
}

bool GuessMyNumberGame(int minR, int maxR)
{
    bool replay = false;
    char confirm = ' ';
    bool win = false;
    int attempts = 0;
    int guessNumber = 0;
    int randomNumber = rand();
    int secretNumber = (randomNumber % maxR) + 1;
    while (secretNumber < minR)
    {
        randomNumber = rand();
        secretNumber = (randomNumber % maxR) + 1;
    }
    system("cls");
    cout << "Todo listo!" << endl;
    cout << "(su numero es " << secretNumber << ", por si quiere hacer trampa)" << endl;
    cout << "\nHaga su primer intento" << endl;
    cin >> guessNumber;
    attempts = attempts + 1;
    win = Guess(secretNumber, guessNumber, attempts);
    while (win == false)
    {
        cout << "\nSiga intentando:" << endl;
        cin >> guessNumber;
        attempts = attempts + 1;
        win = Guess(secretNumber, guessNumber, attempts);
    }
    while (confirm == ' ')
    {
        cout << "Quiere volver a jugar? (s/n)" << endl;
        cin >> confirm;
        if (confirm == 's')
        {
            replay = true;
        }
        else if (confirm == 'n')
        {
            replay = false;
        }
        else
        {
            confirm = ' ';
            system("cls");
            cout << "Porfavor, ponga una opcion valida (s o n)" << endl;
            castigado();
        }
    }

    return replay;
}

void GuessMyNumberMenu()
{
    bool replay = true;
    while (replay == true)
    {
        int minR = 0;
        int maxR = 0;
        while (minR == 0 && maxR == 0)
        {
            system("cls");
            cout << "Bienvenido al juego de Adivinar El Numero!" << endl;
            cout << "Antes de empezar, necesito que me des el rango para el numero aleatorio" << endl;
            cout << "\nEmpezemos con el rango minimo:" << endl;
            cin >> minR;
            cout << "Ahora el rango maximo" << endl;
            cin >> maxR;
            if (minR >= maxR)
            {
                system("cls");
                cout << "Lo siento, pero esto es inaceptable" << endl;
                cout << "Porfavor asegurate de que el rango maximo sea mayor al minimo" << endl;
                minR = 0;
                maxR = 0;
                castigado();
            }
            else
            {
                replay = GuessMyNumberGame(minR, maxR);
            }
        }
    }
    
}

