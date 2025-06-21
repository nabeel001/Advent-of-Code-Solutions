import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

public class Part2 {
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
                int[] leastFrequentCharCount = new int[26];

                for (char c : messageColumns[i].toCharArray()) {
                    leastFrequentCharCount[c - 'a']++;
                }
                int minCount = Integer.MAX_VALUE;
                char leastFrequentChar = 'a';
                for (int j = 0; j < leastFrequentCharCount.length; j++) {
                    if (leastFrequentCharCount[j] < minCount) {
                        minCount = leastFrequentCharCount[j];
                        leastFrequentChar = (char) ('a' + j);
                    }
                }
                decodedMessage.append(leastFrequentChar);
            }

            System.out.println(decodedMessage.toString());
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
