#include "PriceCalculator.h"

double PriceCalculator::calculate(double price, int quantity) const {
    const double total = price * quantity;
    return quantity >= 5 ? total * 0.9 : total;
}
