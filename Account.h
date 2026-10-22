#pragma once
#include <string>

using namespace std;

// Абстрактный класс счета
class Account
{
    protected:
        string owner;           // Владелец счета
        string accountNumber;   // Номер счета
        double balance;         // Баланс
    public:
        // Конструктор
        Account(string owner, string accNum, double balance = 0.0);
        // Виртуальный диструктор
        virtual ~Account() = default;
        // Виртуальные методы (могут быть переопределены в наследниках)
        virtual void deposit(double amount);
        virtual void withdraw(double amount) = 0; // Чистая виртуальная функция
        virtual string getAccountType() const = 0;
        // Геттеры
        double getBalance() const;
        string getOwner() const;
        string getAccountNumber() const;
        // Виртуальный метод отображения информации
        virtual void displayInfo() const;
};
