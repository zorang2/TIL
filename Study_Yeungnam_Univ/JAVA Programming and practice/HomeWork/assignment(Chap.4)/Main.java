import java.util.*;

public class Main {
  public static void main(String[] args){
    Scanner scanner = new Scanner(System.in);
    Menu sm = new Menu(); // Menu 객체 생성
    
    
    System.out.println("명품콘서트홀 예약 시스템입니다.");

    while (true) {
      System.out.print("예약:1, 조회:2, 취소:3, 끝내기:4 >> ");
      int m = scanner.nextInt();
      switch (m) {
        case 1:
          sm.reservation(); //reservation 메소드 호출 (예약)
          break;
        case 2:
          sm.seat_check(); // check 메소드 호출 (조회)
          break;
        case 3:
          sm.seat_cancle(); // cancle 메소드 호출 (취소)
          break;
        case 4:
          return; // 끝내기!
        default: // 예외처리
          System.out.println("잘못 입력하셨습니다. (1~4) ");
          continue;
      }  
    }
  }
}
