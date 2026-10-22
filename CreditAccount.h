#pragma once
#include "Account.h"

using namespace std;

// Кредитный счет (наследник Account)
class CreditAccount : public Account
{
    private:
        double creditLimit; // Кредитный лимит
    public:
        CreditAccount(string owner, string accNum, double limit);
        void withdraw(double amount) override;
        string getAccountType() const override;
};