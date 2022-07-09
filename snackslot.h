#ifndef SNACKSLOT_H
#define SNACKSLOT_H
#include <iostream>
#include <sstream>
#include <iomanip>
#include "snack.h"

class SnackSlot {
public:
    SnackSlot(int);
    void addSnack(Snack*);
    void buySnack(Snack*);
    void buySnack(int);
    Snack* getSnack(int);
    std::string getSnackNameAt(int position) const;
    void setSnack(int, Snack*);
    Snack*& at(int index);
    Snack*& operator[](int index);
    friend std::ostream& operator<<(std::ostream&, const SnackSlot*);
    ~SnackSlot();
private:
    void _allocate_container(int, bool);
    void _reallocate_container();
    std::string getFormatedPriceAt(int) const;
    int snack_count;
    int slot_capacity;
    Snack **container;
};

#endif // SNACKSLOT_H
