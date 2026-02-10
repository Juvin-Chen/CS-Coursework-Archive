import java.util.*;

public class Testhashset {
    public static void main(String[] args) {
        //基于set的使用
        /*
        使用Set集合来存储不重复的元素，Set是一个无序的集合，它不允许重复元素。
        这段代码中String类型的元素没有被重复添加，核心原因是String类已经重写了hashCode()和equals()方法 ，完全符合HashSet对 “重复元素” 的判断标准。
         */
        Set<String> set = new HashSet<>(); // 创建一个 HashSet 对象
        set.add("apple"); // 添加元素
        set.add("banana");
        //输出的顺序是不一定的 不一定和你的添加顺序一致，因为它是无序的
        System.out.println(set);
        set.add("apple"); // 尝试添加重复元素
        System.out.println(set); // 输出 HashSet，重复元素不会被添加
        set.remove("banana"); // 删除元素
        System.out.println(set.size());
        //一些其他方法不再一一演示，如差集并集等操作，可参考表格

        /*基于Hashset的使用，实例化,我们在使用自定义对象时，必须重写hashCode和equals方法，否则无法正确识别重复元素，它的底层是通过hash值来判断元素是否相同的基于hashmap
        如果没有重写hashcode和equals方法，用的就是Object的了，那么即使两个对象的属性值完全相同，它们在内存中的地址不同，hash值也会不同，因此HashSet会认为它们是不同的对象，从而允许重复添加。
        自定义一定要记得重写方法！
         */
        Set<Users> hashset= new HashSet<>();
        Users user1 = new Users("Alice", 30);
        Users user2 = new Users("Bob", 25);
        Users user3 = new Users("Alice", 30); // 重复的用户
        hashset.add(user1); // 添加用户
        hashset.add(user2);
        hashset.add(user3); // 尝试添加重复用户
        System.out.println(hashset); // 输出 HashSet，重复用户不会被添加
        System.out.println("Size of hashset: " + hashset.size()); // 输出 Hash

        //Treeset容器的使用
        Set<String> treeSet = new TreeSet<>(); // 创建一个 TreeSet 对象
        treeSet.add("apple"); // 添加元素
        treeSet.add("cherry");
        treeSet.add("banana");
        //String下面定义的按照字母的unicode码进行排序
        System.out.println(treeSet); // 输出 TreeSet，元素会按照自然顺序排序，这里就是按照string自己定义的元素自身的比较规则

        //通过元素自身实现比较规则来排序
        //自定义对象:如果要自定义比较规则，可以使用Comparator接口来实现
        Set<Users> treeSetUsers = new TreeSet<>();
        treeSetUsers.add(new Users("Charlie", 28));
        treeSetUsers.add(new Users("Alice", 30));
        treeSetUsers.add(new Users("Bob", 25));
        // 这里的 Users 类需要实现 Comparable 接口或提供 Comparator 来定义排序规则，简而言之就是没有给定比较规则时，自定义对象无法被添加
        System.out.println(treeSetUsers); // 输出 TreeSet，元素会按照自定义的

        //通过比较器定义比较规则时，我们需要单独创建一个比较器，比较器需要实现Comparator接口中的compare方法来定义比较规则。在实例化TreeSet时将比较器对象交给TreeSet来完成元素的排序处理。此时元素自身就不需要实现比较规则了。
        //创建TreeSet容器时需要给定比较器对象
        Set<Student> studentSet = new TreeSet<>(new StudentComparator()); // 使用自定义比较器
        studentSet.add(new Student("Alice", 22));
        studentSet.add(new Student("Bob", 20));
        studentSet.add(new Student("Charlie", 22)); // 添加学生对象
        System.out.println(studentSet); // 输出 TreeSet，元素会按照自定义的比较

    }
}
class Users implements Comparable<Users> {
    private String name;
    private int age;

    public Users(String name, int age) {
        this.name = name;
        this.age = age;
    }

    @Override
    public String toString() {
        return "Users{" +
                "name='" + name + '\'' +
                ", age=" + age +
                '}';
    }

    // Getter和Setter方法
    public String getName() {
        return name;
    }
    public void setName(String name) {
        this.name = name;
    }
    public int getAge() {
        return age;
    }
    public void setAge(int age) {
        this.age = age;
    }
    // 重写hashCode和equals方法以确保HashSet能正确识别重复元素
    @Override
    public int hashCode() {
        return name.hashCode() + age; // 简单的哈希计算
    }

    @Override
    public boolean equals(Object obj) {
        if (this == obj) return true;
        if (!(obj instanceof Users)) return false;
        Users user = (Users) obj;
        return age == user.age && name.equals(user.name);
    }

    @Override
    //正数表示当前对象大于比较对象，负数表示小于，0表示相等
    public int compareTo(Users o) {
        if(this.age != o.age) {
            return Integer.compare(this.age, o.age); // 按年龄升序排序
        }
        return this.name.compareTo(o.name); // 如果年龄相同，则按名字升序
    }
}
//创建比较器，以下是用于示例所创建的类
class Student{
    String name;
    int age;

    @Override
    public boolean equals(Object o) {
        if (o == null || getClass() != o.getClass()) return false;
        Student student = (Student) o;
        return age == student.age && Objects.equals(name, student.name);
    }

    @Override
    public int hashCode() {
        return Objects.hash(name, age);
    }

    public Student(String name, int age) {
        this.name = name;
        this.age = age;
    }
}
//定义外部比较器
class StudentComparator implements Comparator<Student> {
    @Override
    public int compare(Student s1, Student s2) {
        // 先按年龄排序，如果年龄相同则按名字排序
        if (s1.age != s2.age) {
            return Integer.compare(s1.age, s2.age);
        }
        return s1.name.compareTo(s2.name);
    }
}