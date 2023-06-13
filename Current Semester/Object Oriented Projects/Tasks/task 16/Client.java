import java.util.Stack;

class Memento {
    private int state;

    public Memento(int state) {
        this.state = state;
    }

    public int getState() {
        return state;
    }
}

class DataEditor {
    private int data;

    public DataEditor(int data) {
        this.data = data;
    }

    public void changeData(int newData) {
        this.data = newData;
    }

    public Memento createMemento() {
        return new Memento(this.data);
    }

    public int getData() {
        return this.data;
    }
}

public class Client {

    public static void main(String[] args) {
        Stack<Memento> history = new Stack<Memento>();

        DataEditor editor = new DataEditor(0);

        history.add(editor.createMemento());

        editor.changeData(10);

        history.add(editor.createMemento());

        editor.changeData(100);

        history.add(editor.createMemento());

        editor.changeData(1000);

        System.out.println(editor.getData() == 1000);

        editor.changeData(history.pop().getState());

        System.out.println(editor.getData() == 100);

        editor.changeData(history.pop().getState());

        System.out.println(editor.getData() == 10);

        editor.changeData(history.pop().getState());

        System.out.println(editor.getData() == 0);
    }
}

/*
 * O Design Pattern Memento permite salvar um ou mais estados
 * de um objeto, de tal forma permitindo realizar a ação de restauração de algum
 * estado,
 * e para a divisão de responsabilidade dessa função, é usado uma nova classe
 * para conter o estado.
 * Tal funcionalidade pode ser aplicada em vários contextos, como sistema de
 * edições,
 * algoritmos para encontrar a melhor solução para um problema utilizando de
 * metodologias como
 * backtracking ou programação dinâmica com memorização, dentre outros.
 */