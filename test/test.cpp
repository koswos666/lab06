#include <gtest/gtest.h>
#include "Account.h"
#include "Transaction.h"


TEST(AccountTest, GetBalance) {
    Account acc(1, 100);
    ASSERT_EQ(acc.GetBalance(), 100);
}

TEST(AccountTest, ChangeBalance) {
    Account acc(1, 100);
    ASSERT_THROW(acc.ChangeBalance(50), std::runtime_error);
    acc.Lock();
    acc.ChangeBalance(50);
    ASSERT_EQ(acc.GetBalance(), 150);
    acc.Unlock();
}
TEST(TransactionTest, MakeTransaction) {
    Account acc_from(1, 500);
    Account acc_to(2, 100);
    Transaction transaction;
    
    // Проверка на отрицательную сумму
    ASSERT_THROW(transaction.Make(acc_from, acc_to, -50), std::invalid_argument);
    
    // Проверка на слишком маленькую сумму
    ASSERT_THROW(transaction.Make(acc_from, acc_to, 99), std::logic_error);
    
    // Проверка успешной транзакции
    ASSERT_TRUE(transaction.Make(acc_from, acc_to, 100));
    ASSERT_EQ(acc_from.GetBalance(), 399); // 500 - 100 - 1
    ASSERT_EQ(acc_to.GetBalance(), 200);   // 100 + 100
    
    // Проверка на недостаточный баланс (новый тест)
    Account acc_from2(3, 101); // Ровно на сумму перевода + комиссия
    ASSERT_TRUE(transaction.Make(acc_from2, acc_to, 100)); // 101 >= 100+1
    
    Account acc_from3(4, 100); // Не хватает на комиссию
    ASSERT_FALSE(transaction.Make(acc_from3, acc_to, 100)); // 100 < 100+1
}
