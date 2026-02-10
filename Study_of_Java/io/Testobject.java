import java.io.*;
import java.io.ObjectOutputStream;
//对象流的作用是将对象序列化为字节流，以便存储或传输，并可以从字节流中反序列化出对象。它主要用于在Java中进行对象的持久化存储或网络传输。
public class Testobject {
    public static void main(String[] args) {
        /*
        我们前边学到的数据流只能实现对基本数据类型和字符串类型的读写，并不能读取对象（字符串除外），如果要对某个对象进行读写操作，我们需要学习一对新的处理流：ObjectInputStream/ObjectOutputStream。
        处理基本数据类型数据，对象也可以处理data类型的数据。
        ObjectInputStream/ObjectOutputStream处理基本数据类型。
        */
        //创建对象输出流对象与文件字节输出流对象。需要的节点流必须要是字节流类型
        try(ObjectOutputStream oos = new ObjectOutputStream(new FileOutputStream("d:/data2"));
            //创建对象输入流对象与文件字节输入流对象
            ObjectInputStream ois = new ObjectInputStream(new FileInputStream("d:/data2"))){

            //将如下数据写入到文件中
            oos.writeInt(10);
            oos.writeDouble(Math.random());
            oos.writeChar('a');
            oos.writeBoolean(true);
            oos.writeUTF("你好Oldlu");
            oos.flush();

            //必须要按照写入的顺序读取数据
            System.out.println("int: "+ois.readInt());
            System.out.println("double: "+ois.readDouble());
            System.out.println("char: "+ois.readChar());
            System.out.println("boolean: "+ois.readBoolean());
            System.out.println("String: "+ois.readUTF());
        }catch(IOException e){
            e.printStackTrace();
        }

        /*
        注意:
        对象流不仅可以读写对象，还可以读写基本数据类型。
        读写基本数据类型时，读取的顺序一定要与写入的顺序一致，否则不能正确读取数据。
        */


        //对象序列化与反序列化
        //创建对象输出字节流与文件输出字节流对象
        //如果想用对多个对象进行序列化，可以使用对象的数组，但是前提是每一个对象必须要实现Serializable接口
        try(ObjectOutputStream oos = new ObjectOutputStream(new FileOutputStream("d:/data3"))){
            //创建Users对象
            Users users = new Users(1,"Oldlu","18");
            //将对象序列化到文件中
            oos.writeObject(users);
            //刷新
            oos.flush();
        }catch(IOException e){
            e.printStackTrace();
        }

        //反序列化
        //创建对象输入字节流与文件字节输入流对象
        try(ObjectInputStream ois = new ObjectInputStream(new FileInputStream("d:/data3"))){
            //将对象反序列化到内存中
            Users users = (Users) ois.readObject(); //ObjectInputStream 的 readObject() 方法是一个通用方法 —— 它可以读取任何可序列化的对象（比如 Users、String、List 等），因此 Java 设计它的返回值为 Object 类型（所有类的父类）。
            System.out.println(users);
        }catch(Exception e){
            e.printStackTrace();
        }
/*
补充：如果是对数组的写法
序列化： oos.writeObject(usersArray); // 直接写入整个数组
反序列化： 直接读取整个数组并强转类型
        Users[] deserializedArray = (Users[]) ois.readObject();

        // 遍历输出数组中的对象
        System.out.println("反序列化的数组内容：");
        for (Users user : deserializedArray) {
            System.out.println(user);
        }
 */
    }
}
class Users implements Serializable {
    private int userid;
    private String username;
    private String userage;

    public Users(int userid, String username, String userage) {
        this.userid = userid;
        this.username = username;
        this.userage = userage;
    }
    public Users() {
    }
    public int getUserid() {
        return userid;
    }
    public void setUserid(int userid) {
        this.userid = userid;
    }
    public String getUsername() {
        return username;
    }
    public void setUsername(String username) {
        this.username = username;
    }
    public String getUserage() {
        return userage;
    }
    public void setUserage(String userage) {
        this.userage = userage;
    }
    @Override
    public String toString() {
        return "Users{" +
                "userid=" + userid +
                ", username='" + username + '\'' +
                ", userage='" + userage + '\'' +
                '}';
    }
}
