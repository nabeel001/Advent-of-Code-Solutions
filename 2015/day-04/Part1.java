import java.math.BigInteger;
import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;

public class Part1 {
    public static void main(String[] args) throws NoSuchAlgorithmException {
        String input = "ckczppom";
        boolean resultFound = false;

        int saltNumber = 1;

        while (!resultFound) {
            StringBuilder secretKey = new StringBuilder(input);
            secretKey.append(saltNumber);

            MessageDigest md = MessageDigest.getInstance("MD5");
            byte[] messageDigest = md.digest(secretKey.toString().getBytes());
            BigInteger num = new BigInteger(1, messageDigest);
            String hashText = num.toString(16);

            while (hashText.length() < 32) {
                hashText = "0" + hashText;
            }

            if (hashText.startsWith("00000"))
                resultFound = true;
            else
                saltNumber++;
        }

        System.out.println(saltNumber);
    }
}