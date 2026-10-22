#include "Bank.h"
#include <iostream>
#include <iomanip>

using namespace std;

void Bank::addAccount(unique_ptr<Account> acc)
{
    accounts.push_back(move(acc));
    cout << "Счет успешно создан!";
}
Account* Bank::findAccount(const string& accNum)
{
    for (auto& acc : accounts)
    {
        if (acc->getAccountNumber() == accNum)
        {
            return acc.get(); // Возвращаем сырой указатель
        }
    }
    return nullptr;
}
void Bank::displayAll() const
{
    if (accounts.empty())
    {
        cout << "Нет открытых счетов\n";
        return;
    }
    cout << "\n--- Все счета ---\n";
    cout << left << setw(12) << "Номер"
        << setw(20) << "Владелец"
        << setw(15) << "Тип"
        << "Баланс\n";
    cout << string(60, '-') << "\n";

    for (const auto& acc : accounts)
    {
        acc->displayInfo();
    }
}