package EncryptionSource;
public final class S20200010234_MyEncryption {
    public final static int key = 5;

    public String ceaserCipher(String plainText, int key) {
        String cipherText = "";
        for (int i = 0; i < plainText.length(); i++) {
            char ref = (char) ((int) plainText.charAt(i));
            if (plainText.charAt(i) == ' ') {
                cipherText += ' ';
            } else {
                ref = (char) ((int) 'a' + ((int) ref - (int) 'a' + key) % 26);
                cipherText += ref;
            }
        }
        return cipherText;
    }

    public String ceaserCipher(String plainText) {
        String cipherText = "";
        for (int i = 0; i < plainText.length(); i++) {
            char ref = (char) ((int) plainText.charAt(i));
            if (plainText.charAt(i) == ' ') {
                cipherText += ' ';
            } else {
                ref = (char) ((int) 'a' + ((int) ref - (int) 'a' + key) % 26);
                cipherText += ref;
            }
        }
        return cipherText;
    }

    public String transpositionCipher(String plainText) {
        String cipherText = "";
        plainText = plainText.replace(" ", "");
        char temp[][] = new char[100][key];
        int x = 0, y = 0;
        for (int i = 0; i < plainText.length(); i++) {

            temp[x][y] = plainText.charAt(i);
            y++;
            if (y == key) {
                y = 0;
                x++;
            }
        }
        for (int i = 0; i < key; i++) {
            for (int j = 0; j < x + 1; j++) {
                if((int) temp[j][i] >= 97 && (int) temp[j][i] <= 122){
                cipherText += temp[j][i];
                }
            }
        }
        return cipherText;
    }
    public String findEncryption(String plainText, String cipherText){
        if (ceaserCipher(plainText).equals(cipherText)) {
            return "Caesarcipher";
        }
        else if(transpositionCipher(plainText).equals(cipherText)){
            return "TranspositionCipher";
        }
        else{
            return "Invalid Encryption";
        }
    }

}