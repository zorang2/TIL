import java.util.*;

public class Menu {
  Scanner scanner = new Scanner(System.in); // Scanner로 받아오는 객체생성
  String seats[][] = new String[3][10]; // S,A,B석 각각10개니까 3x10 array생성.

  public Menu() { // 생성자
    for (int i = 0; i <= 2; i++){ // S, A, B석 3행
      for (int j = 0; j <=9; j++) // 0~9 총 10행
        seats[i][j] = "---"; // ---로 초기화
    }
  } //생성자는 return type없음


  void seats_view(int n) { //S, A, B석 별로 좌석보여줌
    switch (n) { //S = 1, A = 2, B = 2니까
      case 1: //S석 case고
        System.out.print("S>> "); 
        break; //실행되면 빠져나가고
      case 2: //A석 case고
        System.out.print("A>> ");
        break; //실행되면 빠져나가고
      case 3: //B석 case고
        System.out.print("B>> ");
        break; //실행되면 빠져나가고
    }
    for (int j = 0; j <= 9; j++){ //for문 돌려서 초기화해놨던 --- 를 case문에 이어서 바로 출력하게함.
      System.out.print(this.seats[n-1][j] + "  "); // 각각 구분해야되니까 스페이스바까지 출력함.
    }
    System.out.println();
  }

  void reservation() { //예약
    System.out.print("좌석구분 S(1), A(2), B(3) >> ");
    int input_number = scanner.nextInt(); //입력받은 int 변수에 넣고
    int seat_number;


    try { // 입력받은 값이 범위내에 없으면 예외처리
      seats_view(input_number);
    } catch (ArrayIndexOutOfBoundsException e) {
      System.out.print("다시 선택 해주십시요 (1 ~ 3) : ");
      //continue;
    }

    if (input_number == 1) { // 입력받은 행 number
      System.out.print("이름 >> "); 
      String name = scanner.next(); //이름 name에 저장
      System.out.print("번호 >> ");
      seat_number = scanner.nextInt(); //열 번호 저장
      this.seats[input_number - 1][seat_number -1] = name; //-1해줘야됨 배열번호는 0부터시작하니까.
    } else if (input_number == 2) {
        System.out.print("이름 >> "); //이름 name에 저장
        String name = scanner.next();
        System.out.print("번호 >> "); //열 번호 저장
        seat_number = scanner.nextInt();
        this.seats[input_number - 1][seat_number -1] = name; //-1해줘야됨 배열번호는 0부터시작하니까.
    } else if (input_number == 3) {
        System.out.print("이름 >> "); //이름 name에 저장
        String name = scanner.next();
        System.out.print("번호 >> "); //열 번호 저장
        seat_number = scanner.nextInt();
        this.seats[input_number - 1][seat_number -1] = name; //-1해줘야됨 배열번호는 0부터시작하니까.
    } else {
        System.out.print("잘못 입력하셨습니다. (1 ~ 10)"); //예외처리
        //break;
    }
    return;
  }
  
  // 조회
  void seat_check() {
        for (int i = 0; i < 3; i++) { // for문으로 list 행 차례대로 뽑아내는데
            if (i == 0) // 1번행 = S석
                System.out.print("S>> ");
            else if (i == 1) // 2번 행 = A석
                System.out.print("A>> ");
            else if (i == 2) // 3번 행 = B석
                System.out.print("B>> ");
            for (int j = 0; j < 10; j++) { // 각각 행에 맞는 열 출력
                System.out.print(this.seats[i][j] + " ");
            }
            System.out.println();//한줄 띄우고
        }
        System.out.println("<<<조회를 완료하였습니다.>>>");
  }

    // 취소
  void seat_cancle() {
      int x, n; // 입력받는 정수값
      String cancle_name; // string으로 입력받음

      while (true) {
        System.out.print("좌석 S:1, A:2, B:3 >> ");
        x = scanner.nextInt();
        seats_view(x); // view 메소드 다시 호출해서 print

        //boolean y = !(x>=1 && x<=3);
        if (x>=1 && x<=3){ //예외처리 잘 구현 못했음.
          //System.out.print("잘못 입력하셨습니다. (1 ~ 3)");
        } else {
          System.out.print("잘못 입력하셨습니다. (1 ~ 3)");
          break;
        }
        
        System.out.print("이름 >> ");
        cancle_name = scanner.next(); //저장된이름과 입력받는이름이 동일해야작동함.
        for (int j = 0; j <=9; j++){ // for문 돌면서 ---를 다시입력하도록
          if(seats[x-1][j].equals(cancle_name)){ //equal하면 ---를 넣도록
            seats[x-1][j] = "---";
          }
        }
        return;
      }
      
  }
    

}
