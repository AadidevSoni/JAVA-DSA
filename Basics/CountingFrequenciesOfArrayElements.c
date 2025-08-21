import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class CountingFrequenciesOfArrayElements {

	public static void main(String[] args) {
		
		int nums[] = {5,5,5,5};
		List<List<Integer>> res = countFrequencies(nums);
		for(List<Integer> i: res) {
			System.out.println(i);
		}
		
	}
	
	public static List<List<Integer>> countFrequencies(int[] nums) {
    List<List<Integer>> res = new ArrayList<>();

    HashMap<Integer, Integer> freq = new HashMap<>();
    for(int i: nums) {
      freq.put(i, freq.getOrDefault(i,0) + 1);
    }
        
    for(Map.Entry<Integer, Integer> entry: freq.entrySet()) {
      List<Integer> temp = new ArrayList<>();
      temp.add(entry.getKey());
      temp.add(entry.getValue());
      res.add(temp);
    }
    return res;
  }
}
