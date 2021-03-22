import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Comparator;
import java.util.StringTokenizer;



public class Main_1828 {

	static int N,answer;
	static StringTokenizer st;
	static Pair[] temp;
	
	static class Pair{
		Integer x;
		Integer y;
		public Pair(Integer x, Integer y) {
			this.x = x;
			this.y = y;
		}
		public Integer first() {
			return x;
		}
		public Integer second() {
			return y;
		}
	}
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		N=Integer.parseInt(br.readLine());
		temp = new Pair[N];
		for(int i=0;i<N;i++) {
			st = new StringTokenizer(br.readLine());
			int x,y;
			x = Integer.parseInt(st.nextToken());
			y = Integer.parseInt(st.nextToken());
			temp[i] = new Pair(x, y);
		}
		Arrays.sort(temp,new Comparator<Pair>() {

			@Override
			public int compare(Pair o1, Pair o2) {
				if(o1.y>o2.y) {
					return 1;
				}
				else if(o1.y==o2.y) {
					if(o1.x>o2.x) return 1;
					else return -1;
				}
				else return -1;
			}
		});
		
//		for(int i=0;i<N;i++) {
//			System.out.println(temp[i].x+" , "+temp[i].y);
//		}
		
		answer=1;
		int cur = temp[0].y;
		for(int i=1;i<N;i++) {
			if(cur<temp[i].x) {
				answer++;
				cur = temp[i].y;
			}
		}
		System.out.println(answer);
		
	}

}
