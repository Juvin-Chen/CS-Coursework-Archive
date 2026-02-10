import java.util.HashMap;
import java.util.Map;
import java.util.Set;
import java.util.TreeMap;

public class Testmap {
    public static void main(String[] args) {
        //实例化hashmap
        Map<String,String> map=new HashMap<>();

        map.put("a","A");
        map.put("b","B");
        map.put("a","C"); //key与之前出现过的相同的value被替换
        System.out.println(map);
        System.out.println(map.size());

        //获取容器中的元素
        //1 利用key
        String v=map.get("a");
        System.out.println(v);
        //2循环
        Set<String> keySet=map.keySet();
        for(String i:keySet){
            System.out.println(i+"  "+map.get(i));
        }
        //3使用entrySet（一个键值对对象），它是Map的内部接口，返回一个包含所有键值对的集合
        Set<Map.Entry<String,String>> entrySet=map.entrySet();
        //遍历entrySet
        for(Map.Entry<String,String> e:entrySet){
            String key= e.getKey(); //获取键
            String value= e.getValue(); //获取值
            System.out.println("Key: " + key + ", Value: " + value);
        }

        //并集等操作参考之前的代码
        //删除键为"a"的元素，并返回被删除的值
        System.out.println(map.remove("a"));
        //判断key和value是否存在
        System.out.println(map.containsKey("B"));
        System.out.println(map.containsValue("b"));
        map.clear();

        /*
        补充内容：
        HashTable类和HashMap用法几乎一样，底层实现几乎一样，只不过HashTable的方法添加了synchronized关键字确保线程同步检查，效率较低。

        HashMap与HashTable的区别
        - HashMap: 线程不安全，效率高。允许key或value为null
        - HashTable:线程安全，效率低。不允许key或value为null
        */

        /*
        TreeMap下面所用到的两个类包括构造器，可参考hashmap代码里面的类的内容
         */

        //Treemap也有两种比较排序的方式
        Map<Users, String> treeMap = new TreeMap<>();
        treeMap.put(new Users("Alice", 30), "Engineer");
        treeMap.put(new Users("Bob", 25), "Designer");
        treeMap.put(new Users("Charlie", 28), "Manager");
        // TreeMap会根据Users类的自然顺序（需要实现Comparable接口）或提供的Comparator进行排序
        for (Map.Entry<Users, String> entry : treeMap.entrySet()) {
            Users user = entry.getKey();
            String profession = entry.getValue();
            System.out.println("User: " + user.getName() + ", Age: " + user.getAge() + ", Profession: " + profession);
        }
        //或者第二种方式，外部构造器的方式
        Map<Student, String> studentMap = new TreeMap<>(new StudentComparator());
        studentMap.put(new Student("Alice", 22), "A");
        studentMap.put(new Student("Bob", 20), "B");
        studentMap.put(new Student("Charlie", 22), "C");
        Set<Student> studentSet = studentMap.keySet();
        for (Student student : studentSet) {
            String grade = studentMap.get(student);
            System.out.println("Student: " + student.name + ", Age: " + student.age + ", Grade: " + grade);
        }

        // TreeMap的键必须是可比较的，或者提供一个Comparator来定义排序
    }
}
