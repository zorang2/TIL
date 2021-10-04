//예제 2.3 : 타입 변환
class Main {
  public static void main(String[] args) {
    byte b = 127;
    int i = 100;

    System.out.println(b+i); // 127+100=227
    System.out.println(10/4); // 10/4=2
    System.out.println(10.0/4); // double이니까 10.0/4 = 2.5
    System.out.println((char)0x12340041); //강제타입변환결과 0x41이 되며, 문자 A의 코드임
    System.out.println((byte)(b+i)); //-29
    System.out.println((int)2.9+1.8); //3.8
    System.out.println((int)(2.9+1.8)); //4
    System.out.println((int)2.9 + (int)1.8); //3
  }
}

/*
package example2;



public class TypeConversion {



	public static void main(String[] args) {

	

		byte b = 127;

		int i = 100;

		

		System.out.println(b+i);	//b가 int 타입으로 자동변환되어 연산됨

		System.out.println(10/4);	//정수/정수 = 정수 의 결과

		System.out.println(10.0/4);	//실수/정수 = 실수 의 결과

		System.out.println((char)0x12340041);	//0x로 시작한 16진수 데이터에서 char형으로 캐스팅 되고있다. char형은 2바이트, 해당 데이터의 하위 2바이트 까지만 읽을수 있으므로 0041의 아스키 코드 값 65는 문자 A

		System.out.println((byte)(b+i));	//해당 데이터는 int형으로 저장되지만 byte로 캐스팅 되므로 손실되는 부분을 제외한 값 -29

		System.out.println((int)2.9+1.8);	//2.9가 int형으로 캐스팅 되어 2 + 1.8 = 3.8

		System.out.println((int)(2.9+1.8));	//2.9+1.8 이 먼저 계산되어 4.7이라는 데이터가 int형으로 캐스팅 되어 4

		System.out.println((int)2.9+(int)1.8);	// 위와 마찬가지로 2.9는 2로 1.8은 1로 int형으로 각각 캐스팅 되어 결과는 3





	}



}

*/
