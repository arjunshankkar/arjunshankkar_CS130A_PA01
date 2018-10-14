// This is the header file for both the Transaction and
// TransactionChain class.
// CLASSES INCLUDED:
// Class Transaction (in namespace arjun_umashankkar)
// A Transaction is a class to represent a single transaction. A
// transaction contains only private members. These members are
// an int amount, a string sender, a string reciever, a string nonce,
// , and a string hash.
// Class TransactionChain is used a singly linked list of all
// Transaction blocks.
// Member functions of Transaction Chain include: addTransaction,
// findTransaction, and verifyAndPrint

#ifndef BLOCK_H
#define BLOCK_H
#include <cstdlib>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <string>
#include <algorithm>
#include "picosha2.h"

namespace arjun_umashankkar{
  class Transaction{
    public:
      //Default and Parameterized Constructors
      Transaction();
      Transaction(int amt, std::string sndr, std::string rcvr);
      Transaction(int amt, std::string sndr, std::string rcvr,
      std::string init_nonce, std::string init_hash, Transaction* ptr);
      //Setter member functions
      void set_amount(int new_amount) { amount = new_amount; }
      void set_sender(std::string new_sender) { sender = new_sender; }
      void set_reciever(std::string new_reciever) { reciever = new_reciever;}
      void set_nonce(std::string new_nonce) { nonce = new_nonce; }
      void set_hash(std::string new_hash) { hash = new_hash; }
      void set_previous(Transaction* new_Transaction) { previous = new_Transaction; }
      //Getter member functions
      int get_amount() const{ return amount; }
      std::string get_sender() const{ return sender; }
      std::string get_reciever() const{ return reciever; }
      std::string get_nonce() const{ return nonce; }
      std::string get_hash() const{ return hash; }
      Transaction* get_previous() const { return previous; }

    private:
      Transaction * previous;
      int amount;
      std::string sender;
      std::string reciever;
      std::string nonce;
      std::string hash;
  };

  class TransactionChain{
    public:
      TransactionChain();
      void addTransaction(int amount, std::string sender, std::string reciever);
      void findTransaction(std::string sender);
      bool verifyAndPrint();
      void setlast_ptr(Transaction* pointer) { last_ptr = pointer; }
      Transaction* getlast_ptr() const { return last_ptr; }
      // ~TransactionChain();
    private:
      mutable Transaction *head_ptr;
      Transaction *last_ptr;
  };
}

#endif
