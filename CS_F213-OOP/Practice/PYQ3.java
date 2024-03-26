class BankAccount {
    private long balance;
    private long minBalance;

    public long getBalance() {
        return balance;
    }
    public void setBalance(long balance) {
        this.balance = balance;
    }

    public long getMinBalance() {
        return minBalance;
    }
    public void setMinBalance(long minBalance) {
        this.minBalance = minBalance;
    }

    public long generateInterestAmount(long rateOfInterest){
        return balance * rateOfInterest / 100;
    }
}

class CurrentAccount extends BankAccount {
    CurrentAccount(long balance, long minBalance){
        this.setBalance(balance);
        this.setMinBalance(minBalance);
    }

    public long generateInterestAmount(){
        return super.generateInterestAmount(1);
    }
}

class SavingsAccount extends BankAccount {
    public long generateInterestAmount(){
        return super.generateInterestAmount(4);
    }
}


public class PYQ3 {
    public static void main(String args[]){
        CurrentAccount ca = new CurrentAccount(1000, 500);
        System.out.println(ca.generateInterestAmount());

        SavingsAccount sa = new SavingsAccount();
        sa.setBalance(1000);
        sa.setMinBalance(500);
        System.out.println(sa.generateInterestAmount());
    }
}
