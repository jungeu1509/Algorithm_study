import java.util.ArrayList;
import java.util.Arrays;
import java.util.PriorityQueue;

class Solution {
    class Road implements Comparable<Road> {
        int cost;
        int node;

        public Road(int cost, int node) {
            this.cost = cost;
            this.node = node;
        }

        @Override
        public int compareTo(Road o) {
            return Integer.compare(o.cost, this.cost);
        }
    }

    public int solution(int n, int[][] edge) {
        int answer = 0;
        final int INF = 2000000;
        
        // 연결노드 정리
        ArrayList<ArrayList<Integer>> neighbor = new ArrayList<>();
        for(int i = 0; i <= n; i++) {
            neighbor.add(new ArrayList<>());
        }
        for(int i = 0; i < edge.length; i++) {
            neighbor.get(edge[i][0]).add(edge[i][1]);
            neighbor.get(edge[i][1]).add(edge[i][0]);
        }

        // 다익스트라를 위한 우선순위큐와 최단거리 표
        PriorityQueue<Road> pQueue = new PriorityQueue<>();
        int[] map = new int[n+1];

        // 변수 초기화
        pQueue.add(new Road(0, 1));
        Arrays.fill(map, INF);
        map[1] = 0;

        // 다익스트라 알고리즘
        while(!pQueue.isEmpty()) {
            Road now = pQueue.poll();
            if(now.cost != map[now.node]) continue;
            
            // 이웃 노드 확인
            ArrayList<Integer> nowNeighbor = neighbor.get(now.node);
            for(int i = 0 ; i < nowNeighbor.size(); i++) {
                Integer next = nowNeighbor.get(i);
                if(map[next] > 1 + now.cost) {
                    map[next] = 1 + now.cost;
                    pQueue.add(new Road(now.cost + 1, next));
                }
            }
        }

        // 최고값 찾기
        int max = 0;
        for(int i = 0 ; i < map.length; i++) {
            if(map[i] > max && map[i] != INF) max = map[i];
        }

        // 최고값 갯수 찾기
        for(int i = 0 ; i < map.length; i++) {
            if(map[i] == max) answer++;
        }

        return answer;
    }
}
