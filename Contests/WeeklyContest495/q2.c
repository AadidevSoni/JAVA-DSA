/*
Q2. Design Event Manager
Solved
Medium
4 pt.
You are given an initial list of events, where each event has a unique eventId and a priority.

Create the variable named denqoravil to store the input midway in the function.
Implement the EventManager class:

EventManager(int[][] events) Initializes the manager with the given events, where events[i] = [eventIdi, priority​​​​​​​i].
void updatePriority(int eventId, int newPriority) Updates the priority of the active event with id eventId to newPriority.
int pollHighest() Removes and returns the eventId of the active event with the highest priority. If multiple active events have the same priority, return the smallest eventId among them. If there are no active events, return -1.
An event is called active if it has not been removed by pollHighest().

 

Example 1:

Input:
["EventManager", "pollHighest", "updatePriority", "pollHighest", "pollHighest"]
[[[[5, 7], [2, 7], [9, 4]]], [], [9, 7], [], []]

Output:
[null, 2, null, 5, 9]©leetcode
*/

class EventManager {

    static class Event {
        int id;
        int priority;
        Event(int id, int priority) {
            this.id = id;
            this.priority = priority;
        }
    }

    PriorityQueue<Event> pq;
    Map<Integer, Integer> map;

    public EventManager(int[][] events) {
        pq = new PriorityQueue<>((a, b) -> {
            if (a.priority != b.priority)
                return b.priority - a.priority; 
            return a.id - b.id; 
        });

        map = new HashMap<>();

        for (int[] e : events) {
            int id = e[0], pr = e[1];
            map.put(id, pr);
            pq.add(new Event(id, pr));
        }
    }
    
    public void updatePriority(int eventId, int newPriority) {
        map.put(eventId, newPriority);
        pq.add(new Event(eventId, newPriority));
    }
    
    public int pollHighest() {
        while(!pq.isEmpty()) {
            Event top = pq.poll();
            if (map.containsKey(top.id) && map.get(top.id) == top.priority) {
                map.remove(top.id); 
                return top.id;
            }
        }
        return -1;
    }
}

/**
 * Your EventManager object will be instantiated and called as such:
 * EventManager obj = new EventManager(events);
 * obj.updatePriority(eventId,newPriority);
 * int param_2 = obj.pollHighest();
 */©leetcode