import java.util.Vector; //Vector 라이브러리 가져오기
import java.util.Scanner; //Scanner 라이브러리 가져오기

	
class GraphicEditor{ //그래픽에디터 클래스 선언
	private Shape head; // Shape 객체 생성
  private Shape tail; // Shape 객체 생성
	private Scanner scanner; // Scanner 객체 생성
  
	Vector<Shape> v; // 벡터 Shape 객체 생성

	public GraphicEditor(){ // 기본 생성자
		v = new Vector<Shape>(); // v 초기화
		head = null; // head 초기화
		tail = null; // tail 초기화
		scanner = new Scanner(System.in);
	}
	
	//에디터 실행 메서드
	void runEditor() {
		int x;
		System.out.println("그래픽 에디터 beauty을 실행합니다.");
		
		do {
		System.out.print("삽입(1), 삭제(2), 모두 보기(3), 종료(4)>>");
		x = scanner.nextInt();
			switch(x) { // switch case 문으로 접근
			case 1: // 삽입 case
				System.out.print("Line(1), Rect(2), Circle(3)>>");
				int select = scanner.nextInt(); //scanner로 받은 정수를 select에 저장
				put(select); // 1은 선, 2는 사각형, 3은 원 으로 put 메서드 호출
				break; //switch에서 벗어남
			case 2: // 삭제 case
				System.out.print("삭제할 도형의 위치>>");
				int index=scanner.nextInt(); //scanner로 받은 int를 index에 저장
				delete(index); // index값을 적용한 delete 메소드 호출
				break; //switch 벗어남
			case 3: // 모두 보기 case
				print(); // print 메소드 호출
				break; // switch에서 벗어남
			case 4: // 종료 case
				break; // switch에서 벗어남
			default: // error code
				System.out.println("다시 입력해주세요"); // error message
				break; // switch에서 벗어남
			}
		}while(x!=4); // x가 4가 아닐때 ture가 되며 실행됨, x가 1~4일때는 위에서 먼저 필터링 된다.
		System.out.println("beauty을 종료합니다.");
	}
	
	void put(int num) { // 리스트에 넣는 메서드, 입력받은 정수를 num에 저장
		Shape g; // Shpae 객체 g 생성

		switch(num) {
		case 1: // Line 객체 생성 case
			g=new Line();
			break;
		case 2: // Rect 객체 생성 case
			g=new Rect();
			break;
		case 3: // Circle 객체 생성 case
			g=new Circle();
			break;
		default: // error code
			System.out.println("다시입력해주세요"); // error message
			return; // main문으로 돌아감
		}
		v.add(g); // 벡터객체에 g 더함.
		return; // main문으로 돌아감
	}

	void delete(int index) { // 리스트 삭제 메소드
		if(index>v.size()) { // error code, index가 벡터 객체의 size보다 크면 error
			System.out.println("삭제할 수 없습니다."); // error message
			return; // main문으로 돌아감
		}
		v.remove(index); // v 객체에 index에 해당하는 부분 삭제함.
	}
	
	void print() { // print 메소드 선언 
		for(int i=0;i<v.size();i++) { // for문으로 index print함.
			v.get(i).draw(); // v안에 index 순서대로 변수값 안에 draw 메소드를 호출한다.
		}
	}
}