package com.phone;
/*
    实体类
 */
public class Person {
    private int id;
    private String name;
    private int age;
    private String sex;
    private String telnum;
    private String address;

    //虽然无参构造方法是默认的但是一旦定义有参的构造方法之后就失去了这个默认，要最好写出来重新定义一下，这样具有灵活性
    public Person(){

    }

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

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

    public String getSex() {
        return sex;
    }

    public void setSex(String sex) {
        this.sex = sex;
    }

    public String getTelnum() {
        return telnum;
    }

    public void setTelnum(String telnum) {
        this.telnum = telnum;
    }

    public String getAddress() {
        return address;
    }

    public void setAddress(String address) {
        this.address = address;
    }

    @Override
    public String toString() {
        return "Person{" +
                "id=" + id +
                ", name='" + name + '\'' +
                ", age=" + age +
                ", sex='" + sex + '\'' +
                ", telnum='" + telnum + '\'' +
                ", address='" + address + '\'' +
                '}';
    }
    /*（课程中的写法）
    StringBuffer sb = new StringBuffer();
    sb.append("序号").append(this.id).append("#").append("\t");
    sb.append("姓名").append(this.name).append("\t\t");
    sb.append("年龄").append(this.address).append("\t\t");
    sb.append("性别").append(this.sex).append("\t\t");
    sb.append("电话号码").append(this.telNum).append("\t\t");
    sb.append("地址").append(this.address);
    return sb.toString();
     */
}
