/* Name: Russell (Chumicat) (Li-Shuo ZENG)
 * SID¡G B10332030
 * Date: Mar. 14, 2018
 * Last Update: Mar. 14, 2018
 * Version: v1.0
 * Problem statement: ATM
 * Reference:
 */
#include <iostream>
#include <exception>
using std::cin;
using std::cout;
using std::endl;
using std::exception;

class InsufficientFunds : public exception {

}inex;
class NegativeDeposit : public exception {

}neex;


class Account
{
private:
	double balance = 0;
public:
	Account() { }
	Account(double initialDeposit) : balance(initialDeposit) {}
	double getBalance() { return balance; }

	//returns new balance or throw if error
	double deposit(double amount)
	{
		if (amount < 0)
			throw neex;
		else
			balance += amount;

		return balance;
	}

	//return new balance or throw if invalid amount
	double withdraw(double amount)
	{
		if ((amount > balance) || (amount < 0))
			throw inex;
		else
			balance -= amount;
		return balance;
	}
};

int main()
{
	Account a(100);
	try
	{
		cout << "Depositing 50" << endl;
		cout << "New balance: " << a.deposit(50) << endl;
		//cout << "Depositing -25" << endl;
		//cout << "New balance: " << a.deposit(-25) << endl;
		cout << "Withdraw 25" << endl;
		cout << "New balance: " << a.withdraw(25) << endl;
		cout << "Withdraw 250" << endl;
		cout << "New balance: " << a.withdraw(250) << endl;
	}
	catch (InsufficientFunds) // InsufficientFunds: a class name
	{
		cout << "Not enough money to withdraw that amount." << endl;
	}
	catch (NegativeDeposit) // NegativeDeposit: a class name
	{
		cout << "You may only deposit a positive amount." << endl;
	}
	cout << "Enter a character to exit" << endl;
	char wait;
	cin >> wait;
	return 0;
}