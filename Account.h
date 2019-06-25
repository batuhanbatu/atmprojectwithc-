#include <iostream>
#include <string>
using namespace std;
class Account
{
	protected:
		double rate = 0.035, balance;
		long int accountNumber;
		string name;
	public:
		Account(long int an=0, string nm = "", double bln = 0) //Constructor
		{
			setBalance(bln);
			name = nm;
			accountNumber = an;
		}
		double deposit(double a) //Para yat�rma
		{
			setBalance(balance += a);
			return getBalance();
		}
		double withDraw(double a) //Para �ekmek
		{
			setBalance(balance -= a);
			return getBalance();
		}
		double addInterest() //Faiz ekle
		{
			setBalance(balance + (balance*rate));
			return getBalance();
		}
		double getBalance() //Hesaptaki paray� g�stermek
		{
			return balance;
		}
		void setBalance(double a) //Hesaptaki paray� d�zenlemek
		{
			balance = a;
		}
		void moneyTransfer(Account &a, Account &b, double c) //Hesaptan hesaba para aktar�m�
		{
			cout << "Balance of the account (" << b.accountNumber << ") is " << b.deposit(c) << "\n";
			cout << "Balance of your account is " << a.withDraw(c) << "\n";
		}
};
class OverdraftAccount : public Account
{
	public:
		double withDraw(double m, Account &a) //Para �ekmek
		{
			a.setBalance(a.getBalance() - (m + m*0.05));
			return a.getBalance();
		}
};