//import java.util.Scanner;
//import java.util.Vector;
//import java.util.Iterator;

import java.util.*;

class Main {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);

    //Vector<Integer> v = new Vector<Integer>(); //이렇게 쓰는게 귀찮아서 아래처럼쓴다.
    var v = new Vector<Integer>(); // variable은 초기화 하면서 써야됨. var v; 이런식으로는 못씀.

    while(true){ // 내가 0입력하기전까진 무한반복해야하니까 while
      System.out.print("강수량 입력 (0 입력시 종료)>>");
      int n = scanner.nextInt(); //정수값아닐경우를 대비해 원래라면 try catch문 넣어야된다.
      if(n == 0) break; // 0입력시 종료되는문. while밖으로 나감

      v.add(n);
      print(v);

    }
  }

  public static void print(Vector<Integer> v) {
    int sum = 0;

    //Iterator<Integer> = v.iterator(); //이렇게쓰기 귀찮아서 아래처럼 쓴다.
    var it = v.iterator();

    while(it.hasNext()) {
      int n = it.next();
      System.out.print(n + " ");
      sum += n;
    }

    System.out.println();
    System.out.println("현재 평균 " + (sum/v.size()));
  }

}
