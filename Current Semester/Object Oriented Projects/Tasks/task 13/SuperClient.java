class Person {
    private int id;
    private String name;

    public Person(int id, String name) {
        super();

        this.id = id;
        this.name = name;
    }

    public String whoIs() {
        return String.valueOf(this.id) + " - " + this.name;
    }
}

class Enterprise {

    private String name;
    private Person responsible;

    public Enterprise(String name, Person responsible) {
        super();

        this.name = name;
        this.responsible = responsible;

    }

    public String whoIs() {
        return this.name + "; ceo : " + this.responsible.whoIs();
    }
}

class Database {
    static Person getPerson() {
        return new Person(13, "Fulano");
    }

    static String getName() {
        return "Frederico";
    }

    static int getId() {
        return 1;
    }
}

interface EntityBuilder {
    Object createEntity();
}

class PersonBuilder implements EntityBuilder {
    public Person createEntity() {
        return new Person(Database.getId(), Database.getName());
    }

    public Person createEntity(String name) {
        return new Person(Database.getId(), name);
    }
}

class EnterpriseBuilder implements EntityBuilder {

    @Override
    public Object createEntity() {
        return new Enterprise(Database.getName(), Database.getPerson());
    }
}

class Director {

    private PersonBuilder personBuilder;
    private EnterpriseBuilder enterpriseBuilder;

    public Director() {
        this.personBuilder = new PersonBuilder();
        this.enterpriseBuilder = new EnterpriseBuilder();
    }

    public <T extends Object> T createEntity(Class<T> classType) {
        switch (classType.getName()) {
            case "Person":
                return (T) this.personBuilder.createEntity();
            case "Enterprise":
                return (T) this.enterpriseBuilder.createEntity();
            default:
                return null;
        }
    }
}

public class SuperClient {
    public static void main(String[] args) {
        Director director = new Director();

        Person person = director.createEntity(Person.class);
        Enterprise enterprise = director.createEntity(Enterprise.class);

        System.out.println(person.whoIs());
        System.out.println(enterprise.whoIs());
    }

}