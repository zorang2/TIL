class Circle extends Shape{ // Shape를 상속하는 Circle 클래스 선언
	public Circle() {
		super();// Shape 클래스의 필드, 메소드 참조
	}
	//오버라이딩
	public void draw() {// 오버라이딩 작성한 draw 메소드
		System.out.println("Circle"); // Circle 출력
	}
}