import java.util.*;

public class HashMapDemo {
    public static void main(String[] args) {
        Map<String, String> m = new HashMap<String, String>();
        m.put("Dobby", "Elf");
        System.out.println(m.get("Dobby"));
        for(int i = 0; i < m.entrySet().size(); i++){
            System.out.println(m.keySet().iterator());
        }
    }
}
