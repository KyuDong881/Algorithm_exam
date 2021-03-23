import java.util.Scanner;

public class Main_jungol_1411 {

	static int arr[];
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n=sc.nextInt();
		arr = new int[n+1];
		System.out.println(dp(n));
	}

	private static int dp(int n) {
		arr[1]=1;
		arr[2]=3;
		
		for(int i=3;i<=n;i++) {
			arr[i]=(arr[i-1]+2*arr[i-2])%20100529;
		}
		
		return arr[n];
	}

}
