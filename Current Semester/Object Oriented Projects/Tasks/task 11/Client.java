import java.io.BufferedReader;
import java.io.FileReader;
import java.util.ArrayList;
import java.util.List;

abstract class CharCounter {
    private String name;
    private List<String[]> response;
    private CharCounter counter;

    public CharCounter(String name, CharCounter processor) {
        this.name = name;
        this.response = null;
        this.counter = processor;
    }

    protected abstract int count(String content);

    public List<String[]> process(String content) {
        List<String[]> output;

        if (this.response == null)
            output = this.counter.process(content);
        else
            output = this.response;

        int value = this.count(content);

        String[] array = new String[2];

        array[0] = this.name;
        array[1] = Integer.toString(value);

        output.add(array);

        return output;
    }
}

class LetterProcessor extends CharCounter {
    private char letter;

    public LetterProcessor(char letter, String name, CharCounter processor) {
        super(name, processor);

        this.letter = letter;
    }

    @Override
    protected int count(String content) {
        int counter = 0;
        for (int i = 0; i < content.length(); i++)
            if (content.charAt(i) == this.letter)
                counter++;

        return counter;
    }
}

public class Client {

    private static String readFile(String File) throws Exception {

        StringBuilder builder = new StringBuilder();

        FileReader fileReader = new FileReader(File);

        BufferedReader bufferReader = new BufferedReader(fileReader);

        String line;

        while ((line = bufferReader.readLine()) != null)
            builder.append(line);

        bufferReader.close();

        return builder.toString();
    }

    public static CharCounter buildCounter() {
        CharCounter letterACounter = new LetterProcessor('a', "Contador de 'a'", null);

        CharCounter spaceCounter = new LetterProcessor(' ', "Contador de ' '", letterACounter);

        CharCounter pointCounter = new LetterProcessor('.', "Contador de '.'", spaceCounter);

        return pointCounter;
    }

    public static void main(String[] args) {
        try {
            String content = readFile(args[0]);

            CharCounter counter = buildCounter();

            List<String[]> response = counter.process(content);

            for (int index = 0; index < response.size(); index++) {
                String[] result = response.get(index);

                System.out.println(result[0] + " : " + result[1]);
            }

        } catch (Exception e) {
            System.out.println(e.getMessage());
        }

    }
}