import java.util.HashMap;

class User {
    private String name;
    private String key;

    public User(String key, String name) {
        this.key = key;
        this.name = name;
    }

    public String getName() {
        return this.name;
    }

    public String getKey() {
        return this.key;
    }
}

class Parameters {
    private HashMap<String, Object> parameters;

    public Parameters() {
        this.parameters = new HashMap<String, Object>();
    }

    public void setParameter(String flag, Object value) {
        this.parameters.put(flag, value);
    }

    public Object getParameter(String flag) {
        return this.parameters.get(flag);
    }
}

interface UserRepository {
    boolean insert(String userKey, String userName);

    boolean delete(String userKey);

    User get(String userKey);

    User[] all();
}

class FakeUserRepository implements UserRepository {
    private HashMap<String, User> database;

    public FakeUserRepository() {
        this.database = new HashMap<String, User>();
    }

    public User[] all() {
        return this.database.values().toArray(new User[0]);
    }

    @Override
    public boolean delete(String userKey) {
        User user = this.database.remove(userKey);

        if (user == null)
            return false;

        return true;
    }

    @Override
    public User get(String userKey) {
        return this.database.get(userKey);
    }

    @Override
    public boolean insert(String userKey, String userName) {
        User user = this.database.put(userKey, new User(userKey, userName));

        if (user == null)
            return true;

        this.database.put(userKey, user);

        return false;
    }
}

abstract class Command {
    protected Parameters parameters;

    public Object execute(Parameters parameters) throws Exception {
        this.parameters = parameters;

        return this.action();
    }

    protected abstract Object action() throws Exception;
}

abstract class DatabaseCommand extends Command {
    protected UserRepository repository;

    public DatabaseCommand(UserRepository repository) {
        this.repository = repository;
    }
}

class NewCommand extends DatabaseCommand {
    public NewCommand(UserRepository repository) {
        super(repository);
    }

    @Override
    protected Object action() throws Exception {
        try {
            String key = (String) this.parameters.getParameter("key");
            String name = (String) this.parameters.getParameter("name");

            return this.repository.insert(key, name);
        } catch (Exception e) {
            throw new Exception("Wrong Parameters");
        }
    }
}

class DeleteCommand extends DatabaseCommand {
    public DeleteCommand(UserRepository repository) {
        super(repository);
    }

    @Override
    protected Object action() throws Exception {
        try {
            String key = (String) this.parameters.getParameter("key");

            return this.repository.delete(key);
        } catch (Exception e) {
            throw new Exception("Wrong Parameters");
        }
    }
}

class AllCommand extends DatabaseCommand {
    public AllCommand(UserRepository repository) {
        super(repository);
    }

    @Override
    protected Object[] action() throws Exception {
        return this.repository.all();
    }
}

class GetCommand extends DatabaseCommand {
    public GetCommand(UserRepository repository) {
        super(repository);
    }

    @Override
    protected Object action() throws Exception {
        try {
            String key = (String) this.parameters.getParameter("key");

            return this.repository.get(key);
        } catch (Exception e) {
            throw new Exception("Wrong Parameters");
        }
    }
}

class CliApplication {
    private UserRepository repository;

    private HashMap<String, Command> commands;

    public CliApplication(UserRepository repository) {
        this.repository = repository;
        this.commands = new HashMap<String, Command>();

        this.initiateCommands();
    }

    private void initiateCommands() {
        this.commands.put("new", new NewCommand(this.repository));
        this.commands.put("delete", new DeleteCommand(this.repository));
        this.commands.put("get", new GetCommand(this.repository));
        this.commands.put("all", new AllCommand(this.repository));
    }

    public Object run(String commandName, Parameters parameters) throws Exception {

        Command command = this.commands.get(commandName);

        if (command == null)
            throw new Exception("Command Not Found");

        return command.execute(parameters);

    }
}

public class Client {

    public static Parameters createParameters(String key, String name) {
        Parameters parameters = new Parameters();

        if (name != null)
            parameters.setParameter("name", name);

        if (name != null)
            parameters.setParameter("key", key);

        return parameters;
    }

    public static void main(String[] args) throws Exception {
        CliApplication application = new CliApplication(new FakeUserRepository());

        Parameters newParameters = createParameters("1", "Fulano");

        boolean result = (boolean) application.run("new", newParameters);

        System.out.println(result);

        User user = (User) application.run("get", newParameters);

        System.out.println(user.getKey() == "1" && user.getName() == "Fulano");

        boolean result2 = (boolean) application.run("delete", newParameters);

        System.out.println(result2);

        User[] users = (User[]) application.run("all", null);

        System.out.println(users.length == 0);

        boolean result3 = (boolean) application.run("new", newParameters);

        System.out.println(result3);

        User[] users2 = (User[]) application.run("all", null);

        System.out.println(users2.length == 1);
    }
}

/*
 * Diferença entre Strategy e Command:
 * Strategy foca em trocar a metodologia que será usada, enquanto o Command
 * executar um comando específico com outros parâmetros
 * 
 * Diferença entre State e Command:
 * State ele modifica por conta própria a estratégia a ser usanda, enquanto o
 * Command espera que seja passado qual método será usado
 * 
 */