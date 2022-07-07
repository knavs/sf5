#ifndef SNACK_H
#define SNACK_H
#include <string>
#include <iostream>

/**
 * @brief The Snack class
 */
const double BASE_SNACK_PRICE = 10.0;

class Snack {
public:
    Snack();
    Snack(const Snack&);
    Snack(const std::string&, double=BASE_SNACK_PRICE, double=0.0);
    ~Snack();

    std::string getName();
    double getPrice();
    double getCalories();
    void setName(const std::string&);
    void setPrice(double);
    void setCalories(double);

private:
    std::string name;
    double price;
    double calories;
};

#endif // SNACK_H