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
    string preHash;
    //generate new random numbers
    srand(time(NULL));
    //print generated character between a - z
    new_nonce = char(rand() % 26 + 97);
    preHash = to_string(amount) + sender + reciever + new_nonce;
    string hashed = picosha2::hash256_hex_string(preHash);
    int length = hashed.length();
    while (hashed.at(length-1) != '0' && hashed.at(length-1) != '1' &&
    hashed.at(length-1) != '2' && hashed.at(length-1) != '3' && hashed.at(length-1) != '4'){
      new_nonce = char(rand() % 26 + 97);
      //cout << new_nonce << endl;
      preHash = to_string(amount) + sender + reciever + new_nonce;
      hashed = picosha2::hash256_hex_string(preHash);
      length = hashed.length();
    }
    //cout << hashed << endl;
    tmp_ptr -> set_nonce(new_nonce);
    if(head_ptr == NULL){
      tmp_ptr-> set_hash("");
    }
    else{
      string prePrevHash = to_string(head_ptr->get_amount()) + head_ptr->get_sender()
                          + head_ptr->get_reciever() + head_ptr->get_nonce();
      string prev_hash = picosha2::hash256_hex_string(prePrevHash);
      tmp_ptr -> set_hash(prev_hash);
    }
    tmp_ptr -> set_previous(head_ptr);
    head_ptr = tmp_ptr;
  }


  void TransactionChain::findTransaction(std::string sender){
    int transactionCount = 0;
    for(Transaction *tmp_ptr = head_ptr; tmp_ptr != NULL; tmp_ptr = tmp_ptr = tmp_ptr->get_previous()){
      if(sender == tmp_ptr->get_sender()){
        transactionCount++;
        cout << endl;
        cout << "Amount: " << tmp_ptr->get_amount() << endl;
        cout << "Sender: " << tmp_ptr->get_sender() << endl;
        cout << "Reciever: " << tmp_ptr->get_reciever() << endl;
        cout << "Nonce: " << tmp_ptr->get_nonce() << endl;
        cout << "Hash: " << tmp_ptr->get_hash() << endl << endl;
      }
    }
    if (transactionCount == 0){
      cout << endl;
      cout << "There were no transactions where this person sent money." << endl;
    }
  }

  bool TransactionChain::verifyAndPrint(){
    //Verify first
    //Transaction *tmp_ptr = head_ptr;
    for(Transaction *tmp_ptr = head_ptr; tmp_ptr != NULL; tmp_ptr = tmp_ptr->get_previous()){
      if (tmp_ptr -> get_previous() == NULL){
        if(tmp_ptr->get_hash() != ""){
          return false;
        }
      }
      else{
         Transaction* prev_Transaction = tmp_ptr->get_previous();
         string prevPreHash = to_string(prev_Transaction->get_amount()) + prev_Transaction->get_sender() + prev_Transaction->get_reciever()+ prev_Transaction->get_nonce();
         string prevHash = picosha2::hash256_hex_string(prevPreHash);
         if(prevHash != tmp_ptr->get_hash()){
           return false;
          }
        }
     }
    for(Transaction* tmp_ptr = head_ptr; tmp_ptr != NULL; tmp_ptr = tmp_ptr->get_previous()){
      cout << endl;
      cout << "Amount: " << tmp_ptr->get_amount() << endl;
      cout << "Sender: " << tmp_ptr->get_sender() << endl;
      cout << "Reciever: " << tmp_ptr->get_reciever() << endl;
      cout << "Nonce: " << tmp_ptr->get_nonce() << endl;
      cout << "Hash: " << tmp_ptr->get_hash() << endl << endl;
    }
    return true;
  }

  TransactionChain::~TransactionChain(){
    head_ptr = NULL;
  }
}
