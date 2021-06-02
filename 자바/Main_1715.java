import java.util.*;
import java.io.*;

public class Main_1715 {

	private static int N,answer;
	private static int[] arr;
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		N=Integer.parseInt(br.readLine());
		arr = new int[N];
		for(int i=0;i<N;i++) arr[i] = Integer.parseInt(br.readLine());
		
		PriorityQueue<Integer> pq = new PriorityQueue<>();
		for(int val : arr) pq.add(val);
		
		while(pq.size()>1) {
			int sum = pq.poll()+pq.poll();
			pq.add(sum);
			answer+=sum;
		}
		System.out.println(answer);
	}
}