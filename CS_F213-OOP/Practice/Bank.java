import java.io.*;
import java.util.*;

class BankAccount {
    private int balance = 0;

    synchronized void deposit(int amount) {
        balance += amount;
        System.out.println("Deposited " + amount + ", balance is now " + balance);
    }

    synchronized void withdraw(int amount) {
        if (balance < amount) {
            System.out.println("java.lang.ArithmeticException: Illegal mathematical operation");
            return;
        }
        balance -= amount;
        System.out.println("Withdrew " + amount + ", balance is now " + balance);
    }
}

public class Bank {
    public static void main(String[] args) {
        BankAccount account = new BankAccount();
        List<Thread> threads = new ArrayList<>();
        try {
            File file = new File(args[0]);
            Scanner scanner = new Scanner(file);
            while (scanner.hasNextLine()) {
                String line = scanner.nextLine();
                char type = line.charAt(0);
                int amount = Integer.parseInt(line.substring(1));
                if (type == 'd') {
                    threads.add(new Thread(() -> account.deposit(amount)));
                } else if (type == 'w') {
                    threads.add(new Thread(() -> account.withdraw(amount)));
                } else {
                    System.out.println("java.lang.IllegalArgumentException: Wrong argument provided");
                }
            }
            scanner.close();
        } catch (FileNotFoundException e) {
            System.out.println("java.io.FileNotFoundException: Error opening the specified file");
        } catch (NumberFormatException e) {
            System.out.println("java.lang.NumberFormatException: Error in string to number conversion");
        }
        for (int i = 0; i < threads.size(); i++) {
            threads.get(i).start();
        }

        for (Thread thread : threads) {
            try {
                thread.join();
            } catch (InterruptedException e) {
                System.out.println("java.lang.InterruptedException: Thread interrupted");
            }
        }
    }
}