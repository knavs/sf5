#include "snackslot.h"
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
    std::cout << "~SnackSlot" << std::endl;
    for (int i = 0; i < snack_count; i++) delete container[i];
    delete [] container; // убрал лишнюю звездочку ВЫЛЕТАЕТ НА SEGFAULT с этой строчкой
}


void SnackSlot::addSnack(Snack *snack) {

    if (snack_count >= slot_capacity) {         // новый не влезает. надо менять размер слота
        slot_capacity *= 2;                     // увеличиваем сразу в 2 раза.
        _reallocate_container();
    }

    container[snack_count] = new Snack(*snack);
    ++snack_count;
}

void SnackSlot::_reallocate_container() {
    printf("\n__reallocate_container[%d -> %d](%d placed)\n", slot_capacity/2, slot_capacity, snack_count);
    Snack ** big_container = new Snack*[slot_capacity];
    for (int i = 0; i < snack_count; i++) {
        big_container[i] = container[i];        // копируем указатели в  новый массив
        //delete container[i];
    }


    // элементы не удаляем!!! т.к. они будут скопированы в container и будут потом очищены в дестркуторе
    //for (int i = 0; i < snack_count; i++) delete container[i];
    delete [] container; // убрал лишнюю звездочку

    container = big_container;
}


std::string SnackSlot::getFormatedPriceAt(int position) const {
    char str_buffer[6];
    // как-то не по c++
    std::sprintf(str_buffer, "%0.2f", container[position]->getPrice());
    return  str_buffer;
}


std::string SnackSlot::getSnackAt(int position) const {
    if ((position >= 0 && position < snack_count)) {
        if (container[position]->getName().empty()) {
            return "продано";
        } else {
            return container[position]->getName()+ " " + this->getFormatedPriceAt(position) +" руб.";
        }
    } else if (position >= snack_count && position < slot_capacity) {
        return std::string("свободно");
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
             << i << ": " << rhs->getSnackAt(i);
    }

    ostr << "]";
    return ostr;
}
