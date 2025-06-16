import java.math.BigInteger;
import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;

public class Part2 {
    public static void main(String[] args) throws NoSuchAlgorithmException {
        String input = "ugkcyxxp";

        int saltNumber = 0;
        int passwordCharCount = 0;
        char[] passwordArray = new char[8];
        for (int i = 0; i < 8; i++)
            passwordArray[i] = '\0';

        while (passwordCharCount < 8) {
            StringBuilder secretKey = new StringBuilder(input);
            secretKey.append(saltNumber);

            MessageDigest md = MessageDigest.getInstance("MD5");
            byte[] messageDigest = md.digest(secretKey.toString().getBytes());
            BigInteger num = new BigInteger(1, messageDigest);
            String hashText = num.toString(16);

            while (hashText.length() < 32) {
                hashText = "0" + hashText;
            }

            if (hashText.startsWith("00000") && Character.isDigit(hashText.charAt(5))) {
                int index = Integer.parseInt(String.valueOf(hashText.charAt(5)));
                char value = hashText.charAt(6);

                if (index <= 7 && passwordArray[index] == '\0') {
                    passwordArray[index] = value;
                    passwordCharCount++;
                }
            }
            saltNumber++;
        }

        String password = new String(passwordArray);
        System.out.println(password);
    }
}