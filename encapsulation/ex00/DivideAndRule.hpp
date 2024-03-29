#ifndef DIVIDE_AND_RULE_HPP
#define DIVIDE_AND_RULE_HPP

#include <iostream>
#include <map>
#include <set>
#include <vector>

struct Bank;

struct Account
{
  private:
    typedef unsigned int clientId;
    typedef int amount;

    clientId id;
    amount value;

    friend struct Bank;

    static int generateUniqueID()
    {
        static unsigned int nextID = 1;
        return nextID++;
    }

    Account() : id(generateUniqueID()), value(0)
    {
    }

    friend std::ostream &operator<<(std::ostream &p_os, const Account &p_account)
    {
        p_os << "Id account [" << p_account.id << "] - Amount [" << p_account.value << "]";
        return (p_os);
    }
};

struct Bank
{
  private:
    int liquidity;

    std::map<Account::clientId, Account::amount> loanTracks;
    std::map<Account::clientId, Account *> clientAccounts;

    Account *operator[](int id)
    {
        if (id < 0 || static_cast<std::size_t>(id) >= clientAccounts.size())
        {
            throw std::out_of_range("Invalid client id");
        }
        std::map<Account::Account::clientId, Account *>::iterator it = clientAccounts.find(id);
        if (it != clientAccounts.end())
        {
            return it->second;
        }
        std::cerr << "The account does not exist in the bank register" << std::endl;
        return NULL;
    }

  public:
    Bank() : liquidity(0)
    {
    }

    ~Bank()
    {
        for (std::map<Account::clientId, Account *>::iterator it = clientAccounts.begin(); it != clientAccounts.end(); ++it)
        {
            delete it->second;
        }
        clientAccounts.clear();
    }

    int createAccount()
    {
        Account *newAccount = new Account();
        clientAccounts[newAccount->id] = newAccount;
        std::cout << "The account " << newAccount->id << " was successfully created" << std::endl;
        return newAccount->id;
    }

    void deleteAccount(unsigned int id)
    {
        Account *account = (*this)[id];

        if (account != NULL)
        {
            delete account;
            clientAccounts.erase(id);
        }
    }

    void deposit(int amount, unsigned int id)
    {
        Account *account = (*this)[id];

        if (account != NULL)
        {
            this->liquidity += (0.05 * amount);
            account->value += (1 - 0.05) * amount;
            std::cout << "The account " << account->id << " was successfully funded with " << amount
                      << " and a 5% charge was applied which results with " << (amount * 0.05) << std::endl;
        }
    }

    void withdrawal(int amount, unsigned int id)
    {
        Account *account = (*this)[id];

        if (account != NULL)
        {
            if (amount <= account->value)
            {
                account->value -= amount;
                std::cout << "The account " << account->id << " was successfully withdrawn an amount of " << amount
                          << std::endl;
            }
            else
            {
                std::cerr << "The account does not have the necessary funds to make "
                             "this withdrawal"
                          << std::endl;
            }
        }
    }

    void loanMaker(int amount, unsigned int id)
    {
        Account *account = (*this)[id];

        if (account != NULL)
        {
            if (this->liquidity >= amount)
            {
                this->liquidity -= amount;
                account->value += amount;
                this->loanTracks[id] = amount;
                std::cout << "The account receives a loan from the bank " << account->id << " in the amount of "
                          << amount << std::endl;
            }
            else
            {
                std::cerr << "The loan failed, the bank does not have enough liquidity" << std::endl;
            }
        }
    }

    void loanRepay(int amount, unsigned int id)
    {
        Account *account = (*this)[id];

        if (account != NULL)
        {
            if (this->loanTracks.count(id) > 0 && amount <= this->loanTracks[id])
            {
                account->value -= amount;
                this->liquidity += amount;
                this->loanTracks[id] -= amount;
                if (this->loanTracks[id] == 0)
                {
                    this->loanTracks.erase(id);
                }
                std::cout << "The account " << account->id << " has successfully repaid a loan amount of " << amount
                          << " with a remaining of " << this->loanTracks[id] << std::endl;
            }
            else
            {
                std::cerr << "The account does not have an active loan or the "
                             "repayment amount is invalid"
                          << std::endl;
            }
        }
    }

    friend std::ostream &operator<<(std::ostream &p_os, const Bank &p_bank)
    {
        p_os << "Bank informations : " << std::endl;
        p_os << "Liquidity : " << p_bank.liquidity << std::endl;

        p_os << "Client Accounts : " << std::endl;
        std::map<Account::clientId, Account *>::const_iterator it;
        for (it = p_bank.clientAccounts.begin(); it != p_bank.clientAccounts.end(); ++it)
            p_os << *(it->second) << std::endl;

        p_os << "Client Loans : " << std::endl;
        std::map<Account::clientId, Account::amount>::const_iterator map_it;
        for (map_it = p_bank.loanTracks.begin(); map_it != p_bank.loanTracks.end(); ++map_it)
            p_os << "Account: " << map_it->first << ", Remaining loan: " << map_it->second << std::endl;

        return (p_os);
    }
};
#endif
