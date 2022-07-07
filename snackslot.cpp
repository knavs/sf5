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
    delete [] container; // ����� ������ ��������� �������� �� SEGFAULT � ���� ��������
}


void SnackSlot::addSnack(Snack *snack) {

    if (snack_count >= slot_capacity) {         // ����� �� �������. ���� ������ ������ �����
        slot_capacity *= 2;                     // ����������� ����� � 2 ����.
        _reallocate_container();
    }

    container[snack_count] = new Snack(*snack);
    ++snack_count;
}

void SnackSlot::_reallocate_container() {
    printf("\n__reallocate_container[%d -> %d](%d placed)\n", slot_capacity/2, slot_capacity, snack_count);
    Snack ** big_container = new Snack*[slot_capacity];
    for (int i = 0; i < snack_count; i++) {
        big_container[i] = container[i];        // �������� ��������� �  ����� ������
        //delete container[i];
    }


    // �������� �� �������!!! �.�. ��� ����� ����������� � container � ����� ����� ������� � �����������
    //for (int i = 0; i < snack_count; i++) delete container[i];
    delete [] container; // ����� ������ ���������

    container = big_container;
}


std::string SnackSlot::getFormatedPriceAt(int position) const {
    char str_buffer[6];
    // ���-�� �� �� c++
    std::sprintf(str_buffer, "%0.2f", container[position]->getPrice());
    return  str_buffer;
}


std::string SnackSlot::getSnackAt(int position) const {
    if ((position >= 0 && position < snack_count)) {
        if (container[position]->getName().empty()) {
            return "�������";
        } else {
            return container[position]->getName()+ " " + this->getFormatedPriceAt(position) +" ���.";
        }
    } else if (position >= snack_count && position < slot_capacity) {
        return std::string("��������");
    } else {
        return std::string("");     // ���� ������. ���������� ������ ��������
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
 * @brief ���������� ���������� ������ � �������
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
