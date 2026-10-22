#pragma once
#include "Account.h"

using namespace std;

// Дебетовый счет (наследник Account)
class DebitAccount : public Account
{
    public:
        // Конструкто вызывает конструкто базового класса
        DebitAccount(string owner, string accNum, double balance = 0.0);
        // Переопределение виртуальных методов
        void withdraw(double amount) override;
        string getAccountType() const override;
};