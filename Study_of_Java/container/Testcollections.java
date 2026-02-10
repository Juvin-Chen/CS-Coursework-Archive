import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class Testcollections {
    public static void main(String[] args) {
        List<String> list = new ArrayList<>();
        list.add("a");
        list.add("c");
        list.add("b");
        System.out.println(list); // 输出整个集合
        Collections.sort(list); // 对集合进行排序，这里能直接进行排序是因为String类实现了Comparable接口

        //外部比较器的使用
        List<Student> students = new ArrayList<>();
        students.add(new Student("Alice", 22));
        students.add(new Student("Bob", 20));
        students.add(new Student("Charlie", 22));
        System.out.println("Before sorting: " + students);
        Collections.sort(students, new StudentComparator()); // 使用外部比较器进行排序
        System.out.println("After sorting: " + students); // 输出排序后的集合

        //洗牌
        Collections.shuffle(list); // 打乱集合中的元素顺序
        System.out.println("Shuffled list: " + list); // 输出打乱后的集合
        //查找元素
        int index = Collections.binarySearch(list, "b"); // 二分查找元素的位置
        if (index >= 0) {
            System.out.println("Element 'b' found at index: " + index); // 输出元素的位置
        } else {
            System.out.println("Element 'b' not found");
        }
        //反转集合
        Collections.reverse(list); // 反转集合中的元素顺序
        System.out.println("Reversed list: " + list); // 输出反转后的集合

    }
}
