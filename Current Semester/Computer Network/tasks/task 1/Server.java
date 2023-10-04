import java.io.*;
import java.net.*;
import java.util.*;

public class Server {

    public static void main(String[] args) {
        final int port = 5000;

        try {
            try (ServerSocket server = new ServerSocket(port)) {
                Set<PrintWriter> clients = new HashSet<>();

                System.out.println("Server is running on port " + port);

                while (true) {
                    Socket socket = server.accept();

                    ClientHandler handler = new ClientHandler(socket, clients);

                    handler.start();
                }
            }

        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    private static class ClientHandler extends Thread {
        private Socket socket;
        private PrintWriter myWriter;
        private Set<PrintWriter> clients;

        public ClientHandler(Socket socket, Set<PrintWriter> clients) {
            this.socket = socket;
            this.clients = clients;
        }

        @Override
        public void run() {
            try {
                OutputStream outputStream = socket.getOutputStream();

                myWriter = new PrintWriter(outputStream, true);

                // it runs in a thread safe way
                synchronized (this.clients) {
                    this.clients.add(myWriter);
                }

                InputStream inputSream = socket.getInputStream();

                InputStreamReader inputStreamReader = new InputStreamReader(inputSream);

                BufferedReader bufferedReader = new BufferedReader(inputStreamReader);

                String message;

                while ((message = bufferedReader.readLine()) != null) {
                    // it runs in a thread safe way
                    synchronized (this.clients) {
                        for (PrintWriter writer : this.clients) {

                            if (myWriter != writer)
                                writer.println(message);
                        }
                    }
                }

            } catch (IOException e) {
                e.printStackTrace();
            } finally {
                // it runs here when the client disconnects

                // it runs in a thread safe way
                synchronized (this.clients) {
                    this.clients.remove(myWriter);
                }

                try {
                    socket.close();
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
        }
    }

}
