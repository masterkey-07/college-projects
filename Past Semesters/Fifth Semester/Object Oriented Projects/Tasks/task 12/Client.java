import java.util.HashMap;

interface Digit {
    public void display(int size);
}

class SingleDigit implements Digit {
    private int digit;

    public SingleDigit(int digit) {
        this.digit = digit;
    }

    @Override
    public void display(int size) {
        System.out.println(Integer.toString(this.digit) + " (size of " + Integer.toString(size) + ")");
    }
}

class DigitPool {
    private HashMap<Integer, Digit> digitMap;
    private static DigitPool pool;

    private DigitPool() {
        this.digitMap = new HashMap<>();
    }

    public static DigitPool getPool() {
        if (pool != null)
            return pool;

        pool = new DigitPool();

        return pool;
    }

    public Digit getDigit(int digit) {
        boolean hasKey = this.digitMap.containsKey(digit);

        if (hasKey)
            return this.digitMap.get(digit);

        SingleDigit singleDigit = new SingleDigit(digit);

        this.digitMap.put(digit, singleDigit);

        return singleDigit;
    }
}

public class Client {

    public static void main(String[] args) {
        DigitPool pool = DigitPool.getPool();

        Digit digitA = pool.getDigit(0);
        Digit digitB = pool.getDigit(0);
        Digit digitC = pool.getDigit(0);
        Digit digitE = pool.getDigit(2);
        Digit digitF = pool.getDigit(2);

        System.out.println(digitA.equals(digitB) == true);
        System.out.println(digitA.equals(digitC) == true);
        System.out.println(digitE.equals(digitF) == true);

        digitA.display(10);
        digitE.display(3);
    }
}