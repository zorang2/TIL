// 비교 연산자와 논리 연산자 사용하기

class Main {
  public static void main(String[] args) {
    //비교연산
    System.out.println('a' > 'b'); //false
    System.out.println(3 >= 2); //true
    System.out.println(-1 < 0); //true
    System.out.println(3.45 <= 2); // false
    System.out.println(3 == 2); // false
    System.out.println(3 != 2); // true
    System.out.println(!(3 !=2)); //false

    // 비교연산과 논리연산의 복합
    System.out.println((3>2) && (3>4)); //false
    System.out.println((3!=2) || (-1>0)); //true
    System.out.println((3!=2) ^ (-1>0)); //true
  }
}
