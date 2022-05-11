/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode removeNthFromEnd(ListNode head, int n) {
        ListNode answer = head;

        // 총 개수 파악
        int size = 1;
        ListNode now = head.next;
        while(now != null) {
            size++;
            
            if(now.next == null) break;
            else now = now.next;
        }
        
        // N번째 부분 연결 끊기
        // 초기화
        ListNode before = null;
        now = head;
        for(int i = 1; i <= size; i++){
            // 다음 노드 탐색
            if(i != 1) {
                before = now;
                now = now.next;
            }

            // 해당 위치 연결 끊기
            if(i == size - n + 1) {
                if(i==1) answer = head.next;
                else before.next = now.next;
                
                break;
            }
        } // end for

        return answer;
    }
}
