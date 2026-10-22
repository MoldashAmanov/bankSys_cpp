#pragma once
#include "Account.h"
#include <vector>
#include <memory>

using namespace std;

class Bank
{
    private:
        // Умные указатели автоматически освобождают память
        vector<unique_ptr<Account>> accounts;
    public:
        // Добавление нового счета
        void addAccount(unique_ptr<Account> acc);
        // Поиск счета по номеру
        Account* findAccount(const string& accNum);
        // Отображение всех счетов
        void displayAll() const;
};