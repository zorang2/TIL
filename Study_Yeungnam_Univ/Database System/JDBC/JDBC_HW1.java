/*
1. DB 연결은 ("jdbc:oracle:thin:@//localhost:1521/xepdb1", "scott", "tiger") 로 고정. 

2. 학과 번호를 입력받아 그 학과에 재학중인 학생의 성적을 0.01 더하라.

3. (학과번호, 학번)의 오름차순으로 모든 학생의 학과번호, 학번, 이름, 성적을 출력하라.

*/

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.Scanner;

public class JDBCTest {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		String sql = null;
		String sql2 = null;
		
		//오라클 드라이버 로딩할때는 try문으로 묶어줘야된다.
		try {
			Class.forName("oracle.jdbc.driver.OracleDriver");
		} catch (ClassNotFoundException e) {
			System.err.println("ClassNotFoundException : " + e.getMessage());
		}
		
		// 대부분 JDBC 명령문은 try문으로 묶어줘야합니다.
		try {
			
			Connection conn = DriverManager.getConnection("jdbc:oracle:thin:@//localhost:1521/xepdb1", "scott", "tiger");
			
			
			
			System.out.print("해당 학과 재학생들의 성적을 0.01만큼 더할 학과번호를 입력하세요. : ");
			int input_deptno = scanner.nextInt();
			
			sql = "Update student Set grade = grade + ? Where deptno = ?";
			PreparedStatement query = conn.prepareStatement(sql);
			float x = (float) 0.01;
			query.setFloat(1, x);
			query.setInt(2, input_deptno);
			query.executeUpdate();
			System.out.println("\n업데이트 성공");
			
			
			
			sql2 = "select deptno, sname, grade from student where deptno = ?";
			PreparedStatement query2 = conn.prepareStatement(sql2);
			query2.setInt(1, input_deptno);
			ResultSet rset = query2.executeQuery();
			System.out.println("해당 학과 재학생들의 성적을 0.1만큼 더했습니다.\n\n");
			while (rset.next()) {
				System.out.println("학과번호 : " + rset.getInt("deptno") + ", 이름 : " + rset.getString("sname") + ", 기존 성적에서 0.01더한 성적 : " + rset.getFloat("grade"));
			}
		} catch (SQLException sqle) {
			System.err.println("SQLException : " + sqle);
		}
		scanner.close();
		
		try {
			Connection conn = DriverManager.getConnection("jdbc:oracle:thin:@//localhost:1521/xepdb1", "scott", "tiger");
			Statement stmt = conn.createStatement();
			System.out.print("\n\n학과번호, 학번의 오름차순으로 모든 학생의 학과번호, 학번, 이름, 성적을 출력\n\n\n");
			ResultSet rset = stmt.executeQuery("select deptno, sid, sname, grade from student order by deptno, sid");
			while (rset.next()) {
				System.out.println("학과번호 : " + rset.getInt("deptno") + ", " + "학번 : " + rset.getInt("sid") + ", 이름 : " + rset.getString("sname") + ", 성적 : " + rset.getFloat("grade"));
			}
		} catch (SQLException sqle) {
			System.err.println("SQLException : " + sqle);
		}
		
	}
}
