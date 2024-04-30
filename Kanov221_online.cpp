#include <iostream>
#include <cmath>

class Trapezoid {
private:
    double x1, y1, x2, y2, x3, y3, x4, y4;
public:
    Trapezoid(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4)
        : x1(x1), y1(y1), x2(x2), y2(y2), x3(x3), y3(y3), x4(x4), y4(y4) {} // конструктор

    // проверка на равнобочную трапецию
    bool isIsoscelesTrapezoid() {
        double side1 = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
        double side2 = sqrt(pow(x4 - x3, 2) + pow(y4 - y3, 2));

        return side1 == side2;
    }

    // площадь трапеции
    double calculateArea() {
        double base1 = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
        double base2 = sqrt(pow(x4 - x3, 2) + pow(y4 - y3, 2));
        double height = abs(y2 - y1);

        return (base1 + base2) * height / 2;
    }
};

int main() {
    int N;
    std::cout << "Введите количество трапеций N: ";
    std::cin >> N;

    double totalArea = 0.0;
    double averageArea;
    int count = 0;

    // создание и подсчет общей площади трапец
    for (int i = 0; i < N; ++i) {
        double x1, y1, x2, y2, x3, y3, x4, y4;

        std::cout << "Введите координаты 4 точек для трапеции " << i + 1 << ": ";
        std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;

        Trapezoid trapezoid(x1, y1, x2, y2, x3, y3, x4, y4);
        totalArea += trapezoid.calculateArea();
    }

    averageArea = totalArea / N;

    // колво трапеций с площадью больше средней
    for (int i = 0; i < N; ++i) {
        double x1, y1, x2, y2, x3, y3, x4, y4;

        std::cout << "Введите координаты 4 точек для трапеции " << i + 1 << ": ";
        std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;

        Trapezoid trapezoid(x1, y1, x2, y2, x3, y3, x4, y4);
        if (trapezoid.calculateArea() > averageArea) {
            count++;
        }
    }

    std::cout << "Количество трапеций с площадью больше средней площади: " << count << std::endl;

    return 0;
}
