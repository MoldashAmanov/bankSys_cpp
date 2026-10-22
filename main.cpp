#include "Bank.h"
#include "DebitAccount.h"
#include "CreditAccount.h"
#include <iostream>
#include <memory>
#include <stdexcept>

using namespace std;

int main()
{
    Bank bank;
    int choice = 0;

    while (choice != 6)
    {
        cout << "\n --- BankSys ---\n"
            << "1. Открыть дебетовый счет\n"
            << "2. Открыть кредитный счет\n"
            << "3. Пополнить счет\n"
            << "4. Снять по счетам\n"
            << "5. Показать все счета\n"
            << "6. Выход\nВыбор: ";
        cin >> choice;

        try
        {
            if (choice == 1)
            {
                string owner, num;
                cout << "Владелец: ";
                cin >> owner;
                cout << "Номер счета: ";
                cin >> num;

                // Создаем умный указатель на дебетовый счет
                bank.addAccount(make_unique<DebitAccount>(owner, num));
            }
            else if (choice == 2)
            {
                string owner, num;
                double limit;
                cout << "Владелец: ";
                cin >> owner;
                cout << "Номер счета: ";
                cin >> num;
                cout << "Кредитный лимит: ";
                cin >> limit;

                // Создаем умный указатель на кредитный счет
                bank.addAccount(make_unique<CreditAccount>(owner, num, limit));
            }
            else if (choice == 3 || choice == 4)
            {
                string num;
                double amount;
                cout << "Номер счета: ";
                cin >> num;
                cout << "Сумма: ";
                cin >> amount;

                Account* acc = bank.findAccount(num);
                if (!acc)
                    throw runtime_error("Счет не найден!");
                if (choice == 3)
                    acc->deposit(amount);
                if (choice == 4)
                    acc->withdraw(amount);
                cout << "Операция прошла успешно!\n";
            }
            else if (choice == 5)
            {
                bank.displayAll();
            }
        }
        catch (const exception& e)
        {
            cerr << "Ошибка: " << e.what() << "\n";
        }
    }
    return 0;
}