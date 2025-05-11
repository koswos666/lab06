#pragma once

class Account;

class Transaction {
 public:
  Transaction();
  
  int fee() const { return fee_; }
  virtual ~Transaction();

  bool Make(Account& from, Account& to, int sum);
  void set_fee(int fee) { fee_ = fee; }

 private:
  void Credit(Account& accout, int sum);
  bool Debit(Account& accout, int sum);

  // Virtual to test.
  virtual void SaveToDataBase(Account& from, Account& to, int sum);

  int fee_;
};
