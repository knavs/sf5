#ifndef VENDINGMACHINE_H
#define VENDINGMACHINE_H
#include <iostream>
#include <stdio.h>
const double BASE_SNACK_PRICE = 10.0;
/**
 * @brief The Snack struct
 *й (например, у снека есть количество калорий и стоимость,
а у аппарата — функция по выдаче продукта и количество оставшихся продуктов).
В описании должно получиться хотя бы несколько классов.
При выполнении не забывайте использовать инкапсуляцию и перегрузку функций (при необходимости).
 */


struct Snack { // очень короткая структура думаю можно только в h писать?
    Snack() : name(std::string()), price(BASE_SNACK_PRICE), calories(0.0) {};
    Snack(const Snack &other) :name(other.name), price(other.price), calories(other.price) {};
    Snack(std::string name, double price = BASE_SNACK_PRICE, double calories = 0.0): name(name), price(price), calories(calories) {};

    std::string name;
    float price;
    float calories;
};


class SnackSlot {
public:
    SnackSlot(int);
    void addSnack(Snack*);
    void buySnack(Snack*);
    void buySnack(int);
    std::string getSnackAt(int) const;
    Snack*& at(int index);
    Snack*& operator[](int index);
    friend std::ostream& operator<<(std::ostream&, const SnackSlot*);
    ~SnackSlot();
private:
    std::string getFormatedPriceAt(int) const;
    int snack_count;
    int slot_capacity;
    Snack **container;
};


class VendingMachine {
public:
    VendingMachine(int slotCount);
    int getEmptySlotsCount(void) const;
    bool isEmptySlot(const int& position) const;
    void addSlot(SnackSlot *slot);
    friend std::ostream& operator<<(std::ostream& ostr, const VendingMachine *rhs);
    ~VendingMachine();
private:
    int machine_capacity;
    int slot_count;
    SnackSlot **slots;
};
#endif // VENDINGMACHINE_H
