import java.util.Scanner;

public class Main_14606 {

	static int N;
	static int answer;
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		N=sc.nextInt();
		
		dp(N);
		System.out.println(answer);
	}

	private static void dp(int n) {
		
		if(n==1) return;
		
		answer += (n/2)*(n-(n/2));
		dp(n/2);
		dp(n-(n/2));
	}

}
