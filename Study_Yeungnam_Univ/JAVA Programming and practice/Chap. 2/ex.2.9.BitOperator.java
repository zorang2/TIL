// 비트 논리 연산과 비트 시프트 연산
// 시험에 안나올듯... 16진수를 이해하기가 어려움..ㅠ
// 16진수 변환하는법 >> https://ko.wikihow.com/16%EC%A7%84%EC%88%98%EB%A5%BC-2%EC%A7%84%EC%88%98%EC%99%80-10%EC%A7%84%EC%88%98%EB%A1%9C-%EB%B3%80%ED%99%98%ED%95%98%EB%8A%94-%EB%B2%95
class Main {
  public static void main(String[] args) {
    short a = (short)0x55ff;
    short b = (short)0x00ff;

    //비트 논리 연산
    System.out.println("[비트연산결과]");
    System.out.printf("%04x\n", (short)(a & b)); //비트 AND //printf("%04",...)는 4자리의 16진수로 출력하고 빈 곳에는 0을 삽입한다.

    /*
    print : 괄호안 내용을 단순히 출력. 개행문자(=줄바꿈문자=\n) 포함안됨.
    printf : C에서의 printf와 동일. %d, %s 등을 쓰기위해 사용. 개행문자 포함X >> 그래서 이 예제에서 "%04x\n"에 \n이 있는거다.
    println : 괄호안 내용을 출력한 후 마지막에 개행문자가 포함되어 있어 출력후 한 줄 띄워짐.
    */

    System.out.printf("%04x\n", (short)(a | b)); //비트 OR
    System.out.printf("%04x\n", (short)(a ^ b)); //비트 XOR
    System.out.printf("%04x\n", (short)(~a)); //비트 NOT

    byte c = 20; //0x14
    byte d = -8; //0xf8

    //비트 시프트 연산
    System.out.println("[시프트 연산 결과");
    System.out.println(c <<2); //c를 2비트 왼쪽 시프트
    System.out.println(c >>2); //c를 2비트 오른쪽 시프트
    System.out.println(d >>2); //d를 2비트 오른쪽 시프트
    System.out.printf("%04x\n", (d >>>2)); // d를 2비트 오른쪽 시프트. 0삽입
    
    
  }
}
