class Main{
  public static int sum(int n, int m) {
    return n + m;
  }

  //main() 메소드에서 실행 시작

  public static void main(String[] args) { // public static void로 선언
                                          // void >> main함수의 type, return값이 없다는 뜻.
                                          // main >> 이 프로그램이 여기서 시작한다는 함수이름.
                                          // String[] args로 실행 인자를 전달 받음.
    int i = 20;
    int s;
    char a;

    s = sum(i, 10); //sum() 메소드 호출
    a = '?';
    System.out.println(a); // 문자 '?'화면 출력
    System.out.println("Hello"); // "Hello" 문자열 화면 출력
    System.out.println(s); // 정수 s 값 화면 출력

  }
}
