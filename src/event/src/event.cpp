#include "../header/event.h"
#include <stdexcept>

using namespace Coruh::Event;

double Event::add(double a, double b) {
    return a + b;
}

double Event::subtract(double a, double b) {
    return a - b;
}

double Event::multiply(double a, double b) {
    return a * b;
}

double Event::divide(double a, double b) {
    if (b == 0) {
        throw std::invalid_argument("Division by zero is not allowed.");
    }
    return a / b;
}