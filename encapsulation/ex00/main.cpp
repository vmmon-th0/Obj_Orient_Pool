#include "DivideAndRule.hpp"

int main()
{
    Bank myBank = Bank();
    // The attributes of the structures must not be modifiable from the outside
    // myBank.liquidity = 0x00;

    for (int i = 0; i < 10; ++i)
    {
        myBank.createAccount();
    }

    myBank.deposit(500, 4);
    myBank.deposit(1000, 5);
    std::cout << myBank << std::endl;

    myBank.withdrawal(1, 5);
    std::cout << myBank << std::endl;

    myBank.loanMaker(10, 5);
    std::cout << myBank << std::endl;

    myBank.loanRepay(10, 5);
    std::cout << myBank << std::endl;

	myBank.deleteAccount(5);
	std::cout << myBank << std::endl;

    return (0);
}
