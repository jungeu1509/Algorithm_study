import java.util.ArrayList;
import java.util.PriorityQueue;

class Solution {
    static class Road implements Comparable<Road>{
        private int cost; // 시간 비용
        private int num; // 연결된 마을 번호

        public Road(int cost, int num) {
            this.cost = cost;
            this.num = num;
        }

        public boolean checkCost(int cost) {
            if(this.cost == -1 || this.cost > cost) {
                this.cost = cost;
                return true;
            }
            return false;
        }

        @Override
        public int compareTo(Road o) {
            return Integer.compare(this.cost, o.cost);
        }
    }

    public int solution(int N, int[][] road, int K) {
        int answer = 0;
        final int START = 1;

        // 최단시간 저장 배열 선언 및 초기화
        Road[] shortRoad = new Road[N+1];
        shortRoad[START] = new Road(0, START);
        for(int i = START+1; i <= N; i++) {
            shortRoad[i] = new Road(-1,i);
        }

        // 이웃 정점 2차원 배열로 선언 및 초기화
        ArrayList<ArrayList<Road>> neighbor = new ArrayList<>();
        for(int i = 0; i <= N; i++) {
            neighbor.add(new ArrayList<>());
        }
        for(int i = 0; i < road.length; i++) {
            for(int j = 1; j <= N; j++) {
                if (road[i][0] == j) neighbor.get(j).add(new Road(road[i][2], road[i][1]));
                else if (road[i][1] == j) neighbor.get(j).add(new Road(road[i][2], road[i][0]));
            }
        }

        // 우선순위 큐 선언
        PriorityQueue<Road> pQueue = new PriorityQueue<>();

        // 시작점 push
        pQueue.add(new Road(0, START));

        while(!pQueue.isEmpty()) {
            Road now = pQueue.poll();
            if(shortRoad[now.num].cost != now.cost) continue;

            for(int i = 0; i < neighbor.get(now.num).size(); i++) {
                Road next = neighbor.get(now.num).get(i);

                // 이미 저장되어있는 최단거리확인 넣으려는 값이 더 클경우 continue
                if(!shortRoad[next.num].checkCost(shortRoad[now.num].cost + next.cost))continue;
                // 넣으려는 값이 작으면 queue에 push
                pQueue.add(new Road(shortRoad[next.num].cost, next.num));
            }
        }

        // 최단거리 배달가능거리 비교
        for(int i = 1; i <= N; i++) {
            if(shortRoad[i].cost <= K && shortRoad[i].cost >= 0) answer++;
        }

        return answer;
    }
}
