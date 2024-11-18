#include <iostream>
#include <cmath> 

using namespace std;

void task1();

void task2();

void task3();

int main()
{
    /*int menu;
    cout << "\nEnter task number: ";
    cin >> menu;
    switch (menu)
    {
        case 1 : task1(); break; //1st Task

        case 2 : task2(); break; //2st Task

        case 3 : task3(); break; //3st Task

        default : cout << "\nUnknown operation!"; 

    } */

    task1();
    return 0;

}

/* Proc6. Описати процедуру DigitCountSum (K, C, S), що знаходить кількість C
цифр цілого додатного числа K, а також їх суму S (K - вхідний, C і S -
вихідні параметри цілого типу). */



void DigitCountSum (int K, int &C, int &S)
{
    C = 0; // Ініціалізація кількості цифр
    S = 0; // Ініціалізація суми цифр

    while (K > 0) 
    {
        S += K % 10; // Додаємо останню цифру до суми
        K /= 10;     // Видаляємо останню цифру
        C++;         // Збільшуємо лічильник цифр
    }


}

/*За допомогою цієї процедури знайти
кількість і суму цифр для кожного з п'яти даних цілих чисел. */

void task1()
{
    // перевірка К від 0 до 999
    // виклик функції DigitCountSum (k, c, s);
    // output c & s
    // repeat 5 times

    cout << "\n________Task 1 (Proc6)________" << endl << endl;

    int k, c, s;
    for (int i = 0; i < 5; i++)
    {
        cout << "Enter a positive integer (0 to 999): ";
        cin >> k;

        // Перевірка на валідність введення
        if (k < 0 || k > 999)
        {
            cout << "Please enter a number from 0 to 999." << endl;
            i--; // Повертаємо ітерацію, щоб повторити запит на введення
            continue;
        }

        // Виклик процедури DigitCountSum
        DigitCountSum(k, c, s);

        // Виведення кількості цифр і суми цифр
        cout << "Number of digits (C): " << c << endl;
        cout << "Sum of digits (S): " << s << endl << endl;
        
    }


}



