import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

public class Part2 {
    public static void main(String[] args) {
        try (BufferedReader br = new BufferedReader(new FileReader("input.txt"))) {
            String dimensions = br.readLine();
            int validTrianglesCount = 0;

            while (dimensions != null && !dimensions.isEmpty()) {
                List<Integer> triangle1 = new ArrayList<>();
                List<Integer> triangle2 = new ArrayList<>();
                List<Integer> triangle3 = new ArrayList<>();

                for (int i = 0; i < 3; i++) {
                    String[] measures = dimensions.split(" ");
                    List<Integer> measureValues = new ArrayList<>();

                    for (int j = 0; j < measures.length; j++) {
                        if (!measures[j].isEmpty())
                            measureValues.add(Integer.parseInt(measures[j]));
                    }

                    triangle1.add(measureValues.get(0));
                    triangle2.add(measureValues.get(1));
                    triangle3.add(measureValues.get(2));

                    measureValues.clear();
                    dimensions = br.readLine();
                }

                triangle1.sort(null);
                triangle2.sort(null);
                triangle3.sort(null);

                if (triangle1.get(0) + triangle1.get(1) > triangle1.get(2))
                    validTrianglesCount++;
                if (triangle2.get(0) + triangle2.get(1) > triangle2.get(2))
                    validTrianglesCount++;
                if (triangle3.get(0) + triangle3.get(1) > triangle3.get(2))
                    validTrianglesCount++;
            }

            System.out.println(validTrianglesCount);

        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
