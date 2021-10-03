class Account {
    double acc_num;
    String acc_name;
    String password;
    double balance;

    public double getAcc_num() {
        return acc_num;
    }

    public void setAcc_num(double acc_num) {
        this.acc_num = acc_num;
    }

    public String getAcc_name() {
        return acc_name;
    }

    public void setAcc_name(String acc_name) {
        this.acc_name = acc_name;
    }

    public String getPassword() {
        return password;
    }

    public void setPassword(String password) {
        this.password = password;
    }

    public double getBalance() {
        return balance;
    }

    public void setBalance(double balance) {
        this.balance = balance;
    }

    void deposit(double amount) {
        balance += amount;
        System.out.println(amount + " added to balance");
        System.out.println("new balance=" + balance);
    }

    void withdraw(double amount) {
        balance -= amount;
        System.out.println(amount + " removed from balance");
        System.out.println("new balance=" + balance);
    }

    void addInterest() {
        balance += balance / 10;
        System.out.println("10% added to balance");
        System.out.println("new balance=" + balance);
    }

    void printBalance() {
        System.out.println("Balance= " + balance);
    }
}

class SavingAccount extends Account {
    double interest_percent;

    public double getInterest_percent() {
        return interest_percent;
    }

    public void setInterest_percent(double interest_percent) {
        this.interest_percent = interest_percent;
    }

    void addInterest() {
        balance += interest_percent * balance / 100;
        System.out.println(interest_percent + "% intrest added to balance");
        System.out.println("new balance=" + balance);
    }
}

class CurrentAccount extends Account {
    double limit;

    public double getLimit() {
        return limit;
    }

    public void setLimit(double limit) {
        this.limit = limit;
    }

    void withdraw(double amount) {
        if (amount < limit) {
            balance -= amount;
            System.out.println(amount + " removed from balance");
            System.out.println("new balance=" + balance);
        } else {
            System.out.println("Withdrawal failed as limit exceeded");
        }
    }

}

public class BankApplication {
    public static void main(String[] args) {
        Account a1 = new Account();
        System.out.println("===================");
        System.out.println("===================");
        System.out.println("===================");
        System.out.println("General Account");
        System.out.println("===================");

        a1.setAcc_name("Jhon");
        a1.setAcc_num(1234567);
        a1.setPassword("12345678");
        a1.setBalance(10000);
        a1.deposit(100);
        a1.withdraw(2000);
        a1.addInterest();
        a1.printBalance();
        System.out.println("===================");
        System.out.println("===================");
        System.out.println("===================");
        System.out.println("Saving Account");
        System.out.println("===================");

        SavingAccount sa1 = new SavingAccount();
        sa1.setAcc_name("Alex");
        sa1.setAcc_num(123458);
        sa1.setPassword("12345678");
        sa1.setBalance(50000);
        sa1.setInterest_percent(12);
        sa1.deposit(100);
        sa1.withdraw(2000);
        sa1.addInterest();
        sa1.printBalance();
        System.out.println("===================");
        System.out.println("===================");
        System.out.println("===================");
        System.out.println("Current Account");
        System.out.println("===================");

        CurrentAccount ca1 = new CurrentAccount();
        ca1.setAcc_name("Paul");
        ca1.setAcc_num(123158);
        ca1.setPassword("12345678");
        ca1.setBalance(5000);
        ca1.setLimit(1000);
        ca1.deposit(100);
        ca1.withdraw(2000);
        ca1.addInterest();
        ca1.printBalance();
    }
}
