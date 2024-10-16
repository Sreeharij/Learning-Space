import java.util.Arrays;

class Student{
    int rno;
    String name;
    float marks;
    Student(){
        this(10,"hello",20f);
    }
    Student(int rno,String name,float marks){
        this.rno = rno;
        this.name = name;
        this.marks = marks;
    }

    @Override
    protected void finalize() throws Throwable{
        System.out.println("Here");
    }
}



public class lec1 {
    public static void main(String[] args){
        for(int i=0;i<100000;i++){
            Student obj = new Student();
        }
    }
}