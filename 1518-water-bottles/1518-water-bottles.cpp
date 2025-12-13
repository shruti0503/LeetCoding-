// class Solution {
// public:
//     int numWaterBottles(int numBottles, int numExchange) {
//         // 15 ->  15 -> 4 , 4 , 
//         // 3 drink , 3
//         // remiandewr and wuotiemnt ka khel h 
//         // 
//         int startNum=numBottles;
//         int accumulate=0;
//         int ans=0;
//         while(startNum>0){
//            int temp= startNum/numExchange; // toDrink 3 
//            ans=ans+temp;
//            int num =startNum%numExchange; // remained  //3
//            startNum= ans+num ; //6
        

//         }
//         return ans;
        
//     }
// };

class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int startNum = numBottles;
        int ans = startNum; // initially, you can drink all the bottles you have

        while (startNum >= numExchange) {
            int newBottles = startNum / numExchange; // number of new bottles obtained by exchange
            int remainingBottles = startNum % numExchange; // remaining bottles after exchange
            ans += newBottles; // add new bottles to total count
            startNum = newBottles + remainingBottles; // update startNum to include new bottles and remaining ones
        }

        return ans;
    }
};
