#include "CreditAccount.h"
#include <stdexcept>

using namespace std;

CreditAccount::CreditAccount(string owner, string accNum, double limit)
    : Account(owner, accNum, 0.0), creditLimit(limit) {}
// Снятие средств (можно уйти в минус, но не дальше лимита)
void CreditAccount::withdraw(double amount)
{
    if (balance - amount < -creditLimit)
        throw runtime_error("Превышен кредитный лимит!");
    balance -= amount;
}
string CreditAccount::getAccountType() const
{
    return "Кредитный";
}