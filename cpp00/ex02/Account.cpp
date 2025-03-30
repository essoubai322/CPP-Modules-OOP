#include <iostream>
#include "Account.hpp"

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

void Account::_displayTimestamp(void)
{
	time_t		rawtime;
	struct tm	*timeinfo;
	char buffer	[30];

	time (&rawtime);
	timeinfo = localtime (&rawtime);

	strftime (buffer,30,"[%Y%m%d_%H%M%S] ",timeinfo);
	std::cout << buffer; 
}

Account::Account( int initial_deposit ) {
    this->_accountIndex = _nbAccounts;
    _nbAccounts++;
    _totalAmount += initial_deposit;
    this->_amount = initial_deposit;
    this->_nbDeposits = 0;
    this->_nbWithdrawals = 0;
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";created" << std::endl;
}

Account::~Account() {
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";closed" << std::endl;
}

int Account::getNbAccounts() {return _nbAccounts;}

int Account::getTotalAmount() {return _totalAmount;}

int Account::getNbDeposits() {return _totalNbDeposits;}

int Account::getNbWithdrawals() {return _totalNbWithdrawals;}

void Account::displayAccountsInfos() 
{
    _displayTimestamp();
    std::cout << "accounts:" << _nbAccounts << ";total:" << _totalAmount << ";deposits:" << _totalNbDeposits << ";withdrawals:" << _totalNbWithdrawals << std::endl;
}

void	Account::makeDeposit( int deposit ) {
    _displayTimestamp();
    _nbDeposits++;
    _totalNbDeposits++;
    _totalAmount += deposit;
    std::cout << "index:" << _accountIndex << ";p_amount:" << _amount << ";deposit:" << deposit << ";amount:" << (_amount + deposit) << ";nb_deposits:" << _nbDeposits << std::endl;
    _amount += deposit;
}

bool	Account::makeWithdrawal( int withdrawal ) {
    _displayTimestamp();
    if ((_amount - withdrawal) < 0)
    {
        std::cout << "index:" << _accountIndex << ";p_amount:" << _amount << ";withdrawal:refused" << std::endl;
        return false;
    }
    _nbWithdrawals++;
    _totalNbWithdrawals++;
    _totalAmount -= withdrawal;
    std::cout << "index:" << _accountIndex << ";p_amount:" << _amount << ";withdrawal:" << withdrawal << ";amount:" << (_amount - withdrawal) << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
    _amount -= withdrawal;
    return true;
}

int		Account::checkAmount( void ) const {return _amount;}
void	Account::displayStatus( void ) const {
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";deposits:" << _nbDeposits << ";withdrawals:" << _nbWithdrawals << std::endl;
}
