class Solution {
    public int maxEvents(int[][] events) {
        Arrays.sort(events, (a, b) -> a[0] - b[0]);
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        int i=0;
        int n=events.length;
        int count = 0;
        int maxDay=0;
        for(int[] e :events){
            maxDay=Math.max(maxDay,e[1]);
        }
        for (int day=1;day<=maxDay;day++){
            while (i < n && events[i][0] <= day) {
                pq.offer(events[i][1]);
                i++;
            }
            while (!pq.isEmpty() && pq.peek() < day) {
                pq.poll();
            }
            if (!pq.isEmpty()) {
                pq.poll();
                count++;
            }
        }
        return count;
    }
}