import java.awt.*; // Java1.0에 포함된 AWT는 운영체제가 제공하는 네이티브 UI컴포넌트를 이용하는 자바 라이브러리.
import java.awt.event.*;
import javax.swing.*; // 자바의 JFC(Java Foundation Class)는 GUI 프로그래밍에 필요한 각종 킷을 모아놓은 것으로 현재는 GUI의 기능들을 구현할 수 있는 스윙, 2D, Drag&Drop 등을 지원.
import javax.swing.event.*;
import javax.swing.text.BadLocationException;
//아래 클래스에서 사용할 라이브러리 import


class Main extends JFrame{ // JFrame을 부모로 상속
  private JTextArea ta = new JTextArea(5,10); // JTextArea 객체생성
  private JSlider slider = new JSlider(0,100,0); // JSlider 객체생성

  public Main(){
    super("practice3"); // 창이름
    setDefaultCloseOperation(EXIT_ON_CLOSE); //(EXIT_ON_CLOSE)필드 값을 붙이면 윈도우창 종료 시 프로세스까지 깔끔하게 닫을 수 있다.
    Container c = getContentPane(); //  프로그램의 창의 역할, 한개 이상의 컨테이너위에 컴포넌트들이 올려질영역입니다. setLayout() : Container 클래스의 객체 메소드(경로  java.awt.Container)
    c.setLayout(new BorderLayout()); // setLayout() : Container 클래스의 객체 메소드(경로  java.awt.Container)
    c.add(new JScrollPane(ta), BorderLayout.CENTER);
    c.add(slider, BorderLayout.SOUTH);

    slider.setMajorTickSpacing(20); // 주요 눈금 간격 20
    slider.setMinorTickSpacing(5); // 보조 눈금 간격 5
    slider.setPaintLabels(true); // Label 쓰겠다.
    slider.setPaintTicks(true); // Tick 쓰겠다.
    slider.addChangeListener(new ChangeListener() {

        @Override
        public void stateChanged(ChangeEvent e) {
          JSlider s = (JSlider) e.getSource(); // ChangeEvent 소스얻겠다
          if(ta.getText().length() <= s.getValue()){
            s.setValue(ta.getText().length());
          }
          else{
            try{ // 예외처리
              ta.setText(ta.getText(0,s.getValue()));// 예외처리
            }// 예외처리
            catch (BadLocationException ex){// 예외처리
              ex.printStackTrace();// 예외처리
            }// 예외처리
          }
        }
    });

    ta.addKeyListener(new KeyAdapter(){
      @Override
      public void keyTyped(KeyEvent e){
          JTextArea t = (JTextArea) e.getSource();
          int size = t.getText().length();
          if (size >= 100){// 예외처리
            try{// 예외처리
              t.setText(t.getText(0,100));// 예외처리
            } // 예외처리
            catch (BadLocationException ex){// 예외처리
              ex.printStackTrace();// 예외처리
            }// 예외처리
          }// 예외처리
          slider.setValue(size);
      }
    });


    setSize(250,150); // 250, 150size정의
    setVisible(true); // Visible ture
  }

  public static void main(String[] args) { // main함수
    new Main(); // 공간생성
  }
}
