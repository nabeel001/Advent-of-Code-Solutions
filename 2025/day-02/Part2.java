import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.math.BigInteger;
import java.util.HashSet;
import java.util.Set;

public class Part2 {
    public static void main(String[] args) {
        try (BufferedReader br = new BufferedReader(new FileReader("input.txt"))) {

            BigInteger totalInvalidSum = new BigInteger("0");

            String rangesString = br.readLine();
            String[] ranges = rangesString.split(",");

            for (String range : ranges) {
                String rangeValues[] = range.split("-");

                BigInteger startValue = new BigInteger(rangeValues[0]);
                BigInteger endValue = new BigInteger(rangeValues[1]);

                BigInteger num = startValue;
                while (num.compareTo(endValue) <= 0) {

                    String value = num.toString();
                    int valueLength = value.length();

                    for (int i = 1; i <= valueLength / 2; i++) {
                        if (valueLength % i != 0)
                            continue;

                        int id = 0;
                        int count = 0;
                        Set<String> valueSubStrings = new HashSet<>();

                        for (int j = 0; j < valueLength / i; j++) {
                            String subString = value.substring(id, id + i);
                            valueSubStrings.add(subString);
                            count++;
                            id += i;
                        }

                        if (count >= 2 && valueSubStrings.size() == 1) {
                            totalInvalidSum = totalInvalidSum.add(num);
                            break;
                        }
                    }

                    num = num.add(BigInteger.ONE);
                }
            }

            System.out.println(totalInvalidSum);
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
