import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

public class Part1 {
    public static void main(String[] args) {
        try (BufferedReader br = new BufferedReader(new FileReader("input.txt"))) {
            String dimensions = br.readLine();
            int validTrianglesCount = 0;

            while (dimensions != null && !dimensions.isEmpty()) {
                String[] measures = dimensions.split(" ");
                List<Integer> measureValues = new ArrayList<>();

                for (int i = 0; i < measures.length; i++) {
                    if (!measures[i].isEmpty())
                        measureValues.add(Integer.parseInt(measures[i]));
                }

                int side1 = measureValues.get(0);
                int side2 = measureValues.get(1);
                int side3 = measureValues.get(2);

                if (side1 + side2 > side3 && side2 + side3 > side1 && side1 + side3 > side2)
                    validTrianglesCount++;

                dimensions = br.readLine();
            }

            System.out.println(validTrianglesCount);

        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
