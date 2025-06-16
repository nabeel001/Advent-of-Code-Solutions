import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

public class Part2 {
    public static void main(String[] args) {
        try(BufferedReader br = new BufferedReader(new FileReader("input.txt"))) {
            String roomCode;

            while ((roomCode = br.readLine()) != null) {
                String[] parts = roomCode.split("-");
                String finalPart = parts[parts.length - 1];

                String sectorIdString = finalPart.substring(0, finalPart.length()-7);
                int sectorId = Integer.parseInt(sectorIdString);

                StringBuilder decryptedName = new StringBuilder();
                for (int i = 0; i < parts.length - 1; i++) {
                    String part = parts[i];
                    for (char c : part.toCharArray()) {
                        char decryptedChar = (char) ((c - 'a' + sectorId) % 26 + 'a');
                        decryptedName.append(decryptedChar);
                    }
                    decryptedName.append(' ');
                }

                String decryptedRoomName = decryptedName.toString();
                if (decryptedRoomName.contains("northpole object storage")) {
                    System.out.println(sectorId);
                }
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
