package com.phone;

import java.util.*;

/*
核心业务类
 */
public class Operate {
    private List<Person> list;
    public Operate(){
        this.list=new ArrayList<>();
    }

    //用户添加记录的业务逻辑控制
    public void addLogic(){

    }

    //用户查找记录的业务逻辑控制
    public void searchLogic(){

    }

    //用户修改记录的业务逻辑控制
    public void modifyLogic(){

    }

    //用户删除记录的业务逻辑控制
    public void deleteLogic(){

    }

    //用户排序记录的业务逻辑控制
    public void orderLogic(){

    }
    //添加新记录信息
    public void addNew(Person p){
        list.add(p);
    }
    //查询全部记录
    public void showAll(){

    }
    //按姓名查找
    public void searchByName(String name){

    }
    //按年龄查找
    public void searchByAge(int age){

    }
    //按性别查找
    public void searchBySex(String sex){

    }
    //按号码查找
    public void searchByTelnum(String telnum){

    }
    //按地址查找
    public void searchByAddress(String address){

    }
    //修改指定记录
    public void modifyPerson(int id,Person newPerson){

    }
    //删除指定记录
    public void deletePerson(int id){

    }
    //按姓名排序
    public void orderByName(){

    }
    //按年龄排序
    public void orderByAge(){

    }
    //按性别排序
    public void orderBySex(){

    }

    //内部类，定义三个比较器
    //按姓名，年龄，性别排序
    class NameComparator implements Comparator<Person>{
        @Override
        public int compare(Person p1, Person p2) {
            return p1.getName().compareTo(p2.getName());
        }
    }
    class AgeComparator implements Comparator<Person>{
        @Override
        public int compare(Person p1, Person p2) {
            return p1.getAge()-p2.getAge();
        }
    }
    class SexComparator implements Comparator<Person>{
        @Override
        public int compare(Person p1, Person p2) {
            return p1.getSex().compareTo(p2.getSex());
        }
    }
}
