// 따로 Grade.java파일 만드심.

import java.util.Scanner;

class Test {
  
}

class Main {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);

    System.out.print("수학, 과학, 영어 순으로 3개의 점수 입력>>");
    int math = scanner.nextInt();
    int science = scanner.nextInt();
    int english = scanner.nextInt();
    Grade me = new Grade(math, science, english);

    // 여기서 me.math = 100;으로 해도 안된다. private int math니까..
    // public으로 바꾸거나 아무것도 안쓰고 그냥 int math로 하면 가능하다.
    System.out.println("평균은 " + me.average()); // average()는 평균을 계산하여 리턴

     scanner.close();
  }
}



/* 내꺼 실패..
import java.util.Scanner;

class Main {
  private int math, science, english;
  public class average {
    Grade =
  }


  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);

    System.out.print("수학, 과학, 영어 순으로 3개의 점수 입력>>");
    int math = scanner.nextInt();
    int science = scanner.nextInt();
    int english = scanner.nextInt();
    Grade me = new Grade(math, science, english);
    System.out.println("평균은 " + me.average()); // average()는 평균을 계산하여 리턴

     scanner.close();
  }
}
*/
