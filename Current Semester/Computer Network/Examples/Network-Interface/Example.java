import java.net.NetworkInterface;
import java.net.SocketException;
import java.util.Enumeration;

public class Example {

    public static void main(String[] args) throws SocketException {
        Enumeration<NetworkInterface> networkInterfaces = NetworkInterface.getNetworkInterfaces();

        NetworkInterface networkInterface;

        while (networkInterfaces.hasMoreElements()) {
            networkInterface = networkInterfaces.nextElement();

            System.out.println(networkInterface.getName());
            System.out.println(networkInterface.getIndex());
        }
    }

}