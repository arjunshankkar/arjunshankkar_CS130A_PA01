//This is the tester/user input interface for the blockchain project.
#include "blockchain.h"
#include <string>
using namespace std;
using namespace arjun_umashankkar;

  int main(){
      Transaction Blockchain;
      double user_double = 0.0;
      int user_input = 0;
      while (user_input != 4){
      cout << "Welcome to the Transaction-chain application..." << endl;
      cout << "1) Add a transaction to the chain" << endl;
      cout << "2) Find a transaction with name of sender" << endl;
      cout << "3) Verify and print the chain." << endl;
      cout << "4) Exit the application." << endl;
      cout << "Which operation do you want to make? (1,2,3,4)" << endl;
      cin >> user_double;
      int user_input = (int) user_double;
      if(user_input == 1){
        cout << "stub for add transaction" << endl;
      }
      if(user_input == 2)
        cout << "stub for find transaction" << endl;
      if(user_input == 3)
        cout << "stub for verify and print" << endl;
      if (user_input == 4){
        cout << "Thank you for using the Transaction-chain application!" << endl;
        break;
      }
      if ((user_input != 1) && (user_input != 2) && (user_input != 3) && (user_input != 4))
        cout << "Wrong operation! Please try again." << endl;
    }
  }
