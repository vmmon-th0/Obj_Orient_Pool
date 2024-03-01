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
    int id;
    int value;

    friend struct Bank;
    std::set<int> usedIDs;

    static int generateUniqueID()
    {
        static int nextID = 1;
        return nextID++;
    }

    Account() : id(-1), value(0)
    {
        int idAttempt;
        for (; (usedIDs.find(idAttempt = generateUniqueID())) != usedIDs.end();)
        {
        }
        this->id = idAttempt;
        usedIDs.insert(idAttempt);
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

    typedef int clientId;
    typedef int amount;

    std::map<clientId, amount> loanTracks;
    std::vector<Account *> clientAccounts;

  public:
    Bank() : liquidity(0)
    {
    }

    ~Bank()
    {
        for (std::vector<Account *>::iterator it = clientAccounts.begin(); it != clientAccounts.end(); ++it)
        {
            delete *it;
        }
        clientAccounts.clear();
    }

    void createAccount()
    {
        Account *newAccount = new Account();
        clientAccounts.push_back(newAccount);

        std::cout << "The account " << newAccount->id << " was successfully created" << std::endl;
    }

    std::vector<Account *>::iterator findClient(int id)
    {
        for (std::vector<Account *>::iterator it = clientAccounts.begin(); it != clientAccounts.end(); ++it)
        {
            Account *account = *it;
            if (account->id == id)
            {
                return it;
            }
        }
        std::cerr << "The account does not exist in the bank register" << std::endl;
        return clientAccounts.end();
    }

    void deleteAccount(int id)
    {
        std::vector<Account *>::iterator it = findClient(id);

        if (it != clientAccounts.end())
        {
            delete *it;
            clientAccounts.erase(it);
        }
    }

    void deposit(int amount, int id)
    {
        std::vector<Account *>::iterator it = findClient(id);

        if (it != clientAccounts.end())
        {
            Account *account = *it;

            this->liquidity += (0.05 * amount);
            account->value += (1 - 0.05) * amount;
            std::cout << "The account " << account->id << " was successfully funded with " << amount
                      << " and a 5% charge was applied which results with " << (amount * 0.05) << std::endl;
        }
    }

    void withdrawal(int amount, int id)
    {
        std::vector<Account *>::iterator it = findClient(id);

        if (it != clientAccounts.end())
        {
            Account *account = *it;

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

    void loanMaker(int amount, int id)
    {
        std::vector<Account *>::iterator it = findClient(id);

        if (it != clientAccounts.end())
        {
            Account *account = *it;
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

    void loanRepay(int amount, int id)
    {
        std::vector<Account *>::iterator it = findClient(id);

        if (it != clientAccounts.end())
        {
            if (this->loanTracks.count(id) > 0 && amount <= this->loanTracks[id])
            {
                (*it)->value -= amount;
                this->liquidity += amount;
                this->loanTracks[id] -= amount;

                if (this->loanTracks[id] == 0)
                {
                    this->loanTracks.erase(id);
                }

                std::cout << "The account " << (*it)->id << " has successfully repaid a loan amount of " << amount
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
        std::vector<Account *>::const_iterator it;
        for (it = p_bank.clientAccounts.begin(); it != p_bank.clientAccounts.end(); ++it)
            p_os << *(*it) << std::endl;

        p_os << "Client Loans : " << std::endl;
        std::map<int, int>::const_iterator map_it;
        for (map_it = p_bank.loanTracks.begin(); map_it != p_bank.loanTracks.end(); ++map_it)
            p_os << "Account: " << map_it->first << ", Remaining loan: " << map_it->second << std::endl;

        return (p_os);
    }
};
#endif
