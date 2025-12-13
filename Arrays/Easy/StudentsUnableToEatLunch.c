class Solution {
    public int countStudents(int[] students, int[] sandwiches) {
        int[] count = new int[2];

        for(int stud: students) {
            count[stud]++;
        }

        for(int sand: sandwiches) {
            if(count[sand] == 0) {
                break;
            }
            count[sand]--;
        }

        return count[0] + count[1];
    }
}