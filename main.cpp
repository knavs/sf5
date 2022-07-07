#include "vendingmachine.h"

int main() {
    setlocale(LC_ALL, "");

    auto bounty = new Snack("Bounty", 50.02);
    auto snickers = new Snack("Snickers");
    auto gematogen = new Snack("Гематоген");
    auto mishka = new Snack("Мишка на севере");
    auto step = new Snack("Степ");
    auto vobla = new Snack("Вобла");
    auto suhariki = new Snack("3 корочки");

    auto slot = new SnackSlot(4 );// 4- количество батончиков, которые помещаются в слот
    auto slot2 = new SnackSlot(5 );// 5- количество батончиков, которые помещаются в слот

    slot->addSnack(bounty); //Добавляем батончик в слот
    slot->addSnack(snickers);

    slot2->addSnack(gematogen);
    slot2->addSnack(mishka);
    slot2->addSnack(vobla);
    slot2->addSnack(step);
    slot2->addSnack(suhariki);
    slot2->addSnack(bounty);

    int slotCount = 5;  //slotCount - Количество слотов для снеков
    auto machine = new VendingMachine(slotCount);  //slotCount - Количество слотов для снеков
    machine->addSlot(slot); // Помещаем слот обратно в аппарат
    machine->addSlot(slot2); // Помещаем слот обратно в аппарат

    std::cout << "Свободных слотов:" << machine->getEmptySlotsCount()  << std::endl; // Должно выводить количество пустых слотов для снеков
    std::cout << machine;


    // Попытка сделать Сеттер
    (*slot2)[0] = suhariki;
    // Попытка сделать Геттер
    auto random_snack = (*slot2)[rand()%slotCount];

    slot2->buySnack(mishka);

    suhariki->getName() = "Емеля";//


    // Проверяем получилось ли заменить Snack  в слот 2
    std::cout << machine;

    std::cout << random_snack->getName();


    // Вопрос: А можно как-то покороче ??
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

