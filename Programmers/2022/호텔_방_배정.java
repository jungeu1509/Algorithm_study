import java.util.HashMap;

class Solution {
    // 방 목록을 체크하기위한 HashMap <배정받은 방, 다음 방>
    static HashMap<Long, Long> roomChecker = new HashMap<>();

    public long[] solution(long k, long[] room_number) {
        long[] answer = new long[room_number.length];

        for(int i = 0; i < room_number.length; i++) {
            answer[i] = roomAssignments(room_number[i]);
        }

        return answer;
    }

    private long roomAssignments(long hope) {
        long answer;

        // 방이 차있는지 확인
        if(!roomChecker.containsKey(hope)) { // 방이 비어있다면
            roomChecker.put(hope, hope+1); // 원하는 방을 주고 다음 방으로 가라고 가리킨다.
            answer = hope;
        } else { // 방이 이미 배정되어 있다면
            answer = roomAssignments(roomChecker.get(hope)); // 재귀를 이용해 비어있는 다음방으로 배정한다.
            roomChecker.put(hope, answer+1); // 배정받은 방의 다음방을 가리키도록 한다.
        }

        return answer;
    }
}
