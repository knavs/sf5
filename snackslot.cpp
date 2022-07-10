#include "snackslot.h"
/**
 *
 * @class SnackSlot
 *
 */

SnackSlot::SnackSlot(int slot_capacity) {
    SnackSlot::slot_capacity = slot_capacity;
    SnackSlot::snack_count = 0;
    SnackSlot::container = new Snack*[snack_count];
}


SnackSlot::~SnackSlot() {
    std::cout << "~SnackSlot" << std::endl;
    for (int i = 0; i < snack_count; i++) delete container[i];
    delete[] container;
}


void SnackSlot::addSnack(Snack *snack) {

    if (snack_count >= slot_capacity) {         // новый не влезает. надо менять размер слота
        slot_capacity *= 2;                     // увеличиваем сразу в 2 раза.
        reallocateContainer();
    }

    container[snack_count] = new Snack(*snack);
    ++snack_count;
}

Snack* SnackSlot::getSnack(int idx) {
    return container[idx];
}

void SnackSlot::setSnack(int idx, Snack* asnack) {
    container[idx] = asnack;
}

void SnackSlot::reallocateContainer() {
    Snack **big_container = new Snack *[slot_capacity];
    for (int i = 0; i < snack_count; i++) {
        big_container[i] = container[i];        // копируем указатели в  новый массив
    }
    delete[] container;                        // очищаем старый динамический массив. указатели будут удалены в деструкторе
    container = big_container;
}


std::string SnackSlot::getFormatedPriceAt(int position) const {
    std::stringstream ss;
    ss << std::setprecision(2) << container[position]->getPrice();
    return  ss.str();
}


std::string SnackSlot::getSnackNameAt(int position) const {
    if ((position >= 0 && position < snack_count)) {
        if (container[position]->getName().empty()) {
            return "sold out";
        } else {
            return container[position]->getName()+ " " + this->getFormatedPriceAt(position) +" RUR";
        }
    } else if (position >= snack_count && position < slot_capacity) {
        return std::string("free");
    } else {
        return std::string("");     // типа ошибка. возвращаем пустое значение
    }
}

void SnackSlot::buySnack(Snack* snack) {
    for (int i = 0;  i < this->snack_count; i++) {
        if (this->container[i]->getName() == snack->getName()) {
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
 * @brief перегрузка операторов вывода в консоль
 *
 */


std::ostream&  operator<<(std::ostream& ostr, const SnackSlot *rhs) {
    ostr << "Slot("<< rhs->slot_capacity <<") -> [";
    for (int i = 0; i < rhs->slot_capacity; i++) {
        ostr << (i == 0 ? "" : ", ")
             << i << ": " << rhs->getSnackNameAt(i);
    }

    ostr << "]";
    return ostr;
}
