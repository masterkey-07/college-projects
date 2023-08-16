import java.util.ArrayList;

class EcoEco implements Cloneable {
    private ArrayList<String> voices;

    public EcoEco() {
        this.voices = new ArrayList<String>();
    }

    public void addEco(String message) {
        this.voices.add(message);
    }

    public String eco() {
        StringBuilder builder = new StringBuilder();

        for (String string : this.voices)
            builder.append(string + "\n");

        return builder.toString();
    }

    @Override
    public Object clone() throws CloneNotSupportedException {
        EcoEco cloned = (EcoEco) super.clone();

        cloned.voices = (ArrayList<String>) this.voices.clone();

        return cloned;
    }
}

public class Client {

    public static void main(String[] args) throws Exception {
        EcoEco eco = new EcoEco();

        eco.addEco("A");
        eco.addEco("AA");
        eco.addEco("AAA");

        System.out.println(eco.eco().compareTo("A\nAA\nAAA\n") == 0);

        try {
            EcoEco newEco = (EcoEco) eco.clone();

            newEco.addEco("B");
            newEco.addEco("BB");
            newEco.addEco("BBB");

            System.out.println(newEco.eco().compareTo("A\nAA\nAAA\nB\nBB\nBBB\n") == 0);
        } catch (Exception e) {
            System.out.println(e.getMessage());
        }

        eco.addEco("C");
        eco.addEco("CC");
        eco.addEco("CCC");

        System.out.println(eco.eco().compareTo("A\nAA\nAAA\nC\nCC\nCCC\n") == 0);

    }
}