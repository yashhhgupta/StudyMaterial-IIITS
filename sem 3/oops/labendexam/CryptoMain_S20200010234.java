import java.io.BufferedReader;
import java.io.FileReader;

/**
 * CryptoMain_S20200010234
 */

interface CryptoaAlgorithm {
    String encrypt(String string);

    String decrpyt(String string);
}

class SimpleCryptoAlgorithm implements CryptoaAlgorithm {

    @Override
    public String encrypt(String string) {
        String s = "";
        int key = 3;
        for (int i = 0; i < string.length(); i++) {
            char c = (char) ((int) string.charAt(i));
            if (c == ' ') {
                s += ' ';
            } else {
                c = (char) ((int) 'a' + ((int) c - (int) 'a' + key) % 26);
                s += c;
            }
        }
        return s;
    }

    @Override
    public String decrpyt(String string) {
        String s = "";
        int key = 3;
        for (int i = 0; i < string.length(); i++) {
            char c = (char) ((int) string.charAt(i));
            if (c == ' ') {
                s += ' ';
            } else if (c == 'a') {
                s += 'x';
            } else if (c == 'b') {
                s += 'y';
            } else if (c == 'c') {
                s += 'z';
            } else {
                c = (char) ((int) 'a' + ((int) c - (int) 'a' - key) % 26);
                s += c;
            }
        }
        return s;
    }

}

public class CryptoMain_S20200010234 {
    public static void main(String[] args) {
        String filename = args[0];
        int c = -1;
        switch (args[1]) {
            case "-e":
                c = 1;
                break;
            case "-d":
                c = 0;
                break;
            default:
                System.out.println("Wrong format!! :)");
        }
        BufferedReader reader = null;
        try {
            reader = new BufferedReader(new FileReader(filename));
            String line;
            SimpleCryptoAlgorithm encryptAll = new SimpleCryptoAlgorithm();
            while ((line = reader.readLine()) != null) {
                if (c == 1)
                    System.out.println(encryptAll.encrypt(line));
                else if(c == 0){
                    System.out.println(encryptAll.decrpyt(line));
                }else{
                    System.out.println("Try again!");
                }
            }
        } catch (Exception e) {
            e.printStackTrace();
        } finally {
            try {
                reader.close();
            } catch (Exception e) {
                e.printStackTrace();
            }
        }
    }

}
