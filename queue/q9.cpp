// circular Tour / Gas Station 

    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int available = 0 ;
        int deficent = 0 ;
        int start = 0 ;


        for (int i = start ; i < gas.size(); i++){
            available += gas[i]- cost[i];

            if(available < 0){
                deficent += available;
                start = i+1;
                available = 0;
            }
        }   

        if(deficent + available >=0){
            return start;
        }
        return -1;
    }
};