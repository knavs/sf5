#include "VendingMachine.h"
/**
 *
 * @class SnakSlot
 *
 */

SnackSlot::SnackSlot(int slot_capacity) {
    SnackSlot::slot_capacity = slot_capacity;
    SnackSlot::snack_count = 0;
    SnackSlot::container = new Snack*[snack_count];
}


SnackSlot::~SnackSlot() {
    delete [] *container;
}


void SnackSlot::addSnack(Snack *snack) {
    container[snack_count] = new Snack(*snack); // delete[] container уничтожит же его??
    ++snack_count;
}

std::string SnackSlot::getFormatedPriceAt(int position) const {
    char str_buffer[6];
    // как-то не по c++
    std::sprintf(str_buffer, "%0.2f", container[position]->price);
    return  str_buffer;
}

std::string SnackSlot::getSnackAt(int position) const {
    if ((position >= 0 && position < snack_count)) {
        if (container[position]->name.empty()) {
            return "продано";
        } else {
            return container[position]->name + " " + this->getFormatedPriceAt(position) +" руб.";
        }
    } else if (position >= snack_count && position < slot_capacity) {
        return std::string("свободно");
    } else {
        return std::string("");     // типа ошибка. возвращаем пустое значение
    }
}

void SnackSlot::buySnack(Snack* snack) {
    for (int i = 0;  i < this->snack_count; i++) {
        if (this->container[i]->name == snack->name) {
            this->container[i] = new Snack();
            this->snack_count--;
            break;
        }
    }

};
void buySnack(int position);

Snack*& SnackSlot::at(int index) {
    if (index < 0 or index >= slot_capacity) {
        std::cout << "SnackSlot index out of bound, exiting";
        exit(0);
    }
    return container[index];
}

Snack*& SnackSlot::operator[](int index) {
    if (index < 0 or index >= slot_capacity) {
        std::cout << "SnackSlot index out of bound, exiting";
        exit(0);
    }
    return container[index];
}


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


int VendingMachine::getEmptySlotsCount(void) const {
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
        std::cout << "сорян. нет места"; // ничего не делаемы
    }
}



/**
 *
 * @brief перегрузка операторов вывода в консоль
 *
 */


std::ostream&  operator<<(std::ostream& ostr, const SnackSlot *rhs) {
        ostr << "Slot("<< rhs->slot_capacity <<") -> [";
        for (int i = 0; i < rhs->slot_capacity; i++) {
            ostr << (i == 0 ? "" : ", ")
                 << i << ": " << rhs->getSnackAt(i);
        }

        ostr << "]";
    return ostr;
}


std::ostream& operator<<(std::ostream& ostr, const VendingMachine *rhs) {
    ostr << "VendingMachine :=" << std::endl << "  Slots (" << rhs->machine_capacity <<") {\n";
    for (int i = 0; i < rhs->machine_capacity; i++) {
        ostr << "\t"
             << i
             << ": ";
        if (rhs->isEmptySlot(i))
            ostr << rhs->slots[i] << std::endl;
        else
            ostr << "свободно" << std::endl;
    }
    ostr << "  }" <<std::endl;
    return ostr;
}

