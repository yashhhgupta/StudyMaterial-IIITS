class Hacker {
    String hackerName;
    static Hacker[] hackers = new Hacker[3];
    static int hackercount = 0;
    int system;

    public Hacker(String hackerName, int system) {
        this.hackerName = hackerName;
        this.system = system;
    }

    public static int avg() {

        int avg = 0, k = 0;
        for (int i = 0; i < hackercount; i++) {
            k += hackers[i].system;
        }
        avg = k / hackercount;
        return avg;
    }
}

public class hackerMain {

    public static void main(String[] args) {
        Hacker.hackers[Hacker.hackercount++] = new Hacker("vish", 6);
        Hacker.hackers[Hacker.hackercount++] = new Hacker("ish", 4);
        Hacker.hackers[Hacker.hackercount++] = new Hacker("vih", 5);
        int k;
        k = Hacker.avg();
        System.out.println(k);
    }

}