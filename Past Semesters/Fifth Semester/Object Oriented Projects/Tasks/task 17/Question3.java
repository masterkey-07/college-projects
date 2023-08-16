// Victor Jorge 
// Leonardo Fonseca

import java.io.File;
import java.io.FileWriter;

abstract class PrinterClassBuilder {
    private String className;
    private String classMessage;
    protected StringBuilder classBuilder;

    public PrinterClassBuilder(String name, String message) {
        this.className = name;
        this.classMessage = message;
        this.classBuilder = new StringBuilder();
    }

    private void createMethod() {
        this.classBuilder.append("public void hello(String message)");
        this.addOpenBracket();
        this.classBuilder.append("System.out.println(\"" + this.classMessage + "\");");
        this.addCloseBracket();
    }

    protected void addOpenBracket() {
        this.classBuilder.append('{');
    }

    protected void addCloseBracket() {
        this.classBuilder.append('}');
    }

    private void createClassName() {
        this.classBuilder.append("class " + this.className + " ");
    }

    private void buildClass() {
        String buffer = this.classBuilder.toString();

        String filePath = "./" + this.className + ".java";

        File file = new File(filePath);

        try {
            file.createNewFile();

            FileWriter writer = new FileWriter(filePath);

            writer.write(buffer);

            writer.close();
        } catch (Exception e) {
            System.out.println("Class " + this.className + " já foi criado.");
        }
    }

    public void createClass() {
        this.createClassName();
        this.addOpenBracket();
        this.createMethod();
        this.addCloseBracket();
        this.buildClass();
    }

}

class SimpleClassBuilder extends PrinterClassBuilder {
    public SimpleClassBuilder(String name, String message) {
        super(name, message);
    }

}

public class Question3 {

    public static void main(String[] args) {
        SimpleClassBuilder simpleBuilder = new SimpleClassBuilder("NovaNovaClasse", "Olá Mundo");

        simpleBuilder.createClass();
    }
}