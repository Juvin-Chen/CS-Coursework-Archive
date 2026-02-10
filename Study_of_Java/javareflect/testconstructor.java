import java.lang.reflect.Constructor;
import java.lang.reflect.Field;

class Users{
    private String name;
    public int age;

    public Users() {
        this.name = "default";
        this.age = 0;
    }

    public Users(String name, int age) {
        this.name = name;
        this.age = age;
    }

    private Users(int age) {
        this.age = age;
    }

    private void run(){
        System.out.println("run method");
    }
    public void eat(){
        System.out.println("eat method");
    }
}

public class testconstructor {
    public static void main(String[] args) throws Exception {
       Class cls = Users.class;
       Field field2=cls.getField("age");
       //对象实例化
       Users user = (Users) cls.getDeclaredConstructor().newInstance();
       field2.set(user, 18);
       System.out.println("age:"+field2.get(user));


    }
}
