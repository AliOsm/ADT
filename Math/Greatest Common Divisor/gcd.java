import java.util.Scanner;

public class Main {
  
  public static int gcd(int a, int b) { // Change type if needed
    if(b == 0)
      return a;
    
    return gcd(b, a % b);
  }
    
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int a, b;
    
    a = sc.nextInt();
    b = sc.nextInt();
    System.out.println(gcd(a, b));
    
  }
}
