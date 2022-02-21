import java.util.ArrayDeque;
import java.util.Queue;

public class Solution {
    static class Map {
        int x;
        int y;
        Map(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }

    public int[] solution(String[][] places) {
        int[] answer = new int[places.length];
        int index = 0;

        for(String[] arr : places) {

            Queue<Map> queue = new ArrayDeque<>();
            boolean flag = true;
            for(int i = 0; i < arr.length; i++) {
                for(int j = 0; j < arr[i].length(); j++) {
                    if(arr[i].charAt(j) == 'P') {
                        queue.add(new Map(j, i));
                    }
                }
            }

            while (!queue.isEmpty()) {
                Map poll = queue.poll();
                Map left = new Map(poll.x-1, poll.y);
                Map right = new Map(poll.x+1, poll.y);
                Map down = new Map(poll.x, poll.y+1);
                Map up = new Map(poll.x, poll.y-1);

                //오른쪽과 아래에 P 확인
                if(right.x < 5 && arr[right.y].charAt(right.x) == 'P') {
                    flag = false;
                    break;
                }
                if(down.y < 5 && arr[down.y].charAt(down.x) == 'P') {
                    flag = false;
                    break;
                }

                //좌우하 위치에 O 확인. O가 있을경우 주변에 P가 있는지 확인
                if(left.x >= 0 && arr[left.y].charAt(left.x) == 'O') {
                    // 하 확인
                    if(left.y+1 < 5 && arr[left.y+1].charAt(left.x) == 'P') {
                        flag = false;
                        break;
                    }
                }
                if(right.x < 5 && arr[right.y].charAt(right.x) == 'O') {
                    // 우, 하 확인
                    if(right.x+1 < 5 && arr[right.y].charAt(right.x+1) == 'P') {
                        flag = false;
                        break;
                    }
                    if(right.y+1 < 5 && arr[right.y+1].charAt(right.x) == 'P') {
                        flag = false;
                        break;
                    }
                }
                if(down.y < 5 && arr[down.y].charAt(down.x) == 'O') {
                    // 좌, 우, 하 확인
                    if(down.x-1 > 0 && arr[down.y].charAt(down.x-1) == 'P') {
                        flag = false;
                        break;
                    }
                    if(down.x+1 < 5 && arr[down.y].charAt(down.x+1) == 'P') {
                        flag = false;
                        break;
                    }
                    if(down.y+1 < 5 && arr[down.y+1].charAt(down.x) == 'P') {
                        flag = false;
                        break;
                    }
                }

            }

            // 실패하면 0 성공하면 1 삽입
            if(flag) {answer[index] = 1;}
            else {answer[index] = 0;}
            index++;
        }
        return answer;
    }

}
