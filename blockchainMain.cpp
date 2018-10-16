//This is the tester/user input interface for the blockchain project.
#include "blockchain.h"
#include <string>
using namespace std;
using namespace arjun_umashankkar;

  int main(){
      TransactionChain Blockchain;
      double user_double = 0.0;
      int user_input = 0;
      while (user_input != 4){
      cout << "Welcome to the Transaction-chain application..." << endl;
      cout << "1) Add a transaction to the chain" << endl;
      cout << "2) Find a transaction with name of sender" << endl;
      cout << "3) Verify and print the chain." << endl;
      cout << "4) Exit the application." << endl;
      cout << "Which operation do you want to make? (1,2,3,4)" << endl;
      //cin >> user_double;
      //int user_input = (int) user_double;
      cin >> user_input;
      while(cin.fail()){
        cout << "This was not a valid input. Please try again." << endl;
        cin.clear();
        cin.ignore(256,'\n');
        cin >> user_input;
      }
      if(user_input == 1){
        cout << "Please enter the amount, sender, and reciever (in that order) "
             << "with spaces between values and hit enter!" << endl;
        int amnt;
        string sand, rece;
        cin >> amnt >> sand >> rece;
        while(cin.fail()){
          cout << "This was not a valid input. Please try again, and make sure to use an integer for amount." << endl;
          cin.clear();
          cin.ignore(256,'\n');
          cin >> amnt >> sand >> rece;
        }
        Blockchain.addTransaction(amnt, sand, rece);
        cout << "Your transaction has been added. The hash contained in this transaction is: " << endl
             << Blockchain.get_head_ptr()->get_hash() << endl;
      }
      if(user_input == 2){
        cout << "Please input the sender whose transactions you would like to find, and hit enter." << endl;
        string string_input;
        cin >> string_input;
        Blockchain.findTransaction(string_input);
      }
      if(user_input == 3){
        cout << "If the hash has been compromised, this function will return false." << endl;
        cout << "If the hash has not been compromised, this function will return true and print the list of transactions." << endl;
        Blockchain.verifyAndPrint();
      }
      if (user_input == 4){
        cout << "Thank you for using the Transaction-chain application!" << endl;
        break;
      }
      if ((user_input != 1) && (user_input != 2) && (user_input != 3) && (user_input != 4))
        cout << "Wrong operation! Please try again with a valid integer input." << endl;
      }
    }
