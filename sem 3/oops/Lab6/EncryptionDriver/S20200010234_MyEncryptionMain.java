package EncryptionDriver;
import EncryptionSource.S20200010234_MyEncryption;

public class S20200010234_MyEncryptionMain {
    public static void main(String[] args) {
        S20200010234_MyEncryption a = new S20200010234_MyEncryption();
        String plainText = "My name is yash";
        System.out.println("Orignal Text: " + plainText);
        System.out.println("Encrypted Text:"+a.ceaserCipher(plainText, 6));
        System.out.println("Encrypted Text:"+a.ceaserCipher(plainText));
        System.out.println("Encrypted Text:"+a.transpositionCipher(plainText));
        String cipherText = "Rd sfrj nx dfxm";
        System.out.println("Encrypted Text:"+a.findEncryption(plainText,cipherText));
        cipherText = "Mesyihnsayma";
        System.out.println("Encrypted Text:"+a.findEncryption(plainText,cipherText));
    }
}
