#include "snack.h"


Snack::Snack() : name(std::string()), price(BASE_SNACK_PRICE), calories(0.0) {};
Snack::Snack(const Snack &other) :name(other.name), price(other.price), calories(other.price) {};
Snack::Snack(const std::string&  name, double price, double calories): name(name), price(price), calories(calories) {};
Snack::~Snack() {std::cout << "Snack~::" << name << std::endl;}

std::string Snack::getName()
{
    return name;
}

double Snack::getPrice() {
    return price;
}

double Snack::getCalories() {
    return calories;
}

void Snack::setName(const std::string& aname) {
    name = aname;
}

void Snack::setPrice(double aprice) {
    price = aprice;
}

void Snack::setCalories(double acalories) {
    calories = acalories;
}
