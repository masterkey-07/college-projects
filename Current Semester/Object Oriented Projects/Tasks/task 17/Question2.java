// Victor Jorge 
// Leonardo Fonseca

import java.io.File;
import java.io.FileWriter;

abstract class ClassBuilder {
    private String className;
    protected StringBuilder classBuilder;

    public ClassBuilder(String className) {
        this.className = className;
        this.classBuilder = new StringBuilder();
    }

    protected abstract void createImports();

    protected abstract void createProperties();

    protected abstract void createMethods();

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
        this.createImports();
        this.createClassName();
        this.addOpenBracket();
        this.createProperties();
        this.createMethods();
        this.addCloseBracket();
        this.buildClass();
    }

}

class SimpleClassBuilder extends ClassBuilder {
    public SimpleClassBuilder(String className) {
        super(className);
    }

    @Override
    protected void createImports() {
        this.classBuilder.append("import java.util.*;");
    }

    @Override
    protected void createMethods() {
        this.classBuilder.append("public void hello(String message)");
        this.addOpenBracket();
        this.addCloseBracket();
    }

    @Override
    protected void createProperties() {

    }

}

public class Question2 {

    public static void main(String[] args) {
        SimpleClassBuilder simpleBuilder = new SimpleClassBuilder("NovaClasse");

        simpleBuilder.createClass();
    }
}