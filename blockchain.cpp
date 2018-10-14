//This is the cpp file for the Transatcion and TransactionChain classes
#include "blockchain.h"
using namespace std;

namespace arjun_umashankkar{
  Transaction::Transaction(){
    previous = NULL;
    amount = 0;
    sender = "";
    reciever = "";
    nonce = "";
    hash = "";
  }

  Transaction::Transaction(int amt, std::string sndr, std::string rcvr){
    amount = amt;
    sender = sndr;
    reciever = rcvr;
    hash = "";
    nonce = "";
    previous = NULL;
  }

  Transaction::Transaction(int amt, std::string sndr, std::string rcvr,
  std::string init_nonce, std::string init_hash, Transaction* ptr){
    amount = amt;
    sender = sndr;
    reciever = rcvr;
    nonce = init_nonce;
    hash = init_hash;
    previous = ptr;
  }

  TransactionChain::TransactionChain(){
    head_ptr = NULL;
  }

  void TransactionChain::addTransaction(int amount, std::string sender, std::string reciever){
    Transaction *tmp_ptr = new Transaction(amount, sender, reciever, " ", " ", head_ptr);
    string new_nonce;
    string combinedPreHash;
    //generate new random numbers
    srand(time(NULL));
    //print generated character between a - z
    new_nonce = char(rand() % 26 + 97);
    combinedPreHash = to_string(amount) + sender + reciever + new_nonce;
    //while (combinedPreHash.back() != 0 )
  }
}
