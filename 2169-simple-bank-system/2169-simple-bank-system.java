class Bank {
    private long[] balances;
    int n;

    public Bank(long[] balance) {
        balances = balance;
        n = balance.length;
    }
    
    public boolean transfer(int account1, int account2, long money) {
        if (account1>n || account2>n) return false;

        if (balances[account1-1]>= money) {
            balances[account1-1] -= money;
            balances[account2-1] += money;

            return true;
        }

        return false;
    }
    
    public boolean deposit(int account, long money) {
        if (account>n) return false;

        balances[account-1]+=money;

        return true;
    }
    
    public boolean withdraw(int account, long money) {
        if (account>n || balances[account-1]<money) return false;


        balances[account-1]-=money;
        return true;
    }
}

/**
 * Your Bank object will be instantiated and called as such:
 * Bank obj = new Bank(balance);
 * boolean param_1 = obj.transfer(account1,account2,money);
 * boolean param_2 = obj.deposit(account,money);
 * boolean param_3 = obj.withdraw(account,money);
 */