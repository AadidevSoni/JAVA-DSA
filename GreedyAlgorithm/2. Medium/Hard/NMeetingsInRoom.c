package Arrays;

import java.util.*;

class meeting {
	int start;
	int end;
	int pos;
	
	meeting(int start, int end, int pos) {
		this.start = start;
		this.end = end;
		this.pos = pos;
	}
}

class meetingComparator implements Comparator<meeting> {
	
	public int compare(meeting m1, meeting m2) {
		if(m1.end < m2.end) return -1;
		else if(m1.end > m2.end) return 1;
		else if(m1.pos < m2.pos) return -1;
		return 1;
	}
}

public class Practice {
	
	public static void main(String[] args) {
		
		int[] start = {0,3,1,5,5,8};
		int[] end = {5,4,2,9,7,9};
		int n = 6;
		
		maxMeetings(start,end,n);
		
	}
	
	public static void maxMeetings(int[] start, int[] end, int n) {
		
		ArrayList<meeting> meet = new ArrayList<>();
		
		for(int i=0;i<n;i++) {
			meet.add(new meeting(start[i],end[i],i));
		}
		
		meetingComparator mc = new meetingComparator();
		
		Collections.sort(meet,mc);
		
		ArrayList<Integer> answer = new ArrayList<>();
		
		answer.add(meet.get(0).pos);
		int limit = meet.get(0).end;
		
		for(int i=1;i<n;i++) {
			if(meet.get(i).start > limit) {
				answer.add(meet.get(i).pos);
				limit = meet.get(i).end;
			}
		} 
		
		System.out.println("Number of meetings: " + answer.size());
		System.out.println("Order of meetings: ");
		
		for(int i=0;i<answer.size();i++) {
			System.out.print(answer.get(i) + " , ");
		}
		
		System.out.println();
	}
  
}

