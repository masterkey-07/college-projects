//Victor Jorge - 156740
//Leonardo Fonseca - 133680

import java.util.Enumeration;
import java.util.Iterator;
import java.util.Vector;

class LegacyCollector {
    private Enumeration<Integer> data;

    public LegacyCollector() {
        Vector<Integer> data = new Vector<Integer>();

        data.add(1);
        data.add(2);
        data.add(3);
        data.add(4);
        data.add(5);

        this.data = data.elements();
    }

    public Enumeration<Integer> getData() {
        return this.data;
    }
}

class AdapterData implements Iterator {
    private Enumeration<Integer> data;

    public AdapterData(Enumeration<Integer> data) {
        this.data = data;
    }

    @Override
    public boolean hasNext() {
        return data.hasMoreElements();
    }

    @Override
    public Integer next() {
        return data.nextElement();
    }
}

class ModernCollector {

    private LegacyCollector collector;

    public ModernCollector() {
        this.collector = new LegacyCollector();
    }

    public Iterator<Integer> getData() {
        Enumeration<Integer> data = this.collector.getData();

        return new AdapterData(data);
    }

}

public class Question2 {

    public static void main(String[] args) {
        ModernCollector collector = new ModernCollector();

        Iterator<Integer> data = collector.getData();

        int sum = 0;

        while (data.hasNext())
            sum += data.next();

        if (sum == 15)
            System.out.println("Sucess");
        else
            System.out.println("Fail");

    }

}