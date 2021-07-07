import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Main_2467 {

	static ArrayList<Integer> info;
	static int N,liquid1,liquid2;
	static long answer;
	static StringTokenizer st;
	
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		N=Integer.parseInt(br.readLine());
		st = new StringTokenizer(br.readLine());
		info = new ArrayList<>();
		for(int i=0;i<N;i++) {
			info.add(Integer.parseInt(st.nextToken()));
		}
		answer = Integer.MAX_VALUE;
		twopointer();
		System.out.println(liquid1+" "+liquid2);
		
	}

	private static void twopointer() {
		int start = 0;
		int end = info.size()-1;
		
		while(start<end) {
			long cvalue = info.get(start)+info.get(end);
			long abscvalue = Math.abs(cvalue);
			
			if(answer>abscvalue) {
				answer = abscvalue;
				liquid1 = info.get(start);
				liquid2 = info.get(end);
				if(answer==0) return;
			}
			
			if(cvalue<0) start++;
			else end--;
		}
		
	}

}
