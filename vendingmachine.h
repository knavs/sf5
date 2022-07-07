#ifndef VENDINGMACHINE_H
#define VENDINGMACHINE_H
#include <iostream>
#include <cstdio>
#include "snack.h"
#include "snackslot.h"



class VendingMachine {
public:
    VendingMachine(int slotCount);
    int getEmptySlotsCount() const;
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
