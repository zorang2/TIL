import java.util.*;

public class LocationManager {
  private HashMap<String, Location> dept = new HashMap<String, Location>();
  private Scanner scanner = new Scanner(System.in);

  private void read() { // method를 내부에서만 사용하기위해 private로 만든거다.
    System.out.println("도시이름, 경도, 위도를 입력하세요");

    for (int i = 0; i < 4; i++) {
      System.out.print(">>");
      String inputText = scanner.nextLine();
      StringTokenizer st = new StringTokenizer(inputText, ",");
      String name = st.nextToken().trim();
      double longitude = Double.parseDouble(st.nextToken().trim());
      double latitude = Double.parseDouble(st.nextToken().trim());

      Location loc = new Location(name, longitude, latitude);
      dept.put(name, loc);

    }
  }

  private void printAll() {
    Set<String> keys = dept.keySet();
    var it = keys.iterator();
    System.out.println("-------------------------------");

    while (it.hasNext()) {
      String name = it.next();
      Location loc = dept.get(name);
      System.out.println(loc);
    }
    System.out.println("-------------------------------");
  }

  private void processQuery() {
    while (true) {
      System.out.print("도시 이름 >> ");
      String name = scanner.nextLine();
      if (name.equals("그만"))
        break;

      Location loc = dept.get(name);
      if (loc == null) {
        System.out.println(name + "은 없습니다.");
      } else {
        System.out.println(loc);
      }
    }
  }

  public void run() {
    read();
    printAll();
    processQuery();
  }

}
