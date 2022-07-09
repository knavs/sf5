#include "vendingmachine.h"

int main() {
    setlocale(LC_ALL, "");

    auto bounty = new Snack("Bounty", 50.02);
    auto snickers = new Snack("Snickers");
    auto gematogen = new Snack("Gematogen");
    auto mishka = new Snack("Mishka na severe");
    auto step = new Snack("Step");
    auto vobla = new Snack("Vobla");
    auto suhariki = new Snack("3 korochki");

    auto slot = new SnackSlot(2);                  // 2 - количество батончиков, которые помещаются в слот
    auto slot2 = new SnackSlot(5);                 // 5 - количество батончиков, которые помещаются в слот

    slot->addSnack(bounty);                         //Добавляем батончик в слот
    slot->addSnack(snickers);

    slot2->addSnack(gematogen);
    slot2->addSnack(mishka);
    slot2->addSnack(vobla);
    slot2->addSnack(step);
    slot2->addSnack(suhariki);
    slot2->addSnack(bounty);

    int slotCount = 5;                              //slotCount - Количество слотов для снеков
    auto machine = new VendingMachine(slotCount);   //slotCount - Количество слотов для снеков
    machine->addSlot(slot);                         // Помещаем слот обратно в аппарат
    machine->addSlot(slot2);                        // Помещаем слот обратно в аппарат

    std::cout << "Free Slots:" << machine->getEmptySlotsCount()  << std::endl; // Должно выводить количество пустых слотов для снеков
    std::cout << machine;

    slot2->setSnack(0, suhariki);                               // Сеттер
    auto random_snack = slot2->getSnack(rand()%slotCount);      // Геттер

    slot2->buySnack(mishka);

    // Проверяем получилось ли заменить Snack  в слот 2
    std::cout << machine;
    std::cout << random_snack->getName();

    delete bounty;
    delete snickers;
    delete gematogen;
    delete mishka;
    delete step;
    delete vobla;
    delete suhariki;
    delete machine;
    delete slot;
    delete slot2;
}

