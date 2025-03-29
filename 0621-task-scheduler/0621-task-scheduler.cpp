class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26,0);
      // step 1: find freq 
      for(char c: tasks) // 'A'-'A' 65-65 =0  --> 0 based indexing  
      freq[c-'A']++; //The expression c - 'A' is often used in programming to calculate the zero-based position of a character relative to 'A'. 
      //freq array loooking somthig like -> [3,3] 0 ->  A, 0-> B

      // step 2: Insert freq in a max heap
      priority_queue<int> pq;
      for(int f: freq)
      pq.push(f); // pq-> [3,3]
     

      // step 3: find max freq - at last index after sorting
      //This means if a task appears maxFreq times, 
      //there are maxFreq - 1 intervals between its occurrences that need to be managed.
      int maxFreq= pq.top()-1;  // 3-1 =2. 

      // step 4: find num of idle slots initially
      // pop the task with high freq because we are already allocating 
      // that task and in between those tasks we are bufferring with 
      // isle slots to maintain cool down time 
      int idleSlots = maxFreq*n; //idle slotes 3*collDOwntime //6 
       pq.pop();
       
      // step 5: fill idle slots with other tasks
      // pop the next largest task
      // subtract those many tasks from idle slots
      // continue till all tasks in queue has been alloted in idle slots
      while(!pq.empty()){
      auto p = pq.top(); // 3 ; 3
      pq.pop(); // pq now is 3 ; pq empty 
      idleSlots -= min(maxFreq, p); //  6-min(2,3) = 4 //idle slots = 4-2=2
    
      if(idleSlots<=0) 
      break;
      }
      
      // step 6: if there are any idle slots left even after filling all the tasks
      // return idleSlots + total tasks else return total tasks count
      return idleSlots > 0 ? idleSlots + tasks.size(): tasks.size();
  
        
    }
};