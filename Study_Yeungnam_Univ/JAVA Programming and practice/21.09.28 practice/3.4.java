import java.util.Scanner;
import java.util.InputMismatchException;

class Main {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);


    while(true){
      System.out.print("곱하고자 하는 두 수 입력 >>");
      try{
      
        int n = scanner.nextInt();
        int m = scanner.nextInt();
        System.out.println(n + "x" + m + "=" + n*m);
        break; // 이게 있어야 정수값 들어오고 정상적인 계산 1번한뒤에 끝나게해준다.
      }
      catch(InputMismatchException e){
        System.out.println("정수값을 입력하세요");
        scanner.nextLine(); //이게 실수값이 들어간 부분의 버퍼를 비워준다. 이거 없으면 무한루프
      }
    }
    //scanner.close();
  }
}
