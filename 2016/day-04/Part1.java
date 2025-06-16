import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.HashMap;
import java.util.Map;
import java.util.PriorityQueue;

public class Part1 {
    public static void main(String[] args) {
        try(BufferedReader br = new BufferedReader(new FileReader("input.txt"))) {
            String roomCode;
            int sectorIdSum = 0;
            
            while ((roomCode = br.readLine()) != null) {
                String[] parts = roomCode.split("-");
                String finalPart = parts[parts.length - 1];

                String checksum = finalPart.substring(finalPart.length()-6, finalPart.length()-1);
                String sectorIdString = finalPart.substring(0, finalPart.length()-7);
                int sectorId = Integer.parseInt(sectorIdString);

                Map<Character, Integer> letterCount = new HashMap<>();
                for(int i=0;i< parts.length - 1; i++) {
                    String part = parts[i];
                    for(char c: part.toCharArray()) {
                        letterCount.put(c, letterCount.getOrDefault(c, 0) + 1);
                    }
                }

                PriorityQueue<Map.Entry<Character, Integer>> maxHeap = new PriorityQueue<>(
                    (a, b) -> a.getValue() == b.getValue() ? Character.compare(a.getKey(), b.getKey()) : b.getValue() - a.getValue()
                );
                maxHeap.addAll(letterCount.entrySet());

                StringBuilder calculatedChecksum = new StringBuilder();
                for(int i=0; i < 5; i++) {
                    Map.Entry<Character, Integer> entry = maxHeap.poll();
                    calculatedChecksum.append(entry.getKey());
                }

                if(calculatedChecksum.toString().equals(checksum)) {
                    sectorIdSum += sectorId;
                }
            }
            System.out.println(sectorIdSum);
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
