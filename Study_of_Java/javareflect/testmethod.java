import java.lang.reflect.Member;
import java.lang.reflect.Method;

public class testmethod {
    public static void main(String[] args) throws Exception{
        Class cls = Users.class;
        Method[] methods = cls.getMethods();
        for(Method method : methods) {
            System.out.println(method);
        }
        System.out.println("---------------");
        Method[] method2 = cls.getDeclaredMethods();
        for(Method method : method2) {
            System.out.println(method);
        }
        System.out.println("---------------");
        Method m1=cls.getDeclaredMethod("run",null);
        System.out.println(m1);
        System.out.println("---------------");
        Method m2=cls.getMethod("eat",null);
        System.out.println(m2);
    }
}
