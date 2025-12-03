import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.math.BigInteger;

public class Part1 {
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
                    if (value.length() % 2 == 0) {
                        int midPoint = value.length() / 2;
                        String firstHalfValue = value.substring(0, midPoint);
                        String secondHalfValue = value.substring(midPoint);

                        if (firstHalfValue.equals(secondHalfValue))
                            totalInvalidSum = totalInvalidSum.add(num);
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