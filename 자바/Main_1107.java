import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main_1107 {

	static boolean[] broken;
	static int gojang,target;
	static int answer;
	static StringTokenizer st;
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		target = Integer.parseInt(br.readLine());
		gojang = Integer.parseInt(br.readLine());
		broken = new boolean[10];
		
		if(gojang>0) {
			st = new StringTokenizer(br.readLine());
			while(st.hasMoreTokens()) {
				broken[Integer.parseInt(st.nextToken())]=true;
			}
		}
		answer=Math.abs(target-100);
		for(int i=0;i<=1000000;i++) {
			String str = String.valueOf(i);
			int len = str.length();
			boolean flag = false;
			for(int j=0;j<len;j++) {
				if(broken[str.charAt(j)-'0']==true) {
					flag=true;
					break;
				}
			}
			
			if(flag==false) {
				int tmp = Math.abs(target-i) + len;
				answer = Math.min(tmp, answer);
			}
			
		}
		System.out.println(answer);
		
	}

}
