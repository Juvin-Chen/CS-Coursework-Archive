import java.util.LinkedList;
import java.util.List;

public class TestLinkedlist {
    public static void main(String[] args) {
        //基于List实现的链表
        List<Integer> list= new LinkedList<>();
        list.add(10);
        list.add(20);
        list.add(0, 5); // 在索引0处添加元素5
        System.out.println("LinkedList: " + list); // 输出整个链表
        //get方法的写法虽然一样，但是底层含义不一样，链表是没有下标的，这里的0代表的是节点的位置
        System.out.println("第一个元素: " + list.get(0)); // 获取第一个元素

        //基于Linkedlist容器的使用
        LinkedList<String> linkedList = new LinkedList<>();
        linkedList.addFirst("A");
        linkedList.addLast("B");
        linkedList.addFirst("C");  //CAB
        System.out.println("LinkedList: " + linkedList);
        System.out.println("第一个元素: " + linkedList.getFirst());
        System.out.println("最后一个元素: " + linkedList.getLast());
        String str=linkedList.removeLast(); //删除链表中最后一个元素并返回这个元素
        System.out.println(str);
        System.out.println(linkedList);
        linkedList.removeLast();
        System.out.println("After removing last element: " + linkedList);

        //pop方法等效于removefirst，而且也会返回这个元素
        System.out.println(linkedList.pop()); // 删除并返回第一个元素
        linkedList.add("D");
        linkedList.push("E");
        System.out.println("After push: " + linkedList); // 在链表头部添加元素
    }

}
