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
}
