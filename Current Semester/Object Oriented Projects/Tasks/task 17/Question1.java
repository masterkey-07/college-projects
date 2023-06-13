// Victor Jorge 
// Leonardo Fonseca

import java.util.Arrays;
import java.util.Comparator;

class LastWordComparator implements Comparator<String> {
    public int compare(String palavra1, String palavra2) {
        char letra1 = palavra1.charAt(palavra1.length() - 1);
        char letra2 = palavra2.charAt(palavra2.length() - 1);

        if (letra1 > letra2)
            return 1;
        if (letra1 < letra2)
            return -1;
        return 0;
    }
}

public class Question1 {
    public static void main(String[] args) {
        String[] words = { "xe", "xd", "xc", "xb", "xa" };

        Arrays.sort(words, new LastWordComparator());

        System.out.println(0 == words[0].compareTo("xa"));
        System.out.println(0 == words[1].compareTo("xb"));
        System.out.println(0 == words[2].compareTo("xc"));
        System.out.println(0 == words[3].compareTo("xd"));
        System.out.println(0 == words[4].compareTo("xe"));
    }
}
