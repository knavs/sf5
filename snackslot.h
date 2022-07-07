#ifndef SNACKSLOT_H
#define SNACKSLOT_H
#include <iostream>
#include "snack.h"

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
    void _allocate_container(int, bool);
    void _reallocate_container();
    std::string getFormatedPriceAt(int) const;
    int snack_count;
    int slot_capacity;
    Snack **container;
};

#endif // SNACKSLOT_H
