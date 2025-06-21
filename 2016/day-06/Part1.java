import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

public class Part1 {
    public static void main(String[] args) {
        try (BufferedReader br = new BufferedReader(new FileReader("input.txt"))) {
            String[] messageColumns = new String[8];
            String message;

            StringBuilder decodedMessage = new StringBuilder();

            while ((message = br.readLine()) != null) {
                for (int i = 0; i < message.length(); i++) {
                    messageColumns[i] = messageColumns[i] == null ? "" : messageColumns[i];
                    messageColumns[i] += message.charAt(i);
                }
            }

            for (int i = 0; i < messageColumns.length; i++) {
                int[] mostFrequentCharCount = new int[26];

                for (char c : messageColumns[i].toCharArray()) {
                    mostFrequentCharCount[c - 'a']++;
                }
                int maxCount = 0;
                char mostFrequentChar = 'a';
                for (int j = 0; j < mostFrequentCharCount.length; j++) {
                    if (mostFrequentCharCount[j] > maxCount) {
                        maxCount = mostFrequentCharCount[j];
                        mostFrequentChar = (char) ('a' + j);
                    }
                }
                decodedMessage.append(mostFrequentChar);
            }

            System.out.println(decodedMessage.toString());
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
