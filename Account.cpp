#include "Account.h"
#include <iostream>
#include <iomanip>
#include <stdexcept>

using namespace std;

// Реализация конструктора
Account::Account(string owner, string accNum, double balance) 
    : owner(owner), accountNumber(accNum), balance(balance) {}
// Пополнение счета
void Account::deposit(double amount)
{
    if (amount < 0)
        throw invalid_argument("Сумма должна быть положительной!");
    balance += amount;
}
// Геттеры
double Account::getBalance() const
{
    return balance;
}
string Account::getOwner() const
{
    return owner;
}
string Account::getAccountNumber() const
{
    return accountNumber;
}
// Отображение информации о счете
void Account::displayInfo() const
{
    cout << left << setw(12) << accountNumber 
        << setw(20) << owner << setw(15) << getAccountType()
        << ficex << setprecision(2) << balance << " руб.\n";
}