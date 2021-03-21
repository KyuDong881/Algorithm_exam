import java.util.Scanner;

public class Main_2839 {

	static int N;
	static int three, five, answer;

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		N = sc.nextInt();
		five = N / 5;
		int tmp;
		tmp = N % 5;

		while (true) {
			if (tmp % 3 == 0) {
				three = tmp / 3;
				break;
			}

			tmp += 5;
			five--;
			if (five < 0)
				break;
		}
		if (five < 0)
			answer = -1;
		else
			answer = five + three;
		
		sc.close();
		System.out.println(answer);

	}

}
