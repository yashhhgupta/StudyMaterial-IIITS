class Account {
    int acc_num;
    String acc_name;
    String password;
    int balance;
    int num_transactions = 0;
}

public class BankApplication {
    public static Account[] records = new Account[10];
    public static int num_account = 0;

    public static Account createAccount(int acc_num, String acc_name, String password, int balance) {
        Account a = new Account();
        num_account++;
        a.acc_num = acc_num;
        a.acc_name = acc_name;
        a.balance = balance;
        a.password = password;
        return a;
    }

    public static int getAccount(int account) {
        for (int i = 0; i < num_account; i++) {
            if (account == records[i].acc_num) {
                return i;
            }
        }
        return -1;
    }

    public static int login(int acc, String s) {
        int index;
        index = getAccount(acc);
        if (index == -1) {
            System.out.println("Account not found");
        } else {
            if (records[index].password == s) {
                System.out.println("You are logged in as " + records[index].acc_name);
                return index;
            } else {
                System.out.println("Wrong password");
            }
        }
        return -1;
    }

    public static void operation0(int index) {
        System.out.println("You are logged out.\nLogin to continue");
    }

    public static void operation1(int index) {
        if (index == -1) {
            System.out.println("You are not logged in.\nLogin to continue\n");
        } else {
            System.out.println("Account Balance:- " + records[index].balance);
        }
    }

    public static void operation2(int index, int cd, int amount) {
        if (index == -1) {
            System.out.println("You are not logged in.\nLogin to continue\n");
        } else {
            if (cd == 1) {
                records[index].balance += amount;
                System.out.println("Rs." + amount + " credited to your account\n");
            } else if (cd == 2) {
                if (records[index].balance > amount) {

                    records[index].balance -= amount;
                    System.out.println("Rs." + amount + " debited from your account");
                } else {
                    System.out.println("Insufficient Balance");
                }
            }
        }
    }

    public static void operation3(int index, int account, int amount) {
        if (index == -1) {
            System.out.println("You are not logged in.\nLogin to continue");
        } else {
            int index2 = getAccount(account);
            if (records[index].balance > amount) {

                records[index].balance -= amount;
                records[index2].balance += amount;
                System.out.println("Rs." + amount + " transferred from your account to " + records[index2].acc_name);
            } else {
                System.out.println("Insufficient Balance");
            }
        }
    }

    public static void main(String[] args) {
        records[0] = createAccount(34523, "ram", "ram@123", 500);
        records[1] = createAccount(12523, "shyam", "shyam@123", 5000);
        records[2] = createAccount(69873, "rahul", "rahul@123", 10000);
        records[3] = createAccount(41233, "Jack", "jacknjill", 200000);
        int x;
        x = login(34523, "ram@123");
        System.out.println("-----------------------");

        // operation 0-->Log out
        // operation 1-->Account Balance checking
        // operation 2-->Credit(1)/Debit(2)
        // operation 3-->Transfer Between Accounts
        operation1(x);
        System.out.println("-----------------------");
        operation2(x, 2, 600);
        System.out.println("-----------------------");
        operation1(x);
        System.out.println("-----------------------");
        operation0(x);
        x = -1;
        System.out.println("-----------------------");
        System.out.println("-----------------------");
        System.out.println("-----------------------");
        operation2(x, 1, 200);
        System.out.println("-----------------------");
        x = login(41233, "jacknjill");
        System.out.println("-----------------------");
        operation1(x);
        System.out.println("-----------------------");
        operation3(x, 12523, 2000);
        System.out.println("-----------------------");
        operation0(x);
        x = -1;
        System.out.println("-----------------------");
        System.out.println("-----------------------");
        System.out.println("-----------------------");
        x = login(12523, "shyam@123");
        System.out.println("-----------------------");
        operation1(x);
        System.out.println("-----------------------");
        operation2(x, 1, 4000);
        System.out.println("-----------------------");
        operation1(x);
        System.out.println("-----------------------");
    }
}