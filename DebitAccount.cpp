#include "DebitAccount.h"
#include <stdexcept>

DebitAccount::DebitAccount(string owner, string accNum, double balance)
    : Account(owner, accNum, balance) {}
// Снятие средств (можно только то, что есть на счете)
void DebitAccount::withdraw(double amount)
{
    if (amount > balance)
        throw runtime_error("Недостаточно средств!");
    balance -= amount;
}
string DebitAccount::getAccountType() const
{
    return "Дебетовый";
}