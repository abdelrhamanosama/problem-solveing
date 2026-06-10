// Last updated: 6/10/2026, 11:43:30 AM
class Bank {
    private long balance[];
    int n;
    public Bank(long[] balance) {
        this.balance = balance;
        this.n = balance.length;
        // System.out.println(n);
    }
    
    public boolean transfer(int account1, int account2, long money) {
        if(checkAccount(account1)&&checkAccount(account2)){
            if(this.balance[account1-1] >= money)
            {
                this.balance[account1-1] -= money;
                this.balance[account2-1] += money;
                return true;
            }
            else
                return false;
        }
        else{
            return false;
        }
    }
    
    public boolean deposit(int account, long money) {
        if(checkAccount(account)){
            this.balance[account-1] += money;
            return true;
        }
        else{
            return false;
        }
    }
    
    public boolean withdraw(int account, long money) {
        if(checkAccount(account)){
            if(this.balance[account-1] >= money)
            {
                this.balance[account-1] -= money;
                return true;
            }
            else
                return false;
        }
        else{
            return false;
        }
    }
    private boolean checkAccount(int account){
        return account >=1 && account <= this.n;
    }
}

/**
 * Your Bank object will be instantiated and called as such:
 * Bank obj = new Bank(balance);
 * boolean param_1 = obj.transfer(account1,account2,money);
 * boolean param_2 = obj.deposit(account,money);
 * boolean param_3 = obj.withdraw(account,money);
 */