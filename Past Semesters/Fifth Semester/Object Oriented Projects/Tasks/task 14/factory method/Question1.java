interface HashMethod {
    int gen(int data);
}

class HashMD5 implements HashMethod {
    @Override
    public int gen(int data) {
        return data * 5;
    }
}

class HashSHA2 implements HashMethod {
    @Override
    public int gen(int data) {
        return data * 2;
    }
}

class HashCRC32 implements HashMethod {
    @Override
    public int gen(int data) {
        return data * 32;
    }
}

class HashFactory {
    static public HashMethod getHash(String hashType) {
        switch (hashType) {
            case "md5":
                return new HashMD5();
            case "sha2":
                return new HashSHA2();
            case "crc32":
                return new HashCRC32();
            default:
                return null;
        }
    }
}

public class Question1 {

    public static void main(String[] args) {
        HashMethod md5Method = HashFactory.getHash("md5");
        HashMethod sha2Method = HashFactory.getHash("sha2");
        HashMethod crc32Method = HashFactory.getHash("crc32");

        System.out.println(md5Method.gen(5) == 25);
        System.out.println(sha2Method.gen(5) == 10);
        System.out.println(crc32Method.gen(5) == 160);
    }
}