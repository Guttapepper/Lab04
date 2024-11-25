#include <iostream>
#include <cmath> 

using namespace std;

void task1();

void task2();

void task3();

int main()
{
    int menu;
    cout << "\nEnter task number: ";
    cin >> menu;
    switch (menu)
    {
        case 1 : task1(); break; //1st Task

        case 2 : task2(); break; //2st Task

        case 3 : task3(); break; //3st Task

        default : cout << "\nUnknown operation!"; 

    } 

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

    // Перевірка на діапазон
    if (k < 0 || k > 999) 
    {
        cout << "Please enter a number from 0 to 999." << endl;
        return;  // Завершення функції, якщо введене число не відповідає діапазону
    }

        // Виклик процедури DigitCountSum
        DigitCountSum(k, c, s);

        // Виведення кількості цифр і суми цифр
        cout << "Number of digits (C): " << c << endl;
        cout << "Sum of digits (S): " << s << endl << endl;
        
    }


}

/*Task2: Boolean29. Дано числа x, y, x1, y1, x2, y2. Перевірити істинність висловлювання: «Точка з
координатами (x, y) лежить усередині прямокутника, ліва верхня вершина
якого має координати (x1, y1), права нижня - (x2, y2), а сторони паралельні
координатним осях».*/

int input_coordinates(float &x1, float &y1, float &x2, float &y2, float &x, float &y)
{
    cout << "Left top coordinates (x1, y1): ";
    cin >> x1 >> y1;
    if(!cin) return 1; //failed
    cout << "Right bottom coordinates (x2, y2): ";
    cin >> x2 >> y2;
    if(!cin) return 2; //failed
    else if (x1>=x2 || y1<=y2) return 4; //wrong rectangle
    cout << "Point coordinates (x1, y1): ";
    cin >> x >> y;
    if (!cin) return 3; //failed
    else return 0; //correct
    

}

//true/fals
bool is_in_rectangle(float x1, float y1, float x2, float y2, float x, float y)
{
    return x > x1 && x < x2 && y > y2 && y < y1;
}

//console putput
void output_result (bool res)
{
    cout << "A point with coordinates (x, y) lies inside a rectangle \n";
    cout << "the top left vertex (x1, y), the bottom right - (x2, y2),\n";
    cout << "and the sides are parallel to the coordinate axes : ";
    cout << boolalpha << res << endl;
}

void task2()
{
float x, y, x1, y1, x2, y2;
cout << "\n________Tab2, Task 29________" << endl << endl;

    //Input
    if(input_coordinates(x1, y1, x2, y2, x, y) !=0 )
       cout << "Error Input! ";
    else 
    {
    //Output
    output_result(is_in_rectangle(x1, y1, x2, y2, x, y));

    }   
}

//Task3: Integer11. Дано тризначне число. Знайти суму і добуток його цифр.

// Функція для введення числа та перевірки його валідності
int input_number(int &a) 
{
    cout << "Enter a three-digit number: ";
    cin >> a;

    if (!cin) 
    {
        return 1; // Помилка введення
    }
    if (a < 100 || a > 999) 
    {
        return 2; // Число не тризначне
    }
    else return 0; // Введення коректне
}

void calculateSumAndProduct(int a, int &sum, int &mult)
{
    sum = a % 10 + a / 10 % 10 + a / 100;   // Сума цифр
    mult = (a % 10) * (a / 10 % 10) * (a / 100); // Добуток цифр
}

void output_results(int sum, int mult)
{
    cout << "Sum of digits = " << sum << endl;
    cout << "Product of digits = " << mult << endl;
}

void task3()
{
    int a, sum, mult; // Declaration
    cout << "\n________Task 3________" << endl << endl;

    // Введення значення
    int input_status = input_number(a);

    // Обробка результату введення
    if (input_status == 1) 
    {
        cout << "Error: Invalid input. Please enter a number!" << endl;
        return;
    } 
    else if (input_status == 2) 
    {
        cout << "Error: The number must be a three-digit integer!" << endl;
        return;
    }

    // Обчислення
    calculateSumAndProduct(a, sum, mult);

    // Виведення результатів
    output_results(sum, mult);

}




