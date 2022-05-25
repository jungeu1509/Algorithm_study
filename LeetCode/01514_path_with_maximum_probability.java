import java.util.ArrayList;
import java.util.Arrays;
import java.util.PriorityQueue;

class Solution {
    class Road implements Comparable<Road>{
        int node;
        double cost;

        public Road(int node, double cost) {
            this.node = node;
            this.cost = cost;
        }

        @Override
        public int compareTo(Road o) {
            return Double.compare(o.cost, this.cost);
        }
    }

    public double maxProbability(int n, int[][] edges, double[] succProb, int start, int end) {
        double answer = 0;
        final double INF = 200000000; // n*succProb[i]*succProb.length -> 10000*1*20000

        // 이웃 노드 정리
        ArrayList<ArrayList<Road>> neighbor = new ArrayList<>();
        for(int i = 0; i <= n; i++) {
            neighbor.add(new ArrayList<>());
        }
        for(int i = 0; i < edges.length; i++) {
            neighbor.get(edges[i][0]).add(new Road(edges[i][1], succProb[i]));
            neighbor.get(edges[i][1]).add(new Road(edges[i][0], succProb[i]));
        }

        // 우선순위 큐 선언 및 초기화
        PriorityQueue<Road> pQueue= new PriorityQueue<>();
        pQueue.add(new Road(start, 0));
        
        // 최고 가능성 표 선언 및 초기화
        double[] map = new double[n+1];
        Arrays.fill(map, INF);
        map[start] = 0;

        // 다익스트라
        while (!pQueue.isEmpty()) {
            Road now = pQueue.poll();
            if(now.cost != map[now.node]) continue;

            ArrayList<Road> nextDoors = neighbor.get(now.node);
            for(int i = 0; i < nextDoors.size();i++) {
                Road next = nextDoors.get(i);
                if(next.cost == INF) continue;
                if(map[next.node] == INF || map[next.node] < map[now.node] * next.cost) {
                    if(map[now.node] == 0) map[next.node] = next.cost;
                    else map[next.node] = map[now.node] * next.cost;
                    pQueue.add(new Road(next.node, map[next.node]));
                }
            }
        }

        // 연결 여부 확인
        answer = (map[end] == INF)? 0: map[end];
        return answer;
    }
}
