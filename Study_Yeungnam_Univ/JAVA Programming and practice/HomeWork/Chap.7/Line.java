class Line extends Shape{ // Shape를 상속하는 Line 클래스 선언
	public Line() {
		super(); // Shape 클래스의 필드, 메소드 참조
	}
	//오버라이딩
	public void draw() { // 오버라이딩 작성한 draw 메소드
		System.out.println("Line"); // Line 출력
	}
}