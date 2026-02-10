import java.lang.reflect.InvocationTargetException;
import java.lang.reflect.Method;

class Reflect{
    public void method1() {
        System.out.println("This is method 1");
    }
    public void method2() {
        System.out.println("This is method 2 ");
    }
    public void method3() {
        System.out.println("This is private method 3");
    }
}
public class reflectexample {
    public static void main(String[] args) throws InvocationTargetException, IllegalAccessException {
        Reflect rd = new Reflect();
        if(args != null && args.length > 0){
            //获取ReflectDemo的Class对象
            Class clazz = rd.getClass();
            //通过反射获取ReflectDemo下的所有方法
            Method[] methods = clazz.getMethods();
            for(String str :args){
                for(int i=0;i<methods.length;i++){
                    if(str.equalsIgnoreCase(methods[i].getName())){
                        methods[i].invoke(rd);
                        break;
                    }
                }
            }
        }else{
            rd.method1();
            rd.method2();
            rd.method3();
        }
    }
}
