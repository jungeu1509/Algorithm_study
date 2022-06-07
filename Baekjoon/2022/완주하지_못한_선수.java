import java.util.ArrayList;

class Solution {
    public String solution(String[] participant, String[] completion) {
        String answer = "";
        ArrayList<ArrayList<String>> arrPart = new ArrayList<>();
        ArrayList<ArrayList<String>> arrComp = new ArrayList<>();
        
        final int MAXNUM = 26;
        for(int i = 0; i < MAXNUM; i++) {
        	arrPart.add(new ArrayList<String>());
        	arrComp.add(new ArrayList<String>());
        }
        
        for(int i = 0; i < participant.length; i++) {
            char start = participant[i].charAt(0);
            arrPart.get(start - 'a').add(participant[i]);
        }
        
        for(int i = 0; i < completion.length; i++) {
            char start = completion[i].charAt(0);
            arrComp.get(start - 'a').add(completion[i]);
        }
        
        for(int count = 0; count < MAXNUM; count++) {
        	ArrayList<String> nowPart = arrPart.get(count);
        	ArrayList<String> nowComp = arrComp.get(count);
        	
        	boolean[] visitComp = new boolean[nowComp.size()];
        	
        	if(nowPart.size() != nowComp.size()) {
        		boolean flag;
        		for(int i = 0; i < nowPart.size(); i++) {
        			flag = false;
        			
        			for(int j = 0; j < nowComp.size(); j++) {
        				if(nowPart.get(i).equals(nowComp.get(j))) {
        					if(visitComp[j] == false) {
        						visitComp[j] = true;
        						flag = true;
        						break;
        					}
        				}
        			}
        			
        			if(flag == false) {
        				answer += nowPart.get(i);
        				return answer;
        			} // and for(j)
        		} // and for(i)
        	} // and if(nowPart.size() != nowComp.size())
        } // and for(count)
        
        return answer;
    }
}
