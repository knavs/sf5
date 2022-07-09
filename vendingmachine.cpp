#include "vendingmachine.h"

/**
 *
 * @class VendingMachine
 *
 */

VendingMachine::VendingMachine(int slotCount) {
    this->machine_capacity = slotCount;
    this->slot_count = 0;
    this->slots = new SnackSlot*[slotCount];
}


VendingMachine::~VendingMachine() {
    delete [] slots;
}


int VendingMachine::getEmptySlotsCount() const {
    return machine_capacity - slot_count;
}


bool VendingMachine::isEmptySlot(const int& position) const {
    return position < slot_count;
}


void VendingMachine::addSlot(SnackSlot *slot) {
    if (getEmptySlotsCount() >= 1) {
        this->slots[slot_count] = slot;
        this->slot_count++;
    } else {
        std::cout << "no space available. sorry"; // ничего не делаемы
    }
}



/**
 *
 * @brief перегрузка операторов вывода в консоль
 *
 */


std::ostream& operator<<(std::ostream& ostr, const VendingMachine *rhs) {
    ostr << "VendingMachine :=" << std::endl << "  Slots (" << rhs->machine_capacity <<") {\n";
    for (int i = 0; i < rhs->machine_capacity; i++) {
        ostr << "\t"
             << i
             << ": ";
        if (rhs->isEmptySlot(i))
            ostr << rhs->slots[i] << std::endl;
        else
            ostr << "free" << std::endl;
    }
    ostr << "  }" <<std::endl;
    return ostr;
}

