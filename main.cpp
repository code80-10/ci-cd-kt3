#include "PriceCalculator.h"

#include <iostream>
#include <stdexcept>
#include <string>

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cerr << "Использование: " << argv[0] << " <цена> <количество>\n";
        return 1;
    }

    try {
        std::size_t pricePos = 0;
        std::size_t quantityPos = 0;
        const std::string priceText = argv[1];
        const std::string quantityText = argv[2];
        const double price = std::stod(priceText, &pricePos);
        const int quantity = std::stoi(quantityText, &quantityPos);

        if (pricePos != priceText.size() || quantityPos != quantityText.size() ||
            price < 0 || quantity <= 0) {
            throw std::invalid_argument("invalid value");
        }

        PriceCalculator calculator;
        std::cout << "Итоговая стоимость: "
                  << calculator.calculate(price, quantity) << '\n';
    } catch (const std::exception&) {
        std::cerr << "Ошибка: цена должна быть неотрицательным числом, "
                     "а количество — положительным целым числом.\n";
        return 1;
    }

    return 0;
}
